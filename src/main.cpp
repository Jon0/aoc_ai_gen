#include "Parser.h"
#include "PerWriter.h"

using namespace std;

int main(int argc, char *argv[]) {
	Parser p;
	shared_ptr<Graph> g = p.readGraph(argv[1]);
	g->printState();

	PerWriter w;
	w.write("test.per", g);
}
