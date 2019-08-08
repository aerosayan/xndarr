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

  std::vector<int> x,y;
  auto z = xn::expression<decltype((x)),xn::op_add,decltype((y))>(x,y);
  cout << z.x << endl;
  xn::static_vector<int,200> v;
  cout << v.size_ << " " <<  v.type_ << endl;
  cout << v.size() << endl;

  return 0;
}
