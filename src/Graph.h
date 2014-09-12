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

	// not needed
	double value;
};

struct Flow {
	string from;
	string to;
	double rate;

	// not needed
	double cost;
	bool control;
};

class Graph {
public:
	Graph();
	virtual ~Graph();

	Node *getNode(string label);

	void add(Node);
	void add(Flow);
	void add(Action);

	vector<Action> &actions();
	vector<Flow> getOutgoing(Node &);
	double getFeedback(Node &);


	vector<double> getUtility(Action &);
	vector<double> getUtility(vector<double>, vector<double>);
	void getPoint(Flow);



	map<string, double> getValues();
	void run();

	void printState();

private:
	vector<Node> nodes;
	vector<Flow> flows;
	vector<Action> actions_list;


};

} /* namespace std */

#endif /* GRAPH_H_ */
