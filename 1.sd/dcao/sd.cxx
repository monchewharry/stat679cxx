// Write a program called "sd.cxx" that computes the sample standard
// deviation of a set of data.
//
// Your program should include three functions:
//
// - mean(), which takes two parameters:
//   - n, an integer, the length of the array being passed
//   - x, an array of doubles (as a pointer), the data
//
// - sd(), which takes two parameters:
//   - n, an integer, the length of the array being passed
//   - x, an array of doubles (as a pointer), the data
//   sd() should call mean() as part of its calculation
//
// - main(), which should:
//   - prompt the user for the number of points
//   - read in the number of points and then the points themselves
//   - use your sd() function to find the standard deviation
//


// Note: If the user types 5 and then 1 2 3 4 5, you should get a
// standard deviation of about 1.58.

#include <iostream>
#include <cmath>
using namespace std;

double mean(int n, double *x);
double sd(int n, double *x);

int main(){
  cout << "How many points";
  int n_points =0;
  cin >> n_points;
  double *x = new double[n_points];
  for (int i = 0; i < n_points; ++i){
    x[i] = i+1;
  }
  double stdeviation = 0;
  stdeviation = sd(n_points,x);
  delete [] x;

  cout <<"sample standard deviation=" << stdeviation<<"."<<endl;
  return 0;

}


double mean(int n, double *x){
  double s1 = 0;
  for ( int i = 0; i < n; i++ ){
    s1 += x[i];
  }
  double m = 0;
  m=s1/n;
  return m;
}

double sd(int n, double *x){
  double mu = 0;
  mu = mean(n, x);
  double s2 = 0;
  for ( int i = 0; i < n; i++ )    {
    s2 += pow((x[i]-mu),2);
  }
  double standardDev = 0;
  standardDev= sqrt(s2/(n-1));
  return standardDev;
}
