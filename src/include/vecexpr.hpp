//-//////////////////////////////////////////////////////////////////////////-//
// @file vecexpr.hpp
// @info Vector expression.
// @author Sayan Bhattacharjee
// @date 4-AUG-2019
//-//////////////////////////////////////////////////////////////////////////-//
#pragma once
#ifndef __XNDARR_VECEXPR_HPP__
#define __XNDARR_VECEXPR_HPP__

#include <utility>
#include "operations.hpp"

namespace xn{

template<typename LHS, typename OP, typename RHS>
class vecexpr
{
  /// Left hand side of the expression
  const LHS& lhs_;

  /// Right hand side of the expression
  const RHS& rhs_;

  public:
  /// Constructor
  vecexpr(const LHS& ,const RHS&);
  auto eval() {return OP::eval(lhs_,rhs_);}

  template<typename RE>
  auto operator+(RE&& other) const -> decltype(auto)
  {
    return vecexpr< vecexpr<LHS,OP,RHS>,OP,decltype(std::forward<RE>(other))>
      (*this, std::forward<RE>(other));
  }

};
};

#include "vecexpr.cpp"

#endif
