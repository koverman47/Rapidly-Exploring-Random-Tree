#ifndef RandomSpaceGenerator_H
#define RandomSpaceGenerator_H

#include "Hull.h"
#include <cmath>
#include <vector>
#include "Node.h"


class RandomSpaceGenerator {

	private:
		int width;
		int height;
		int numObstacles;
		Node target; // Integer targets easier to consider
		vector<Hull> obstacles;
	
	public:
		// considering only 2D
		// (-1) vs. nullptr
		RandomSpaceGenerator(int obstacles=1, int x=640, int y=480, int targetX=-1, int targetY=-1);
		~RandomSpaceGenerator();

		void generateHull();
		vector<Hull> getObstacles();
		int getWidth();
		int getHeight();
};


#endif
