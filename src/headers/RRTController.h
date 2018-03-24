#ifndef RRTController_H
#define RRTController_H

#include <cmath>

#include "Edge.h"
#include "Node.h"
#include "Graph.h"


class RRTController {

	private:
		std::queue qu;
		Graph graph;
	public:
		RRTController(int sampleSize = 8, double radius=3, int maxSamples=100, int xBound, int yBound);
		~RRTController();

		void sample(); // Compute s samples, Push to queue
		Node getNext();

};


#endif
