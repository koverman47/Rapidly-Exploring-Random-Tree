#ifndef Node_H
#define Node_H

/* Notes:
 * 	- Assuming Two Dimensional Configuration Space
 *
 *
 * Questions:
 * 	- After traversing to a new vertex, will there be any case in which I want to keep 'backwards' references?
 *
 */




class Node {

	private:
			double x; // These coordinates should not be changed after they are first set.
			double y;
	public:
			// Internal Value checking - the RRTController should protect against out of bounds coordinates
			Node(double x = -1, double y = -1); // Default to generic invalid coordinates if given nothing
			~Node();

			double getX();
			double getY();			
};


#endif
