/*
 * PerWriter.cpp
 *
 *  Created on: 5/09/2014
 *      Author: remnanjona
 */

#include <fstream>
#include <iostream>

#include "parser/Parser.h"
#include "PerWriter.h"

namespace std {

void readSpecFile(const char *f) {
	Parser p(f);
	shared_ptr<graph::Graph> g = p.readGraph();
	cout << to_string(*g.get()) << std::endl;

	PerWriter w;
	w.write("test.per", g);
}

PerWriter::PerWriter() {}

PerWriter::~PerWriter() {}

void PerWriter::writeRule(ofstream &ofs, map<graph::Node *, double> &vals, Action &a) {
	vector<Condition> cds;

	//a->

	for (auto &p: vals) {
		ofs << "# ++ " << p.first->label << " * "<< p.second << endl;
	}



	ofs << "(defrule" << endl;
	ofs << "\t(true)" << endl;
	ofs << "=>" << endl;
	ofs << "\t(" << a.effect << ")" << endl;
	ofs << ")" << endl;
}

void PerWriter::write(string fname, shared_ptr<graph::Graph> g) {
	ofstream ofs(fname);

	// for (Action &a: g->actions()) {
	// 	map<graph::Node *, double> vals = g->getUtility(a);
	// 	writeRule(ofs, vals, a);
	// }
}

} /* namespace std */
