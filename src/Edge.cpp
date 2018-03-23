#include "headers/Edge.h"


Edge::Edge(Node s, Node t) {
	this->source = s;
	this->sink = t;
}


double Edge::getStartX() {
	return this->source.getX();
}

double Edge::getEndX() {
	return this->sink.getX();
}

double Edge::getStartY() {
	return this->source.getY();
}

double Edge::getEndY() {
	return this->sink.getY();
}

Edge::~Edge() {}
