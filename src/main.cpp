#include "parser/Parser.h"
#include "PerWriter.h"

using namespace std;

int main(int argc, char *argv[]) {
	Parser p(argv[1]);
	shared_ptr<Graph> g = p.readGraph();
	g->printState();

	PerWriter w;
	w.write("test.per", g);
}
