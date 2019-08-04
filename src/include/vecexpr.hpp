//-//////////////////////////////////////////////////////////////////////////-//
// @file vecexpr.hpp
// @info Vector expression.
// @author Sayan Bhattacharjee
// @date 4-AUG-2019
//-//////////////////////////////////////////////////////////////////////////-//
#pragma once
#ifndef __XNDARR_VECEXPR_HPP__
#define __XNDARR_VECEXPR_HPP__

#include "operations.hpp"

namespace xn{

template<typename LHS, typename OP, typename RHS>
class vecexpr
{
  /// Left hand side of the expression
  const LHS& lhs;

  /// Right hand side of the expression
  const RHS& rhs;

  public:
  /// Constructor
  vecexpr(const LHS& ,const RHS&);
  auto eval() {return OP::eval(lhs,rhs);}



};
};

#include "vecexpr.cpp"

#endif
