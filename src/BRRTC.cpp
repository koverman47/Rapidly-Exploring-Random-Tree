#include "headers/BRRTC.h"
#include <cstdlib>


BRRTC::BRRTC(ConfigurationSpace space, Node start, Node target, int sampleSize, double radius, double rate, double leniency) : RRTController(space, start, sampleSize, radius, rate) {
	this->idGen = 2;
	this->target = target;
	backtrack.push(start);
	g.insertNode(start);
	g.insertNode(target);
}

void BRRTC::sample() {
	bool isValid = true;
	vector<double> distanceList;
	vector<Node> sampleList;
    printf("Radius: %f\n", radius);

	for(int s = 0; s < samples; s++) {
		double x = radius * cos(sampleRatio * s) + point.getX();
		double y = radius * sin(sampleRatio * s) + point.getY();

		Node n = Node(idGen++, x, y);
		if(space.isValidPoint(point, n)) {
			sampleList.push_back(n);
			distanceList.push_back(distance(n, target)); // Distance function from super class
		}
		else {
			isValid = false;
		}
	}
	int minIndex = min(distanceList);
	Node temp;
	if(distanceList[minIndex] > (distance(backtrack.top(), target) + leniency * radius)) {
		temp = backtrack.top();
		backtrack.pop();
	}
	else {
		temp = sampleList[min(distanceList)];
		for(int i = 0; i < sampleList.size(); i++) {
			if(i != minIndex) {
				backtrack.push(sampleList[i]);
			}
		}
	}
	g.insertNode(temp);
	g.insertEdge(Edge(idGen++, point, temp, distance(point, temp)));
	point = temp;
	if(isValid) {
		radius += radius * rate;
        radius > 5 ? radius = 5 : true; // c++ requires shorthand else?
	}
	else {
        radius = radius * rate;
        radius < 0.1 ? radius = 0.1 : true;
        
	}
}


// Useless because we can keep track as we calculate the distances
int BRRTC::min(vector<double> toMin) {
	int index = 0;
	for(int i = 1; i < toMin.size(); i++) {
		if(toMin[i] < toMin[index]) {
			index = i;
		}
	}
	return index;
}


BRRTC::~BRRTC() {}
