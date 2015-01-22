#include <iostream>

#include "Simulator.h"

namespace std {

Simulation::Simulation() {}

void Simulation::run() {

	// simple model with 2 players
	resources["p1_workers"] = 10.0;
	resources["p1_stockpile"] = 0.0;
	resources["p1_military"] = 0.0;
	resources["p2_workers"] = 10.0;
	resources["p2_stockpile"] = 0.0;
	resources["p2_military"] = 0.0;

	// players decide spending, and targeting ratio
	p1_spend = 0.0;
	p1_target = 0.5;
	p2_spend = 0.1;
	p2_target = 0.3;

	auto s = []() {};

	running = true;
	while (running) {
		update();
	}
}

void Simulation::update() {

	auto new_p1_stock = resources["p1_workers"];
	auto new_p2_stock = resources["p2_workers"];

	auto new_p1_work = resources["p1_workers"] + resources["p1_stockpile"] * p1_spend - resources["p2_military"] * p2_target;
	auto new_p2_work = resources["p2_workers"] + resources["p2_stockpile"] * p2_spend - resources["p1_military"] * p1_target;

	auto new_p1_mil = resources["p1_military"] + resources["p1_stockpile"] * (1.0-p1_spend) - resources["p2_military"] * (1.0-p2_target);
	auto new_p2_mil = resources["p2_military"] + resources["p2_stockpile"] * (1.0-p2_spend) - resources["p1_military"] * (1.0-p1_target);

	if (new_p1_mil < 0.0) new_p1_mil = 0.0;
	if (new_p2_mil < 0.0) new_p2_mil = 0.0;

	resources["p1_workers"] = new_p1_work;
	resources["p1_stockpile"] = new_p1_stock;
	resources["p1_military"] = new_p1_mil;
	resources["p2_workers"] = new_p2_work;
	resources["p2_stockpile"] = new_p2_stock;
	resources["p2_military"] = new_p2_mil;

	std::cout << resources["p1_workers"] << " & " << resources["p1_military"] << " vs ";
	std::cout << resources["p2_workers"] << " & " << resources["p2_military"] << std::endl;


	if (resources["p1_workers"] <= 0 || resources["p2_workers"] <= 0) {
		running = false;
	}
}

} /* namespace std */
