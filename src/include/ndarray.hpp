//-//////////////////////////////////////////////////////////////////////////-//
// @file ndarray.hpp
// @info N dimensional array
// @author Sayan Bhattacharjee
// @date 5-AUG-2019
//-//////////////////////////////////////////////////////////////////////////-//
#pragma once
#ifndef __XNDARR_NDARRAY_HPP__
#define __XNDARR_NDARRAY_HPP__

#include <vector>
#include <initializer_list>
#include "vecexpr.hpp"
#include "operations.hpp"

namespace xn {

template<typename T>
class ndarray{
  std::vector<T> data_;
  size_t size_;

  public:
  ndarray();
  ndarray(size_t);
  ndarray(std::initializer_list<T>);
  ~ndarray() {}

  size_t size_v() const;
  std::vector<T>& data_r() const;
  const std::vector<T>& data_cr() const;

}; // class ndarray

}; // namespace xn

#include "ndarray.cpp"
#endif // __XNDARR_NDARRAY_HPP__
