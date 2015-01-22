#ifndef SIMULATOR_H_
#define SIMULATOR_H_

#include <unordered_map>

namespace std {

class Simulation{
public:
	Simulation();

	void run();


private:
	void update();

	bool running;

	std::unordered_map<std::string, double> resources;

	double p1_spend, p1_target, p2_spend, p2_target;

};

} /* namespace std */

#endif /* SIMULATOR_H_ */