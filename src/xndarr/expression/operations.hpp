//-//////////////////////////////////////////////////////////////////////////-//
// @file opeartions.hpp
// @info Expression operations
// @author Sayan Bhattacharjee
// @date 4-AUG-2019
//-//////////////////////////////////////////////////////////////////////////-//
#pragma once
#ifndef __XNDARR_OPEARTONS_HPP__
#define __XNDARR_OPEARTONS_HPP__

namespace xn {
//-//////////////////////////////////////////////////////////////////////////-//
// NOTE
// For most of the operations it is expected that same datatypes will be used
// together. For ex, it is expected that both lhs and rhs are of same type.
// If lhs and rhs aren't of same type then the operation is potentially risky.
//-//////////////////////////////////////////////////////////////////////////-//

/// Addition operation functor
struct op_add
{
  template<typename T>
  T static apply(const T& lhs, const T& rhs)
  {
    return lhs + rhs;
  }

  template<typename T, typename SIMD_ISET>
  decltype(auto) static apply(const SIMD_ISET& iset, const T& lhs, const T& rhs)
  {
  }

  template<typename T>
  decltype(auto) static apply(const xn::AVX2& iset, const T& lhs, const T& rhs)
  {
    return _mm256_add_ps(_mm256_loadu_ps(lhs), _mm256_loadu_ps(rhs));
  }
};

/// Subtaraction operation functor
struct op_sub
{
  template<typename T>
  T static apply(const T& lhs, const T& rhs)
  {
    return lhs - rhs;
  }
};


/// Division operation functor
struct op_div
{
  template<typename T>
  T static apply(const T& lhs, const T& rhs)
  {
    return lhs / rhs;
  }
};


/// Multiplication operation functor
struct op_mul
{
  template<typename T>
  T static apply(const T& lhs, const T& rhs)
  {
    return lhs * rhs;
  }
};

/// Modulus operation functor
struct op_mod
{
  template<typename T>
  T static apply(const T& lhs, const T& rhs)
  {
    return lhs % rhs;
  }
};


};
#endif
