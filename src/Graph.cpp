#include "headers/Graph.h"


Graph::Graph() {}


void Graph::insertNode(Node node) {
	for(int i = 0; i < nodes.size(); i++) {
		if(nodes[i].getID() == node.getID()) {
			return;
		}
	}
	nodes.push_back(node);
}


void Graph::insertEdge(Edge edge) {
	for(int i = 0; i < edges.size(); i++) {
		if(edges[i].getID() == edge.getID()) {
			return;
		}
	}
	edges.push_back(edge);
}


void Graph::visualize() {

}


void Graph::writeToFile(string path) {
	ofstream file;
	file.open(path);
	
	//file << "*** Edges ***" << endl;
	for(Edge edge : edges) {
		file << "{(" << edge.getStart().getX() << "," << edge.getStart().getY() << "),(" << edge.getEnd().getX() << "," << edge.getEnd().getY() << ")}" << endl;
	}

	file.close();
}


vector<Node> Graph::getNodes() {
	return nodes;
}


vector<Edge> Graph::getEdges() {
	return edges;
}


Graph::~Graph() {}
