#include <iostream>
#include "headers/Edge.h"
#include "headers/Node.h"
#include <cstdlib>


using namespace std; // Stacks and Queues implemented in the c++ standard


int main() {
	
	Node s = Node(0, 0);
	Node t = Node(1, 1);

	Edge e = Edge(s, t);

	cout << "Start (" << e.getStartX() << ", " << e.getStartY() << ")" << endl;
	cout << "End (" << e.getEndX() << ", " << e.getEndY() << ")" << endl;

	return 0;
}
