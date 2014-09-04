/*
 * PerWriter.h
 *
 *  Created on: 5/09/2014
 *      Author: remnanjona
 */

#ifndef PERWRITER_H_
#define PERWRITER_H_

#include <memory>
#include <string>

#include "Graph.h"

namespace std {

class PerWriter {
public:
	PerWriter();
	virtual ~PerWriter();

	void write(string, shared_ptr<Graph>);
};

} /* namespace std */

#endif /* PERWRITER_H_ */
