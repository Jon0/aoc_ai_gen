#include "GraphBuilder.h"

namespace graph {

Graph GraphBuilder::make_graph() {
	std::vector<Node> nodes;
	std::vector<Edge> edges;

	return Graph(nodes, edges);
}

} /* namespace graph */
