#ifndef Edge_H
#define Edge_H

#include "Node.h"

class Edge {

	private:
		Node source;
		Node sink;
		double weight;
		int id;
	public:
		Edge(int id, Node s, Node t, double w=0);
		~Edge();

		Node getStart();
		Node getEnd();
		double getWeight();
		void setWeight(double w);
		int getID();

};


#endif
