#ifndef BRRTC_H
#define BRRTC_H

#include "RRTController.h"
#include <vector>

// Biased Rapidly-Exploring Random Tree
// We bias towards an end target

class BRRTC : public RRTController {

	private:
		Node destination;
		double distance(vector<double> a, vector<double> b); // Euclidean
		int min(vector<double> a);
	public:
		BRRTC();
		~BRRTC();

		void sample();
}


#endif
