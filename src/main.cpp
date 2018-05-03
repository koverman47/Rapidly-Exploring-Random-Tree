#include <iostream>
#include <cstdlib>
#include "headers/RRTController.h"
#include "headers/RandomSpaceGenerator.h"
#include "headers/ConfigurationSpace.h"
#include "headers/BRRTC.h"
#include <fstream>


using namespace std; // Stacks and Queues implemented in the c++ standard


int main() {
	
	int epochs = 1000;

	//RandomSpaceGenerator rsg = RandomSpaceGenerator();
	//ConfigurationSpace space = ConfigurationSpace(rsg.getObstacles(), rsg.getWidth(), rsg.getHeight());
	
	vector<Node> h1;
	vector<Node> h2;
	/* Square */
	h1.push_back(Node(0, 80, 80));
	h1.push_back(Node(0, 80, 100));
	h1.push_back(Node(0, 100, 100));
	h1.push_back(Node(0, 100, 80));

	h2.push_back(Node(0, 100, 80));
	h2.push_back(Node(0, 100, 50));
	h2.push_back(Node(0, 150, 50));
	h2.push_back(Node(0, 150, 80));

	Hull hull1 = Hull(h1);
	Hull hull2 = Hull(h2);
	vector<Hull> hulls;
	hulls.push_back(hull1);
	hulls.push_back(hull2);

	ConfigurationSpace space = ConfigurationSpace(hulls, 640, 480);
	// (Configuration Space, samples, radius, rate)
	//RRTController rrt = RRTController(space, Node(0, 0, 0), 8, 1, 0.5);
	BRRTC rrt = BRRTC(space, Node(0, 0, 0), Node(1, 200, 200), 16, 1, 0.5);

	for(int i = 0; i < epochs; i++) {
		cout << "Epoch Number: " << i << endl;
		rrt.sample();
	}
	vector<Node> vertexSet = rrt.getGraph().getNodes();
	/*for(Node vertex : vertexSet) {
		cout << "(" << vertex.getX() << ", " << vertex.getY() << ")" << endl;
	}*/
	rrt.getGraph().writeToFile("see.txt");
	ofstream file;
	file.open("obstacles.txt", fstream::app);
	
	file << "{(80,80),(80,100)}" << endl;
	file << "{(80,100),(100,100)}" << endl;
	file << "{(100,100),(100,80)}" << endl;
	file << "{(100,80),(80,80)}" << endl; 

	file << "{(100,80),(100,50)}" << endl;
	file << "{(100,50),(150,50)}" << endl;
	file << "{(150,50),(150,80)}" << endl;
	file << "{(150,80),(100,80)}" << endl;

	file.close();

}







