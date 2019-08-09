//-//////////////////////////////////////////////////////////////////////////-//
// @file scalar.cpp
// @info Scalar values handling through expression templates
// @author Sayan Bhattacharjee
// @date 8-AUG-2019
//-//////////////////////////////////////////////////////////////////////////-//
#pragma once
#ifndef   __XNDARR_SCALARS_HPP__
#define   __XNDARR_SCALARS_HPP__
#include "common.hpp"
#include <utility>

namespace xn{

/// Scalar object struct to allow usage with expression templates
template<typename T>
class scalar{
  /// Value of the scalar
  T&& val_;

  public:
  scalar(T&& val) : val_(std::forward<T>(val)) {};
  ~scalar() {};
  T&& v() {return val_;};
};
}; // namespace xn
#endif // __XNDARR_SCALARS_HPP__
