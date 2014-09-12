#ifndef ACTION_H_
#define ACTION_H_

#include <string>
#include <vector>

namespace std {

struct Quantity {
	string node_name;
	double amount;
};

class Action {
public:
	Action();
	virtual ~Action();

	vector<Quantity> cost, value;
	double time;
	string effect;
};

}

#endif /* ACTION_H_ */
