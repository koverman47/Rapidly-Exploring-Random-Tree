#ifndef Graph_H
#define Graph_H

#include <vector>
#include "Node.h"
#include "Edge.h"
#include <iostream>
#include <fstream>

using namespace std;


class Graph {

	private:
		vector<Node> nodes;
		vector<Edge> edges;
	public:
		Graph();
		~Graph();

		void insertNode(Node node);
		void insertEdge(Edge edge);
		void visualize();
		void writeToFile(string path="see.txt");
		vector<Node> getNodes();
		vector<Edge> getEdges();

};

#endif
