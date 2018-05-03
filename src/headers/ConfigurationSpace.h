#ifndef ConfigurationSpace_H
#define ConfigurationSpace_H

#include <vector>
#include "Hull.h"
#include "Node.h"


class ConfigurationSpace {

	private:
		vector<Hull> obstacles;
		int xBound; // Enforce integer boundaries
		int yBound;
	public:
		ConfigurationSpace(vector<Hull> obstacles, int x=640, int y=480);
		ConfigurationSpace();
		~ConfigurationSpace();
		
		bool isValidPoint(Node s, Node t);

};

#endif
