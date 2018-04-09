#ifndef ConfigurationSpace_H
#define ConfigurationSpace_H

#include <vector>
#include "Hull.h"


class ConfigurationSpace {

	private:
		vector<Hull> obstacles;
		int xBound; // Enforce integer boundaries
		int yBound;
	public:
		ConfigurationSpace(vector<Hull> obstacles, int x=640, int y=480);
		~ConfigurationSpace();
		
		bool isValidPoint(double xs, double ys, double xt, double yt);

};

#endif
