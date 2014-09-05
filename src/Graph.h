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

	vector<Flow> getOutgoing(Node &);
	double getFeedback(Node &);
	vector<double> check(vector<double>, vector<double>);
	void getPoint(Flow);



	map<string, double> getValues();
	void run();
	void printState();

private:
	vector<Node> nodes;
	vector<Flow> flows;
};

} /* namespace std */

#endif /* GRAPH_H_ */
