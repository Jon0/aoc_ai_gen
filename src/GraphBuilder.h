#ifndef GRAPHBUILDER_H_
#define GRAPHBUILDER_H_

namespace graph {

class GraphBuilder {
public:
	GraphBuilder() {}

	void add(std::string name, double amount);

	Graph make_graph();
};

} /* namespace graph */

#endif
