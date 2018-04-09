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

		Node getStart();
		Node getEnd();

};


#endif
