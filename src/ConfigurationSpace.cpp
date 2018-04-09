#include "headers/ConfigurationSpace.h"


ConfigurationSpace::ConfigurationSpace(vector<Hull> obstacles, int x, int y) {
	this->obstacles = obstacles;
	this->xBound = x;
	this->yBound = y;
}


// s for source, t for sink
bool isValidPoint(double xs, double ys, double xt, double yt) {
	if(xt > xBound || yt > yBound || xt < 0 || yt < 0) {
		return false;
	}
	for(hull : obstacles) {
		if(hull.doesIntersect(xs, ys, xt, yt)) {
			return false;
		}
	}
	return true;
}


~ConfigurationSpace::ConfigurationSpace() {}
