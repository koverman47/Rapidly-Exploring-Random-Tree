#include "headers/Node.h"


Node::Node(double x, double y) {
	if(x == -1 || y == -1) {
		// Error
	}
	this->x = x;
	this->y = y;
}


double Node::getX() {
	return this->x;
}

double Node::getY() {
	return this->y;
}

Node::~Node() {}
