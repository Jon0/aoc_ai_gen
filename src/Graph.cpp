#include <iostream>

#include "Graph.h"

namespace graph {

Graph::Graph(std::vector<Node> &n, std::unordered_map<Edge, Flow> &e)
	:
	nodes(n),
	edges(e) {}

Graph::~Graph() {}

Node *Graph::getNode(std::string label) {
	for (auto &n: nodes) {
		if (n.label == label) return &n;
	}
	throw std::runtime_error(label + " not a node");
}

std::string Graph::state() const {
	std::string s;
	for (const Node &n: nodes) {
		s += std::to_string(n) + "\n";
	}
	return s;
}

} /* namespace graph */

namespace std {

std::string to_string(const graph::Node &node) {
	return "node " + to_string(node.id) + ", " + node.label;
}

std::string to_string(const graph::Edge &edge) {
	return "edge "+ to_string(edge.first) + " -> " + to_string(edge.second);
}

std::string to_string(const graph::Graph &g) {
	return "graph " + g.state();
}

}
