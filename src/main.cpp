//-//////////////////////////////////////////////////////////////////////////-//
// @file main.cpp
// @info Main driver for developing the library.
// @author Sayan Bhattacharjee
// @date 2-AUG-2019
//-//////////////////////////////////////////////////////////////////////////-//

#include "include/xndarr.hpp"
#include <immintrin.h>
#include <iostream>
#include <stdexcept>

using namespace std;

template<class OP, class TYPE, s32 SIMD>
struct apply
{
};

template<>
struct apply<xn::op_add,float,256>
{
  __m256 operator()(const float* a, const float* b)
  {
    return _mm256_add_ps(_mm256_loadu_ps(a), _mm256_loadu_ps(b));
  }
};

int main() {
  // Initialize data
  xn::static_vector<float, 10> x({1,2,3,4,5,6,7,8,9,10}),
                               y({1,2,3,4,5,6,7,8,9,10}),
                               z;

  // Dispatch a call to the proper specilization of apply
  __m256 data = apply<xn::op_add,decltype(x.dtype),256>()
                                         (&x.data()[0],&y.data()[0]);

  // Store the data (8 floats) into z
  _mm256_storeu_ps(&z.data()[0], data);

  cout << "SIMD eval of 8 floats: ";
  for(szt i=0; i<z.size(); ++i) cout << z.data()[i] << " "; cout << endl;

  return 0;
}
