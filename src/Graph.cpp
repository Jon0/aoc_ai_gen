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
	throw runtime_error(label + " not a node");
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

	// this is really slow
	for (int i = 0; i < 25; ++i) {
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

	cout << "feedback = " << rates[n.id] << endl;
	return rates[n.id];
}

map<Node *, double> Graph::getUtility(Action &a) {
	vector<double> c, v;
	c.resize( nodes.size() );
	v.resize( nodes.size() );
	for (Quantity &q: a.cost) {
		c[getNode(q.node_name)->id] = q.amount;
	}
	for (Quantity &q: a.value) {
		v[getNode(q.node_name)->id] = q.amount;
	}
	vector<double> vals = getUtility(c, v);
	map<Node *, double> mapvals;
	for (Node &n: nodes) {
		mapvals[&n] = vals[n.id];
	}
	return mapvals;
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

void Graph::printState() {
	for (Node &n: nodes) {
		cout << "node " << n.label << endl;
	}
	for (Action &a: actions_list) {
		cout << "action " << a.effect << endl;
	}
}

} /* namespace std */
