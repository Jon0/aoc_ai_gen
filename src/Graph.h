#ifndef GRAPH_H_
#define GRAPH_H_

#include <functional>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

#include "Action.h"

namespace graph {

struct Node {
	unsigned int id;
	std::string label;
};

struct Flow {
	std::function<double()> rate;
};

using Edge = std::pair<Node, Node>;

}

namespace std {

std::string to_string(const graph::Node &node);

std::string to_string(const graph::Edge &edge);

template<> struct hash<graph::Node> {
	typedef std::size_t result_type;
	result_type operator()( const graph::Node &arg ) const {
        return arg.id;
	}
};

template<> struct hash<graph::Edge> {
	typedef std::size_t result_type;
	result_type operator()( const graph::Edge &arg ) const {
		result_type const s ( std::hash<graph::Node>()(arg.first) );
        result_type const e ( std::hash<graph::Node>()(arg.second) );
        return s ^ (e << 1);
	}
};

}

namespace graph {

class Graph {
public:
	Graph(std::vector<Node> &n, std::unordered_map<Edge, Flow> &e);
	virtual ~Graph();

	std::string state() const;

private:
	std::vector<Node> nodes;
	std::unordered_map<Edge, Flow> edges;

	Node *getNode(std::string label);
	std::vector<Flow> getOutgoing(Node &);
	double getFeedback(Node &);
	std::vector<double> getUtility(std::vector<double>, std::vector<double>);

	std::vector<Flow> flows;
};

} /* namespace graph */

namespace std {
	
std::string to_string(const graph::Graph &g);

}

#endif /* GRAPH_H_ */
