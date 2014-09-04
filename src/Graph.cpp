/*
 * Graph.cpp
 *
 *  Created on: 4/09/2014
 *      Author: remnanjona
 */

#include <iostream>

#include "Graph.h"

namespace std {

Graph::Graph() {}

Graph::~Graph() {}

Node *Graph::getNode(string label) {
	for (Node &n: nodes) {
		if (n.label == label) return &n;
	}
}

void Graph::add(Node n) {
	nodes.push_back(n);
}

void Graph::add(Flow f) {
	flows.push_back(f);
}

map<string, double> Graph::getValues() {
	map<string, double> next_values;
	for (Node &n: nodes) {
		next_values.insert(map<string, double>::value_type(n.label, n.value));
	}
	return next_values;
}

void Graph::getPoint(Flow f) {
	// weighting on each node
	// decision made if sum >= 0
	vector<double> weights;





}

void Graph::run() {
	for (int i = 0; i < 100; ++i) {
		map<string, double> next_values = getValues();

		// update each flow
		for (Flow &f: flows) {
			double inc = getNode(f.from)->value * f.rate;
			next_values[f.from] -= f.cost * inc;
			double &v = next_values[f.to];
			v += inc;
			if (v < 0) v = 0;
		}

		for (Node &n: nodes) {
			n.value = next_values[n.label];
		}
		cout << endl;
		printState();
	}
}

void Graph::printState() {
	for (Node &n: nodes) {
		cout << n.label << " = " << n.value << endl;
	}
}

} /* namespace std */
