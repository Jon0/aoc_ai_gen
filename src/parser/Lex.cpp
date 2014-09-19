/*
 * Lex.cpp
 *
 *  Created on: 20/09/2014
 *      Author: remnanjona
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

#include "Lex.h"

namespace std {

Lex::Lex(string fname): ifs(fname, ifstream::in) {
	if (!ifs) {
		throw runtime_error(fname + " not found");
	}
}

Lex::~Lex() {}

queue<string> Lex::getTokens() {
	// get list of tokens
	queue<string> tokens;
    for (string line; getline(ifs, line); ) {
    	vector<string> line_split = split(line, ' ');
    	for (string &s: line_split) tokens.push(s);
    }
    return tokens;
}

vector<string> split(const string &s, char delim) {
    vector<string> tokens;
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
    	item.erase(remove(item.begin(), item.end(), ' '), item.end());
    	if (!item.empty()) tokens.push_back(item);
    }
    return tokens;
}

} /* namespace std */
