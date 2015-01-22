#ifndef PERWRITER_H_
#define PERWRITER_H_

#include <memory>
#include <string>
#include <vector>

#include "Action.h"
#include "Graph.h"

namespace std {

void readSpecFile(const char *);

struct Condition {
	int type;
};

class PerWriter {
public:
	PerWriter();
	virtual ~PerWriter();

	void writeRule(ofstream &, map<Node *, double> &, Action &);
	void write(string, shared_ptr<Graph>);
};

} /* namespace std */

#endif /* PERWRITER_H_ */
