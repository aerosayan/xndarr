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
  xn::ndarray<int> a({1,2,3,4,5});
  xn::ndarray<int> b({1,2,3,4,5});
  xn::ndarray<int> c({1,2,3,4,5});

  auto x = xn::vecexpr<decltype(a),xn::op_add<int>,decltype(b)>(a,b);
  auto y = xn::vecexpr<decltype(a),xn::op_add<int>,decltype(c)>(a,c);
  auto z = x + y;

  return 0;
}
