/*
 * Parser.h
 *
 *  Created on: 4/09/2014
 *      Author: remnanjona
 */

#ifndef PARSER_H_
#define PARSER_H_

#include <memory>
#include <string>
#include <vector>

#include "Graph.h"

namespace std {

class Parser {
public:
	Parser();
	virtual ~Parser();

	vector<string> readTokens(string);
	shared_ptr<Graph> readGraph(string);

};

} /* namespace std */

#endif /* PARSER_H_ */
