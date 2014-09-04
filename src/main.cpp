#include "Parser.h"
#include "PerWriter.h"

using namespace std;

int main() {
	Parser p;
	shared_ptr<Graph> g = p.readGraph("test.txt");


	PerWriter w;
	w.write("test.per", g);
}
