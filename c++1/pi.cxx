// pi.cxx: Estimate PI by Monte Carlo simulation. Consider a square of
// side length 1 with area 1*1 = 1. An inscribed circle has radius
// 1/2, so its area is PI*(1/2)*(1/2) = PI/4. Generate random points
// in the square. The ratio of points inside the circle to the number
// generated is an estimate of PI/4. Multiply it by 4 to estimate PI.

// Compile pi.cxx in emacs via:
//    M-x compile Enter
//    g++ -Wall -g -o x pi.cxx
// (In the line above, -W = warnings, -g = include debuging data, -o = output.)
// Then, to see the first compile error:
//    C-x `
// To run x in an emacs shell:
//    M-x shell Enter
//    x

#include <cstdlib>  // for random()
#include <iostream> // for cin, cout
#include <cmath>    // for sqrt()

using namespace std; // lets us write cin, cout instead of std::cin, std::cout

// Return random number in [-1/2, 1/2).
double randomMinusOneHalfToOneHalf();

// Return distance between (x, y) and (0, 0). (Declare function before call.)
double distanceFromOrigin(double x, double y);

// Return number of n points specified by { (x[i], y[i]) } that are
// inside circle centered at (0, 0) having radius 0.5.
int how_many_inside_circle(int n, double *x, double *y);

int main() { // execution starts in main()
    // write to standard output
    cout << "How many random points shall we place in the square? ";
    int n_points_inside_square = 0; // declare a variable
    cin >> n_points_inside_square; // read from standard input

    // allocate memory for two arrays
    double *x = new double[n_points_inside_square]; // draw: x gets the address
    double *y = new double[n_points_inside_square]; // of an array of n ints,
                                                    // x[0] through x[n-1]
    for (int i = 0; i < n_points_inside_square; ++i) { // make points in square
	x[i] = randomMinusOneHalfToOneHalf();
	y[i] = randomMinusOneHalfToOneHalf();
    }

    int n_points_inside_circle =
	how_many_inside_circle(n_points_inside_square, x, y);
    delete [] x; // release memory allocated by new
    delete [] y;

    float PI_estimate = 4.0 * n_points_inside_circle / n_points_inside_square;

    cout << "n_points_inside_circle=" << n_points_inside_circle
	 << " and n_points_inside_square=" << n_points_inside_square
	 << "." << endl;
    cout << "PI is approximately " << PI_estimate << endl << endl;

    return 0; // main() returns 0 to indicate success, nonzero for failure
}

// Now implement functions declared above main().

double randomMinusOneHalfToOneHalf() {
    // In emacs, do
    //   M-x man Enter
    //   random Enter
    // to see random() returns a random integer in [0, RAND_MAX].
    // RAND_MAX is a constant, typically 2^31. double() coerces its
    // integer argument to double, which causes real-number division
    // instead of integer division.
    double random0to1 = double(random()) / RAND_MAX;
    return random0to1 - 0.5;
}

double distanceFromOrigin(double x, double y) {
    return sqrt(x*x + y*y);
}

int how_many_inside_circle(int n, double *x, double *y) {
    int n_inside = 0;
    for (int i = 0; i < n; ++i) {
	if (distanceFromOrigin(x[i], y[i]) < 0.5)
	    n_inside++;
    }
    return n_inside;
}
