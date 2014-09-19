/*
 * Lex.h
 *
 *  Created on: 20/09/2014
 *      Author: remnanjona
 */

#ifndef LEX_H_
#define LEX_H_

#include <fstream>
#include <queue>
#include <string>

namespace std {

class Lex {
public:
	Lex(string);
	virtual ~Lex();

	queue<string> getTokens();

private:
	ifstream ifs;

};

vector<string> split(const string &s, char delim);

} /* namespace std */

#endif /* LEX_H_ */
