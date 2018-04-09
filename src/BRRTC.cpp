#include "headers/BRRTC.h"


//TODO: Pass arguments to super class
BRRTC::BRRTC() {
	this->point;
}

//TODO: Fix this up
void BRRTC::sample() {
	bool collision = false;

	for(int s = 0; s < samples; s++) {
		x = radius * cos(sampleRatio * s) + point.getX();
		y = radius * sin(sampleRatio * s) + ->point.getY();

		if(x >= xBound || y >= yBound || x < 0 || y < 0) {
			radius *= radius * rate;
			collision = true;
		}
	}
	if(!collision) {
		radius += radius * rate;
	}
}


void BRRTC::sample() {
	bool isValid = true;
	vector<double> distanceList;
	vector<Node> sampleList;

	for(int s = 0; s < samples; s++) {
		x = radius * cos(sampleRatio * s) + point.getX();
		y = radius * sin(sampleRatio * s) + point.getY();

		if(space.isValidPoiint(point.getX(), point.getY(), x, y)) {
			Node n = new Node(x, y);
			sampleList.push_back(n);
			distanceList.push_back(distance(n, destination));
		}
		else {
			isValid = false;
		}
	}
	point = sampleList[min(distanceList)];
	if(isValid) {
		radius += radius * rate;
	}
	else {
		radius *= radius * rate;
	}
}


double BRRTC::distance(vector<double> a, vector<double> b) {
	double sum = 0;
	for(int i = 0; i < a.size(); i++) { // Assuming a, b are the same size
		sum += pow(a[i] - b[i], 2);
	}
	return sqrt(sum);
}

// Useless because we can keep track as we calculate the distances
int BBRTC::min(vector<double> toMin) {
	int index = 0;
	for(int i = 1; i < toMin.size(); i++) {
		if(toMin[index] < toMin[i]) {
			index = i;
		}
	}
	return index;
}


BRRTC::~BRRTC() {}
