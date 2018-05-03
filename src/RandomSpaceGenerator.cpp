#include "headers/RandomSpaceGenerator.h"


RandomSpaceGenerator::RandomSpaceGenerator(int obstacles, int x, int y, int targetX, int targetY) {
	this->numObstacles = obstacles;
	this->width = x;
	this->height = y;
	
	if(targetX >= 0 && targetY >= 0 && targetX <= x && targetY <= y) {
		this->target = Node(-1, targetX, targetY); // ID
	}
}


void RandomSpaceGenerator::generateHull() {

}


vector<Hull> RandomSpaceGenerator::getObstacles() {
	return obstacles;
}


int RandomSpaceGenerator::getWidth() {
	return width;
}


int RandomSpaceGenerator::getHeight() {
	return height;
}


RandomSpaceGenerator::~RandomSpaceGenerator() {}
