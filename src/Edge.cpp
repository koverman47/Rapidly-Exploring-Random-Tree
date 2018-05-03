#include "headers/Edge.h"


Edge::Edge(int id, Node s, Node t, double w) {
	this->source = s;
	this->sink = t;
	this->weight = w;
	this->id = id;
}


Node Edge::getStart() {
	return source;
}


Node Edge::getEnd() {
	return sink;
}


double Edge::getWeight() {
	return weight;
}


void Edge::setWeight(double w) {
	weight = w;
}


int Edge::getID() {
	return id;
}


Edge::~Edge() {}
