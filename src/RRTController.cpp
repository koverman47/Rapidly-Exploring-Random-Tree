#include "headers/RRTController.h"


RRTController::RRTController(ConfigurationSpace space, int sampleSize, double radius, double rate) {
	this->space = space;
	this->samples = sampleSize;
	this->radius = radius;
	this->rate = rate; // Additive Increase/Multiplicative Decrease - (0,1)
	this->sampleRatio = (2 * M_PI) / sampleSize;
}


void RRTController::sample() {
	Node point = qu.pop();
	bool isValid = true;

	for(int s = 0; s < this->samples; s++) {
		x = radius * cos(sampleRatio * s) + point.getX();
		y = radius * sin(sampleRatio * s) + point.getY();

		if(space.isValidPoint(point.getX(), point.getY(), x, y)) {
			qu.push(new Node(x, y))
		}
		else {
			isValid = false;
		}
	}
	if(isValid) {
		radius += radius * rate;
	}
	else {
		radius *= radius * rate;
	}
}


RRTController::~RRTController() {}
