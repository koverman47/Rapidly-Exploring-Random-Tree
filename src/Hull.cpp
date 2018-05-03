#include "headers/Hull.h"


Hull::Hull(vector<Node> points) {
	this->points = points;
}


bool Hull::doesIntersect(Node s, Node t) {
	for(int i = 0; i < points.size() - 1; i++) {
		if((determinant(points[i], s, t) > 0 ^ determinant(points[i + 1], s, t) > 0) && (determinant(s, points[i], points[i + 1]) > 0 ^ determinant(t, points[i], points[i + 1]) > 0)) {
			return true;
		}
		if((determinant(points[0], s, t) > 0 ^ determinant(points.back(), s, t) > 0) && (determinant(s, points[0], points.back()) > 0 ^ determinant(t, points[0], points.back()) > 0)) {
			return true; // Fence Post
		}
	}
	return false;
}


/*
 * [1 	ax	ay]
 * [1	bx	by]
 * [1	cx	cy]
 */
double Hull::determinant(Node a, Node b, Node c) {
	double first = (b.getX() * c.getY()) - (b.getY() * c.getX());
	double second = a.getX() * (c.getY() - b.getY());
	double third = a.getY() * (c.getX() - b.getX());
	return first - second + third;
}


vector<Node> Hull::getPoints() {
	return points;
}


Hull::~Hull() {}
