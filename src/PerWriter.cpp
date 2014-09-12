/*
 * PerWriter.cpp
 *
 *  Created on: 5/09/2014
 *      Author: remnanjona
 */

#include <fstream>
#include <iostream>

#include "PerWriter.h"

namespace std {

PerWriter::PerWriter() {}

PerWriter::~PerWriter() {}

void PerWriter::writeRule(ofstream &ofs, vector<Condition> c, vector<Action> a) {
	ofs << "(defrule" << endl;
	ofs << "\t(true)" << endl;
	ofs << "=>" << endl;
	for (Action &act: a) {
		ofs << "\t(" << act.effect << ")" << endl;
	}
	ofs << ")" << endl;
}

void PerWriter::write(string fname, shared_ptr<Graph> g) {
	ofstream ofs(fname);

	vector<Condition> cds;
	writeRule(ofs, cds, g->actions());

}

} /* namespace std */
