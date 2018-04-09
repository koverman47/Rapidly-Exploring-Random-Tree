#ifndef BRRTC_H
#define BRRTC_H

#include "RRTController.h"
#include <vector>

// Biased Rapidly-Exploring Random Tree
// We bias towards an end target

class BRRTC : public RRTController {

	private:
		Node point;
		Node destination;
		double distance(Node u, Node v); // Euclidean
		int min(vector<Node> toMin);
	public:
		BRRTC();
		~BRRTC();

		void sample();
}


#endif
