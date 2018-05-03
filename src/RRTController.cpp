#include "headers/RRTController.h"
#include <cstdlib>


RRTController::RRTController(ConfigurationSpace space, Node start, int sampleSize, double radius, double rate) {
	this->space = space;
	this->samples = sampleSize;
	this->radius = radius;
	this->rate = rate; // Additive Increase/Multiplicative Decrease - (0,1)
	this->sampleRatio = (2 * M_PI) / sampleSize;
	this->idGen = 1;
	qu.push(start);
	g.insertNode(start);
}


void RRTController::sample() {
	printf("Start Sample\n");
	Node point = qu.front();
	qu.pop();
	printf("Point Coordinates: (%f, %f)\n", point.getX(), point.getY());
	bool isValid = true;

	for(int s = 0; s < samples; s++) {
		printf("Sample Number: %d\n", s);
		double x = radius * cos(sampleRatio * s) + point.getX();
		double y = radius * sin(sampleRatio * s) + point.getY();

		Node n = Node(idGen++, x, y);
		if(space.isValidPoint(point, n)) {
			if(rand() % 3 == 0) {
				qu.push(n);
				g.insertNode(n);
				g.insertEdge(Edge(idGen++, point, n, distance(point, n)));
			}
		}
		else {
			isValid = false;
		}
	}
	/*if(isValid) {
		radius += radius * rate;
		radius > 5 ? radius = 5 : true;
	}
	else {
		radius = radius * rate;
		radius < 0.5 ? radius = 0.5 : true;
	}*/
}


Graph RRTController::getGraph(int epochs) {
	return g;
}


double RRTController::distance(Node a, Node b) {
	return sqrt(pow(a.getX() - b.getX(), 2) + pow(a.getY() - b.getY(), 2));
}


RRTController::~RRTController() {}
