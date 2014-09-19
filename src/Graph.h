/*
 * Graph.h
 *
 *  Created on: 4/09/2014
 *      Author: remnanjona
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include <map>
#include <string>
#include <vector>

#include "Action.h"

namespace std {

struct Node {
	unsigned int id;
	string label;
};

struct Flow {
	string from;
	string to;
	double rate;
};

class Graph {
public:
	Graph();
	virtual ~Graph();

	void add(Node);
	void add(Flow);
	void add(Action);

	vector<Action> &actions();
	map<Node *, double> getUtility(Action &);

	void printState();

private:
	Node *getNode(string label);
	vector<Flow> getOutgoing(Node &);
	double getFeedback(Node &);
	vector<double> getUtility(vector<double>, vector<double>);

	vector<Node> nodes;
	vector<Flow> flows;
	vector<Action> actions_list;
};

} /* namespace std */

#endif /* GRAPH_H_ */
