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

void PerWriter::write(string fname, shared_ptr<Graph> g) {
	ofstream ofs(fname);

	ofs << "defrule(true)" << endl;
}

} /* namespace std */
