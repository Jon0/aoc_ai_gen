#ifndef GAMEMODEL_H_
#define GAMEMODEL_H_

#include "Graph.h"

namespace model {

class GameModel {
public:
	GameModel() {}

	std::vector<Action> &actions();
	std::map<Node *, double> getUtility(Action &);


private:
	graph::Graph g;
	std::vector<Action> actions_list;
};

} /* namespace model */

#endif