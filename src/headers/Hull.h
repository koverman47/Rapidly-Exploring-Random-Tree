#ifndef Hull_H
#define Hull_H

#include <cmath>
#include <vector>
#include "Node.h"

using namespace std;


class Hull {

	private:
		vector<Node> points;
	public:
		Hull(vector<Node> points);
		~Hull();

		vector<Node> getPoints();
		bool doesIntersect(Node s, Node t);
		double determinant(Node a, Node b, Node c);

};

#endif
