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

/// Long template signature for class expression
#define XNDARR_EXPRESSION_LTSIG \
  template<typename LHS, typename OP, typename RHS>

/// Short template signature for class expression
#define XNDARR_EXPRESSION_STSIG \
  expression<LHS,OP,RHS>

XNDARR_EXPRESSION_LTSIG
class expression
{
  /// Left hand side of the expression
  const LHS& lhs_;

  /// Right hand side of the expression
  const RHS& rhs_;

  public:
  /// Constructor
  expression(const LHS& ,const RHS&);

  };
};

#include "vecexpr.cpp"

#endif
