/*
 * @author Alexis Aspauza
 * @version 1.0
 * @data May/6/2021
 * Decription: Este projecto es realizado como parte del examen técnico
 * 		de la empresa Aranda Software.
 *		A pesar que el examen es en español, colocaré los comentarios
 *		de mis códigos en inglés debido a ser esta la mejor práctica.
*/

// Header policy
#ifndef BST_H
#define BST_H

#include <iostream>
#include <vector>
using namespace std;

/** Defition of our Binary Search Tree class */
template <class T>
class BST{
	private:
		// PRIVATE ATTRIBUTES
		/** Defining our class Node */
		class Node{
		public:
			// node attributes
			T data;
			Node *left;
			Node *right;
			// node constructor
			Node(T dt){
				data = dt; 
				left = nullptr; 
				right = nullptr; 
			}
		};
		Node *root;

		// PRIVATE METHODS
		/** given a subtree parent and data, insert it in the subtree */
		Node* insert(Node *parent, const T& data){
			// base case, the node is inserted as leaf here
			if(parent == nullptr) return new Node(data);
			// if data is lower than parent, insert it into left branch
			if(data < parent->data) parent->left = insert(parent->left, data);
			// if data is greater than parent, insert it into right branch
			if(data > parent->data) parent->right = insert(parent->right, data);
			// return the current parent node
			return parent;
		}


		/** search a node in a subtree */
		bool search(Node *parent, const T& data){
			// base case, the node does not exist in the tree
			if(parent == nullptr) return false;
			// if data is lower than parent, search in left branch
			if(data < parent->data) return search(parent->left, data);
			// if data is greater than parent, search in right branch
			if(data > parent->data) return search(parent->right, data);
			// the node is found
			return true;
		}

		/** delete the whole tree recursively */
		void recDelete(Node *parent){
			// case base: node to be deleted is null
			if(parent == nullptr) return;
			// recursively delete left and right branches
			recDelete(parent->left);
			recDelete(parent->right);
			// delete the current node
			delete(parent);
		}

		/** Get the common ancestor of two nodes */
		T commonAncestor(Node *parent, const T& n1, const T& n2){
			if(parent == nullptr)
				throw "ERROR: Common Ancestor can't be found since both elements are not in the tree.\n";
			// if both nodes are lower than parent, this is not the first common parent
			if(n1 < parent->data and n2 < parent->data)
				return commonAncestor(parent->left, n1, n2);
			// if both nodes are greater than parent, this is not the first common parent
			else if(n1 > parent->data and n2 > parent->data)
				return commonAncestor(parent->right, n1, n2);
			// if nodes are in different sub branches
			// if one of the elements does not exist in the tree, throws an error
			if(!search(parent, n1) or !search(parent, n2))
				throw "ERROR: Common Ancestor can't be found since both elements are not in the tree.\n";
			// return the common ancestor
			return parent->data;
		}

		/** Traverse the tree in-order and return a vector of items ordered */
		void inOrder(vector<T>& traversal, Node *parent){
			if(parent == nullptr) return;
			inOrder(traversal, parent->left);
			traversal.push_back(parent->data);
			inOrder(traversal, parent->right);
		}

		/** Traverse the tree pre-order and return the traversal */
		void preOrder(vector<T>& traversal, Node *parent){
			if(parent == nullptr) return;
			traversal.push_back(parent->data);
			preOrder(traversal, parent->left);
			preOrder(traversal, parent->right);
		}

		/** Traverse the tree post-order and return the traversal */
		void postOrder(vector<T>& traversal, Node *parent){
			if(parent == nullptr) return;
			postOrder(traversal, parent->left);
			postOrder(traversal, parent->right);
			traversal.push_back(parent->data);
		}

	public:
		// PUBLIC METHODS
		/** Constructor */
		BST(){ root = nullptr; }

		/** Destructor */
		~BST(){ recDelete(root); }

		/** Insertion */
		void insert(const T& data){
			root = insert(root, data);	
		}

		/** Search */
		bool search(const T& data){
			return search(root, data);	
		}

		/** Get the common ancestor of two nodes */
		T commonAncestor(const T& n1, const T& n2){
			return commonAncestor(root, n1, n2);
		}

		/** Return the in order items */
		vector<T> inOrder(){
			vector<T> items;
			inOrder(items, root);
			return items;
		}

		/** Return the pre order items */
		vector<T> preOrder(){
			vector<T> items;
			preOrder(items, root);
			return items;
		}

		/** Return the post order items */
		vector<T> postOrder(){
			vector<T> items;
			postOrder(items, root);
			return items;
		}
};

#endif // BST_H