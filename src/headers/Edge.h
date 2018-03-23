#ifndef Edge_H
#define Edge_H

#include "Node.h"

class Edge {

	private:
		Node source;
		Node sink;
		
	public:
		Edge(Node s, Node t);
		~Edge();

		// I am going about it this way because c++ tuples are awful to look at
		double getStartX();
		double getEndX();
		double getStartY();
		double getEndY();

};


#endif
