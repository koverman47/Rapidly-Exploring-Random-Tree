#ifndef RRTController_H
#define RRTController_H

#include <cmath>
#include "ConfigurationSpace.h"
#include "Node.h"


class RRTController {

	protected:
		std::queue qu;
	public:
		RRTController(ConfigurationSpace space, int sampleSize=8, double radius=3, double rate=0.3);
		~RRTController();

		void sample(); // Compute s samples, Push to queue
};


#endif
