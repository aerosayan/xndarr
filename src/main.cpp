//-//////////////////////////////////////////////////////////////////////////-//
// @file main.cpp
// @info Main driver for developing the library.
// @author Sayan Bhattacharjee
// @date 2-AUG-2019
//-//////////////////////////////////////////////////////////////////////////-//

#include "include/xndarr.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;


int main()
{
  // Initialize data
  xn::static_vector<int, 10> x({1,2,3,4,5,6,7,8,9,10}),
                             y({1,2,3,4,5,6,7,8,9,10}),
                             z;
  // Normal evaluation
  cout << "Normal eval : "
       << x[0] + y[0] << endl; // Access data like a normal vector

  // Lazy evaluation
  auto f = x + y;
  cout << "Lazy eval   : ";
  cout << f[0] << endl;   // Calculates only x[0] + y[0]

  // Forced evaluation
  z = x + y;              // Assignment(=) triggers the forced evaluation.
                          // In forced evaluation, the whole vector is processed
  cout << "Forced eval : ";
  for(auto x : z.data_) cout << x << " "; cout << endl;

  return 0;
}
