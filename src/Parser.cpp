/*
 * Parser.cpp
 *
 *  Created on: 4/09/2014
 *      Author: remnanjona
 */

#include <algorithm>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <sstream>

#include "Parser.h"

namespace std {

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

Parser::Parser() {}

Parser::~Parser() {}

vector<string> Parser::readTokens(string fname) {
	ifstream ifs(fname, ifstream::in);
	if (!ifs) {
		throw runtime_error(fname + " not found");
	}

	// get list of tokens
    vector<string> tokens;
    for (string line; getline(ifs, line); ) {
    	vector<string> line_split = split(line, ' ');
    	tokens.insert(tokens.end(), line_split.begin(), line_split.end());
    }
    return tokens;
}

shared_ptr<Graph> Parser::readGraph(string fname) {
	vector<string> tokens = readTokens(fname);
	shared_ptr<Graph> g = make_shared<Graph>();

	for (int i = 0; i < tokens.size(); ++i) {
		if (tokens[i] == "node") {
			Node n;
			n.label = tokens[++i];
			n.value = atof(tokens[++i].c_str());
			g->add(n);
		}
		else if (tokens[i] == "flow") {
			Flow f;
			f.from = tokens[++i];
			f.to = tokens[++i];
			f.rate = atof(tokens[++i].c_str());
			f.cost = atof(tokens[++i].c_str());
			if (f.cost > 0) f.control = true;
			g->add(f);
		}
		else if (tokens[i] == "action") {
			Action a;

			string next = tokens[++i];
			while (next != "time") {
				if (!a.effect.empty()) a.effect += " ";
				a.effect += next;
				next = tokens[++i];
			}
			a.time = atof(tokens[++i].c_str());
			i++;

			next = tokens[++i];
			while (next != "value") {
				double amount = atof(tokens[++i].c_str());
				a.cost.push_back(Quantity{next, amount});
				next = tokens[++i];
			}
			g->add(a);
		}
	}
	return g;
}

} /* namespace std */
