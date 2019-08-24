//-//////////////////////////////////////////////////////////////////////////-//
// @file static_vector.cpp
// @info Static vector that allows compile time optimizations
// @author Sayan Bhattacharjee
// @date 8-AUG-2019
//-//////////////////////////////////////////////////////////////////////////-//
#include <assert.h>

XNDARR_STATIC_VECTOR_LTSIG
XNDARR_STATIC_VECTOR_STSIG
  :: static_vector(T data)
{
  std::fill(data_, data_ + N, data);
}

XNDARR_STATIC_VECTOR_LTSIG
XNDARR_STATIC_VECTOR_STSIG
  :: static_vector(const std::initializer_list<T>& data)
{
  assert(N == data.size() &&
    "ERR > initializer list size and static_vector size doesn't match");

  szt i=0;
  for(auto x: data)
    data_[i++] = x;
}

