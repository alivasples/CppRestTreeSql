#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <vector>
#include <sstream>
#include <regex>
using namespace std;

/** This namespace includes some util and basic functions */
namespace Utils{
	/** split a string as a vector of integers */
	vector<int> splitInts(string s);

	/** concatenate a ints vector into a single string */
	string joinInts(vector<int> numbers, string sep  = ",");
};


#endif //UTILS_H