//-//////////////////////////////////////////////////////////////////////////-//
// @file static_vector.hpp
// @info Static vector that allows compile time optimizations
// @author Sayan Bhattacharjee
// @date 6-AUG-2019
//-//////////////////////////////////////////////////////////////////////////-//
#pragma once
#ifndef   __XNDARR_STATIC_VECTOR_HPP__
#define   __XNDARR_STATIC_VECTOR_HPP__
#include <array>
#include "common.hpp"

namespace xn {


/// Data regarding row vectors
struct row_vec{
  static const s32 id = 1<<0;
};

/// Data regarding column vectors
struct col_vec{
  static const s32 id = 1<<1;
};


/// Long template signature for class static_vector
#define XNDARR_STATIC_VECTOR_LTSIG \
  template<typename T, szt N, typename VEC_TYPE>

/// Short template signature for class static_vector
#define XNDARR_STATIC_VECTOR_STSIG \
  static_vector<T,N,VEC_TYPE>

/// Static vector class
template<typename T, szt N, typename VEC_TYPE = row_vec>
class static_vector{
  public:
  /// Size of the static vector
  static const szt size_ = N;
  /// Storage format of the static vector (row or column)
  s32 type_ = VEC_TYPE::id;
  /// Data stored in the static vector
  std::array<T,N> data_;

  public:
  static_vector(){}
  ~static_vector(){}

  /// Get size
  static const szt size();

}; // class static_vector

#include "static_vector.cpp"
}; // namespace xn

#endif // __XNDARR_STATIC_VECTOR_HPP__
