/*
 * @author Alexis Aspauza
 * @version 1.0
 * @data May/6/2021
 * Decription: Este projecto es realizado como parte del examen técnico
 * 		de la empresa Aranda Software.
 *		A pesar que el examen es en español, colocaré los comentarios
 *		de mis códigos en inglés debido a ser esta la mejor práctica.
 *
 * NOTA: Estamos usando pistache como REST API, para instalar ver la 
 * 		documentación oficial: http://pistache.io/docs/ 
*/

#include <pistache/endpoint.h>
#include <pistache/router.h>
#include <pistache/http.h>
#include "Utils.h"
#include "BST.h"
#include "Tester.h"
#include "SQLiteAPI.h"

using namespace std;
using namespace Pistache;

class TreeEndpoint {
public:
	// PUBLIC METHODS
	/** Constructor */
    TreeEndpoint(Address addr)
        : http(std::make_shared<Http::Endpoint>(addr))
    { }

    /** initialize the end point */
    void init(size_t thr = 2) {
        auto opts = Http::Endpoint::options().threads(thr);
        http->init(opts);
        setupRoutes();
    }

    /** start serving */
    void start() {
        http->setHandler(router.handler());
        http->serve();
    }

    /** shutdown the server */
    void shutdown() {
        http->shutdown();
    }

private:
	// PRIVATE ATTRIBUTES
	shared_ptr<Http::Endpoint> http;
    Rest::Router router;
    SQLiteAPI sqlAPI;
    BST<int> *tree = new BST<int>;

	/** Define all the serving routes */
    void setupRoutes() {
        Rest::Routes::Get(router, "/seeTree", Rest::Routes::bind(&TreeEndpoint::seeTree, this));
        Rest::Routes::Post(router, "/newTree", Rest::Routes::bind(&TreeEndpoint::newTree, this));
        Rest::Routes::Post(router, "/addItem/:item", Rest::Routes::bind(&TreeEndpoint::addItem, this));
        Rest::Routes::Get(router, "/commonAncestor/:items", Rest::Routes::bind(&TreeEndpoint::commonAncestor, this));
    }

    /** Show the traversals of the tree to the client */
    void seeTree(const Rest::Request& request, Http::ResponseWriter response) {
    	// making traversals
    	string inOrder = Utils::joinInts(tree->inOrder());
    	string preOrder = Utils::joinInts(tree->preOrder());
    	string postOrder = Utils::joinInts(tree->postOrder());
    	string msg = "IN-ORDER: {" + inOrder + "}\nPRE-ORDER: {" + preOrder + "}\nPOST-ORDER: {" + postOrder + "}\n";
    	// sending the response
        response.send(Http::Code::Ok, msg);
    }

    /** Create an empty tree but first save the previous one if not empty */
    void newTree(const Rest::Request& request, Http::ResponseWriter response) {
    	// making traversals
    	string inOrder = Utils::joinInts(tree->inOrder());
    	string preOrder = Utils::joinInts(tree->preOrder());
    	string postOrder = Utils::joinInts(tree->postOrder());
    	// saving last state into the database
    	sqlAPI.insertInTree(inOrder, preOrder, postOrder);
    	// freing the tree and creating an empty one
    	tree = new BST<int>();
        response.send(Http::Code::Ok, "An empty tree was created successfully.\n"
        	"Previous tree was saved in the database.\n");
    }

    /** Add an item to the current tree */
    void addItem(const Rest::Request& request, Http::ResponseWriter response) {
    	// getting the parameter
    	auto item = request.param(":item").as<std::string>();
    	// inserting the parameter into our current tree
    	int item_int = stoi(item);
    	tree->insert(item_int);
    	// response ok
        response.send(Http::Code::Ok, "Item " + item + " was added\n");
    }

    /** get the common ancestor of two items comma separated */
    void commonAncestor(const Rest::Request& request, Http::ResponseWriter response) {
    	// getting the numbers in as a single string
    	auto items = request.param(":items").as<std::string>();
    	// spliting the two numbers
    	try{
    		vector<int> numbers = Utils::splitInts(items);
    		cout << numbers[0] << " and " << numbers[1] << endl;
    		int ancestor = tree->commonAncestor(numbers[0], numbers[1]);
	    	// seding the response
	        response.send(Http::Code::Ok, "common ancestor of: " + items + ": " + to_string(ancestor) + "\n");
    	} catch(int error){
	    	// seding the response
	        response.send(Http::Code::Ok, "Wrong format of input. Numbers must be comma separated: a,b\n");
    	} catch(const char* errorStr){
    		// seding the response
	        response.send(Http::Code::Ok, string(errorStr));
    	}

    }

};


/** main function */
int main(int argc, char *argv[]) {
	// Making unit test
	string message;
    bool passed = Tester::testAll(message);
    cout << message << endl;
	if(passed){
		// Just creating our endpoints and running the server
	    TreeEndpoint treeServer(Address(Ipv4::any(), Port(9080)));
	    treeServer.init();
	    cout << "Listening..." << endl;
	    treeServer.start();
	    treeServer.shutdown();
	}
}
