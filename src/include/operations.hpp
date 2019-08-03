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
template<typename T>
struct op_add
{
  T static eval(const T& lhs, const T& rhs){
    return lhs + rhs;
  }
};

/// Subtaraction operation functor
template<typename T>
struct op_sub
{
  T static eval(const T& lhs, const T& rhs){
    return lhs - rhs;
  }
};


/// Division operation functor
template<typename T>
struct op_div
{
  T static eval(const T& lhs, const T& rhs){
    return lhs / rhs;
  }
};


/// Multiplication operation functor
template<typename T>
struct op_mul
{
  T static eval(const T& lhs, const T& rhs){
    return lhs * rhs;
  }
};

/// Modulus operation functor
template<typename T>
struct op_mod
{
  T static eval(const T& lhs, const T& rhs){
    return lhs % rhs;
  }
};


};
#endif
