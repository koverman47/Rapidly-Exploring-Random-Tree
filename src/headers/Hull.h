#ifndef Hull_H
#define Hull_h

#include <cmath>
#include <vector>
#include "Node.h"

class Hull {

	private:
		vector<Node> points;
	public:
		Hull();
		~Hull();

		vector<Node> getPoints();
		bool doesIntersect(double xs, double ys, double xt, double yt);

};

#endif Hull_H
