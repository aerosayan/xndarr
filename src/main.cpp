//-//////////////////////////////////////////////////////////////////////////-//
// @file main.cpp
// @info Main driver for developing the library.
// @author Sayan Bhattacharjee
// @date 2-AUG-2019
//-//////////////////////////////////////////////////////////////////////////-//
#include "xndarr/xndarr.hpp"
#include <iostream>

int main() {
  // Initialize data
  xn::static_vector<float, 20>
    x({1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20}),
    y({1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20}), z;

  // SIMD vector addition
  z = x + y;

  std::cout << "SIMD vector addition : ";
  for(szt i=0;i<z.size();++i){std::cout<<z.data()[i]<<" ";}std::cout<<std::endl;

  return 0;
}
