#ifndef BRRTC_H
#define BRRTC_H

#include "RRTController.h"
#include <vector>
#include <stack>
#include "Node.h"
#include "ConfigurationSpace.h"

// Biased Rapidly-Exploring Random Tree
// We bias towards an end target

class BRRTC : public RRTController {

	private:
		Node point;
		Node target;
		double leniency;
		std::stack<Node> backtrack;

		int min(vector<double> toMin);
	public:
		//BRRTC() : RRTController();
		BRRTC(ConfigurationSpace space, Node start, Node target, int sampleSize=8, double radius=3, double rate=0.5, double leniency=0.5);
		~BRRTC();

		virtual void sample();
};

#endif
