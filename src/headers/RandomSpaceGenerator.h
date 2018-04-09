#ifndef RandomSpaceGenerator_H
#define RandomSpaceGenerator_H

#include "Hull.h"
#include <cmath>
#include <vector>

class RandomSpaceGenerator {

	private:
		int width;
		int height;
		vector<int> target; // Integer targets easier to consider
		vector<Hull> obstacles;
	
	public:
		// considering only 2D
		// (-1) vs. nullptr
		RandomSpaceGenerator(int x=640, int y=480, int obstacles=1, int targetX=-1, int targetY=-1);
		~RandomSpaceGenerator();

		void generateHull();
		vector<Hull> getObstacles();
};


#endif
