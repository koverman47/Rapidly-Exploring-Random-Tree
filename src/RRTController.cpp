#include "headers/RRTController.h"


RRTController::RRTController(int sampleSize, double radius, int maxSamples, int xBound, int yBound, double rate) {
	this->samples = sampleSize;
	this->radius = radius;
	this->epochs = maxSamples; // Is this RRT Controller's responsibility?
	this->xBound = xBound;
	this->yBound = yBound;
	this->rate = rate; // Additive Increase/Multiplicative Decrease - (0,1)
	this->sampleRatio = (2 * M_PI) / sampleSize;
}


void RRTController::sample() {
	Node point = qu.pop();
	bool collision = false;

	for(int s = 0; s < this->samples; s++) {
		x = this->radius * cost(this->sampleRatio * s) + point.getX();
		y = this->radius * sin(this->sampleRatio * s) + point.getY();

		if(x >= this->xBound || y >= this-> yBound || x < 0 || y < 0) {
			this->radius *= this->radiius * this->rate; // The more collisions, the smaller we make the radius;
		}

		qu.push(new Node(x, y));
	}
	if(!collision) {
		this->radius += this->radius * this->rate;
	}
}


Node RRTController::getNext() {
	return this->qu.front;
}


RRTController::~RRTController() {}
