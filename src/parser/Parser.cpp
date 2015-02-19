/*
 * Parser.cpp
 *
 *  Created on: 4/09/2014
 *      Author: remnanjona
 */

#include <iostream>

#include "Lex.h"
#include "Parser.h"

namespace std {

Parser::Parser(string fname) {
	filename = fname;
}

Parser::~Parser() {}

shared_ptr<graph::Graph> Parser::readGraph() {
	Lex infile(filename);
	tokens = infile.getTokens();
	//shared_ptr<graph::Graph> g = make_shared<graph::Graph>();
	while (!tokens.empty()) {
		string &next = tokens.front();
		if ( next == "node" ) {
			//g->add( readNode() );
		}
		else if ( next == "flow" ) {
			//g->add( readFlow() );
		}
		else if ( next == "action" ) {
			//g->add( readAction() );
		}
		else {
			throw runtime_error("unrecognized token " + next);
		}
	}
	//return g;
}

graph::Node Parser::readNode() {
	match("node");
	graph::Node n;
	n.label = pop();
	return n;
}

graph::Flow Parser::readFlow() {
	match("flow");
	graph::Flow f;
	//f.from = pop();
	//f.to = pop();
	//f.rate = popf();
	return f;
}

Action Parser::readAction() {
	match("action");
	Action a;

	string next = pop();
	while (next != "time") {
		if (!a.effect.empty()) a.effect += " ";
		a.effect += next;
		next = pop();
	}
	a.time = popf();

	match("cost");
	next = tokens.front();
	while (next != "value") {
		pop();
		double amount = popf();
		a.cost.push_back(Quantity{next, amount});
		next = tokens.front();
	}

	match("value");
	next = tokens.front();
	while (next != "end") {
		pop();
		double amount = popf();
		a.value.push_back(Quantity{next, amount});
		next = tokens.front();
	}
	pop();

	return a;
}

void Parser::match(string s) {
	string &top = tokens.front();
	if (s == top) {
		tokens.pop();
		return;
	}
	throw runtime_error("expected " + s + " but found " + top);
}

string Parser::pop() {
	string top = tokens.front();
	tokens.pop();
	return top;
}

double Parser::popf() {
	return atof(pop().c_str());
}



} /* namespace std */
