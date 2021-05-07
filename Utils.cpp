#include "Utils.h"

/** split a string as a vector of integers */
vector<int> Utils::splitInts(string s){
	// validating input is correct
	if(!regex_match(s, regex("(\\+|-)?[[:digit:]]+,(\\+|-)?[[:digit:]]+"))){
		throw 400;
	}
	// definition of our ints vector
	vector<int> ints;
	// using sstream library to split the string
	istringstream is(s);
	// pusing all items into our vector
	int n;
	char sep;
    while( is >> n ) {
        ints.push_back(n);
        is >> sep;
	}
	// returning our vector
	return ints;
}

/** concatenate a ints vector into a single string */
string Utils::joinInts(vector<int> numbers, string sep){
	string joined = "";
	for(int i = 0; i < numbers.size(); i++){
		if(i > 0) joined += sep;
		joined += to_string(numbers[i]);
	}
	return joined;
}