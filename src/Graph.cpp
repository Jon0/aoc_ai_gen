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
	n.id = nodes.size();
	nodes.push_back(n);
}

void Graph::add(Flow f) {
	flows.push_back(f);
}

void Graph::add(Action a) {
	actions_list.push_back(a);
}

vector<Action> &Graph::actions() {
	return actions_list;
}

vector<Flow> Graph::getOutgoing(Node &n) {
	vector<Flow> flist;
	for (Flow &f : flows) {
		if (f.from == n.label) {
			flist.push_back(f);
		}
	}
	return flist;
}

double Graph::getFeedback(Node &n) {
	vector<double> rates;
	for (Node &n : nodes) rates.push_back(0.0);

	vector<Node *> reach;
	reach.push_back(&n);

	for (int i = 0; i < 50; ++i) {
		vector<Flow> fs;
		for (Node *n : reach) {
			vector<Flow> insert = getOutgoing(*n);
			fs.insert(fs.end(), insert.begin(), insert.end());
		}
		reach.clear();
		for (Flow &f : fs) {
			unsigned int index = getNode(f.to)->id;
			rates[index] += f.rate;
			reach.push_back(getNode(f.to));
		}
	}
	return rates[n.id];
}

vector<double> Graph::getUtility(Action &a) {
	vector<double> c, v;
	c.resize( nodes.size() );
	v.resize( nodes.size() );
	for (Quantity &q: a.cost) {
		c[getNode(q.node_name)->id] = q.amount;
	}
	for (Quantity &q: a.value) {
		v[getNode(q.node_name)->id] = q.amount;
	}
	return getUtility(c, v);
}

// cost and value have length equal to number of nodes
vector<double> Graph::getUtility(vector<double> cost, vector<double> value) {
	vector<double> diff;
	for (Node &n : nodes) diff.push_back(0.0);
	for (int i = 0; i < nodes.size(); ++i) {
		diff[i] -= cost[i] * getFeedback(nodes[i]);
		diff[i] += value[i] * getFeedback(nodes[i]);
	}
	return diff;
}

void Graph::getPoint(Flow f) {
	// weighting on each node
	// decision made if sum >= bias
	vector<double> weights;
}

map<string, double> Graph::getValues() {
	map<string, double> next_values;
	for (Node &n : nodes) {
		next_values.insert(map<string, double>::value_type(n.label, n.value));
	}
	return next_values;
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
	for (Action &a: actions_list) {
		cout << "action " << a.effect << endl;
	}
}

} /* namespace std */
