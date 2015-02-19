#include "GameModel.h"

namespace model {

std::vector<Action> &Graph::actions() {
	return actions_list;
}

std::vector<Flow> Graph::getOutgoing(Node &n) {
	vector<Flow> flist;
	for (Flow &f : flows) {
		if (f.from == n.label) {
			flist.push_back(f);
		}
	}
	return flist;
}

double Graph::getFeedback(Node &n) {
	vvector<double> rates;
	for (auto &n : nodes) rates.push_back(0.0);

	std::vector<Node *> reach;
	reach.push_back(&n);

	// this is really slow
	for (int i = 0; i < 25; ++i) {
		std::vector<Flow> fs;
		for (auto n : reach) {
			std::vector<Flow> insert = getOutgoing(*n);
			fs.insert(fs.end(), insert.begin(), insert.end());
		}
		reach.clear();
		for (auto &f : fs) {
			unsigned int index = getNode(f.to)->id;
			rates[index] += f.rate;
			reach.push_back(getNode(f.to));
		}
	}

	std::cout << "feedback = " << rates[n.id] << std::endl;
	return rates[n.id];
}

std::map<Node *, double> Graph::getUtility(Action &a) {
	std::vector<double> c, v;
	c.resize( nodes.size() );
	v.resize( nodes.size() );
	for (Quantity &q: a.cost) {
		c[getNode(q.node_name)->id] = q.amount;
	}
	for (Quantity &q: a.value) {
		v[getNode(q.node_name)->id] = q.amount;
	}
	std::vector<double> vals = getUtility(c, v);
	std::map<Node *, double> mapvals;
	for (auto &n: nodes) {
		mapvals[&n] = vals[n.id];
	}
	return mapvals;
}

// cost and value have length equal to number of nodes
std::vector<double> Graph::getUtility(std::vector<double> cost, std::vector<double> value) {
	std::vector<double> diff;
	for (auto &n : nodes) diff.push_back(0.0);
	for (int i = 0; i < nodes.size(); ++i) {
		diff[i] -= cost[i] * getFeedback(nodes[i]);
		diff[i] += value[i] * getFeedback(nodes[i]);
	}
	return diff;
}	

} /* namespace model */