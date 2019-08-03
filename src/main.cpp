//-//////////////////////////////////////////////////////////////////////////-//
// @file main.cpp
// @info Main driver for developing the library.
// @author Sayan Bhattacharjee
// @date 2-AUG-2019
//-//////////////////////////////////////////////////////////////////////////-//

#include "include/xndarr.hpp"
#include <iostream>

using namespace std;


int main()
{
  double x = 5.0;
  double y = 10.0;

  auto exp = xn::vecexpr<double,xn::op_div<double>,double>(x,y);
  cout << exp.eval() << endl;

  return 0;
}
