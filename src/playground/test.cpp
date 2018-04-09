/*
 * This is for playing around with the C++ language as I get more familiar with it.
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


class X {
	public:
		void pp() { cout << "X - Pretty Print" << endl; }
	protected:
		void printSix() { cout << "Six :: 6" << endl; }
		int getZ() { return z; }
		int dim = 3;
	private:
		int z = 200;
} x;

class Y : public X {
	public:
		void pp() { cout << "Y - Pretty Print" << endl; }
		void callProtected() { printSix(); }
		void printZ() { cout << getZ() << endl; }
		void printDim() { cout << dim << endl; }
} y;


double distance(vector<double> a, vector<double> b) {
	double sum = 0;
	for(int i = 0; i < a.size(); i++) {
		sum += pow(a[i] - b[i], 2);
	}
	return sqrt(sum);
}


int main() {
	cout.precision(63);

	vector<double> a = {0.0, 0.0};
	vector<double> b = {3.0, 4.0};

	cout << distance(a, b) << endl;

	/*x.pp();
	y.pp();
	y.callProtected();
	y.printZ();
	y.printDim();*/
}
