#include "headers/ConfigurationSpace.h"


ConfigurationSpace::ConfigurationSpace() {}


ConfigurationSpace::ConfigurationSpace(vector<Hull> obstacles, int x, int y) {
	this->obstacles = obstacles;
	this->xBound = x;
	this->yBound = y;
}


// s for source, t for sink
bool ConfigurationSpace::isValidPoint(Node s, Node t) {
	if(t.getX() > xBound || t.getY() > yBound || t.getX() < 0 || t.getY() < 0) {
		return false;
	}
	for(Hull hull : obstacles) {
		if(hull.doesIntersect(s, t)) {
			return false;
		}
	}
	return true;
}


ConfigurationSpace::~ConfigurationSpace() {}
