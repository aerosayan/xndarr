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

  xn::static_vector<int,500> w,x,y,z;
  auto X = w + x*y - z ;
  //cout << X << endl;

  return 0;
}
