#include "headers/Node.h"


Node::Node() {}


Node::Node(int id, double x, double y) {
	if(x == -1 || y == -1) {
		// Error
	}
	this->x = x;
	this->y = y;
	this->id = id;
}


double Node::getX() {
	return x;
}


double Node::getY() {
	return y;
}


int Node::getID() {
	return id;
}


Node::~Node() {}
