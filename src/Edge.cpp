#include "headers/Edge.h"


Edge::Edge(Node s, Node t) {
	this->source = s;
	this->sink = t;
}


Node Edge::getStart() {
	return source;
}


Node Edge::getEnd() {
	return sink;
}

Edge::~Edge() {}
