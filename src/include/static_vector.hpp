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
#include <iostream>
#include "common.hpp"

namespace xn {


/// Data regarding row vectors
struct row_vec{
  static const s32 id_ = 1<<0;
};

/// Data regarding column vectors
struct col_vec{
  static const s32 id_ = 1<<1;
};


/// Long template signature for class static_vector
#define XNDARR_STATIC_VECTOR_LTSIG \
  template<typename T, szt N, typename VEC_TYPE>

/// Short template signature for class static_vector
#define XNDARR_STATIC_VECTOR_STSIG \
  static_vector<T,N,VEC_TYPE>

//-//////////////////////////////////////////////////////////////////////////-//
/// Static vector class
//-//////////////////////////////////////////////////////////////////////////-//
// NOTE : The data will be allocated on the stack thus it is required that the
// amount of elements `requested` to be stored through template parameter `N`
// should be less than the maximum  allowable limit for the stackk.
// It should also be noted that the type `T` plays a factor in the deduction
// of maximum number of elements that can be stored.
//-//////////////////////////////////////////////////////////////////////////-//
template<typename T, szt N, typename VEC_TYPE = row_vec>
class static_vector{
  public:
  /// Size of the static vector
  const szt size_ = N;
  /// Storage format of the static vector (row or column)
  s32 type_ = VEC_TYPE::id_;
  /// Data stored in the static vector
  T data_[N];

public:
  /// Variable of data type T
  //  This is used to identify the type of T at compile and runtime
  T dtype;

  public:
  static_vector() {}

  static_vector(T);

  static_vector(const std::initializer_list<T>& );

  ~static_vector(){}

  /// Get size
  constexpr szt size();


  //-///////////////////////////////////////////////////////////////////////-//
  /// Overloading opeartors
  //-///////////////////////////////////////////////////////////////////////-//
  T operator[](szt i) const
  {
    return data_[i];
  }

  template<typename RHSXP>
  static_vector<T,N>& operator=(RHSXP&& rhs)
  {
    szt i = 0;

    #if defined(XNSIMD_AVX3_AVAILABLE)
    #error "AVX3 enabled?"
    for( ; i<(N & ~7); i += 8){

    }
    #endif

    for( ; i<N; ++i){
      data_[i] = rhs[i];
    }

    return *this;
  }

  template<typename RHSXP>
  decltype(auto) operator+(RHSXP&& rhs)
  {
    return expression<
      XNDARR_STATIC_VECTOR_STSIG const &,
      op_add,
      decltype(std::forward<RHSXP>(rhs))>
      (*this, std::forward<RHSXP>(rhs));
  }

  template<typename RHSXP>
  decltype(auto) operator-(RHSXP&& rhs)
  {
    return expression<
      XNDARR_STATIC_VECTOR_STSIG const &,
      op_sub,
      decltype(std::forward<RHSXP>(rhs))>
      (*this, std::forward<RHSXP>(rhs));
  }

  template<typename RHSXP>
  decltype(auto) operator*(RHSXP&& rhs)
  {
    return expression<
      XNDARR_STATIC_VECTOR_STSIG const &,
      op_mul,
      decltype(std::forward<RHSXP>(rhs))>
      (*this, std::forward<RHSXP>(rhs));
  }

  template<typename RHSXP>
  decltype(auto) operator/(RHSXP&& rhs)
  {
    return expression<
      XNDARR_STATIC_VECTOR_STSIG const &,
      op_div,
      decltype(std::forward<RHSXP>(rhs))>
      (*this, std::forward<RHSXP>(rhs));
  }

}; // class static_vector


#include "static_vector.cpp"
}; // namespace xn

#endif // __XNDARR_STATIC_VECTOR_HPP__
