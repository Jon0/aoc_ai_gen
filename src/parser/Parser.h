/*
 * Parser.h
 *
 *  Created on: 4/09/2014
 *      Author: remnanjona
 */

#ifndef PARSER_H_
#define PARSER_H_

#include <memory>
#include <queue>
#include <string>
#include <vector>

#include "../Graph.h"

namespace std {

class Parser {
public:
	Parser(string);
	virtual ~Parser();

	shared_ptr<Graph> readGraph();

private:
	string filename;
	queue<string> tokens;

	Node readNode();
	Flow readFlow();
	Action readAction();


	void match(string);
	string pop();
	double popf();

};

} /* namespace std */

#endif /* PARSER_H_ */
