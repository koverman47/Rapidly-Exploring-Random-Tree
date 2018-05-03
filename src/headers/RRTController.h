#ifndef RRTController_H
#define RRTController_H

#include <cmath>
#include <queue>
#include "ConfigurationSpace.h"
#include "Node.h"
#include "Graph.h"


class RRTController {

	protected:
		std::queue<Node> qu;
		int idGen; // ID Generator, static?
		Graph g;
		int samples;
		double radius;
		double rate;
		double sampleRatio;
		ConfigurationSpace space;

		double distance(Node a, Node b);
	public:
		RRTController(ConfigurationSpace space, Node start, int sampleSize=8, double radius=3, double rate=0.5);
		~RRTController();

		void sample(); // Compute s samples, Push to queue
		Graph getGraph(int epochs=100);
};


#endif
