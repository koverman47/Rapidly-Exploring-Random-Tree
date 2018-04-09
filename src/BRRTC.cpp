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

double BRRTC::distance(vector<double> a, vector<double> b) {
	double sum = 0;
	for(int i = 0; i < a.size(); i++) { // Assuming a, b are the same size
		sum += pow(a[i] - b[i], 2);
	}
	return sqrt(sum);
}

// Useless because we can keep track as we calculate the distances
int BBRTC::min(vector<double> a) {
	int index = 0;
	for(int i = 1; i < a.size(); i++) {
		if(a[index] < a[i]) {
			index = i;
		}
	}
	return index;
}


BRRTC::~BRRTC() {}
