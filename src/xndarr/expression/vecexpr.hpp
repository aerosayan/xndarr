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
#include "../common.hpp"
#include "operations.hpp"

namespace xn{

/// Long template signature for class expression
#define XNDARR_EXPRESSION_LTSIG \
  template<typename LHS, typename OP, typename RHS>

/// Short template signature for class expression
#define XNDARR_EXPRESSION_STSIG \
  expression<LHS,OP,RHS>

//-//////////////////////////////////////////////////////////////////////////-//
/// Expression template class
//-//////////////////////////////////////////////////////////////////////////-//
/// LHS : Left Hand Side Value
/// RHS : Right Hand Side Value
/// OP  : Operation to be applied to LHS and RHS
//-//////////////////////////////////////////////////////////////////////////-//
template<typename LHS, typename OP, typename RHS>
class expression
{
  private:
  /// Left hand side of the expression
  LHS lhs_;

  /// Right hand side of the expression
  RHS rhs_;


  public:
  /// Constructor
  expression(LHS ,RHS);
  /// Copy constructor
  expression(XNDARR_EXPRESSION_STSIG &);
  /// Move constructor
  expression(XNDARR_EXPRESSION_STSIG &&);
  /// Destructor
  ~expression(){}

  //-///////////////////////////////////////////////////////////////////////-//
  /// Overloading opeartors
  //-///////////////////////////////////////////////////////////////////////-//
  decltype(auto) operator[](szt i)
  {
    return OP::eval(lhs_[i], rhs_[i]);
  }

  template<typename RHSXP>
  decltype(auto) operator+(RHSXP&& rhs) const
  {
    return expression<
      expression<LHS,OP,RHS> const&,
      op_add,
      decltype(std::forward<RHSXP>(rhs))>
      (*this, std::forward<RHSXP>(rhs));
  }

  template<typename RHSXP>
  decltype(auto) operator-(RHSXP&& rhs) const
  {
    return expression<
      expression<LHS,OP,RHS> const&,
      op_sub,
      decltype(std::forward<RHSXP>(rhs))>
      (*this, std::forward<RHSXP>(rhs));
  }

  template<typename RHSXP>
  decltype(auto) operator*(RHSXP&& rhs) const
  {
    return expression<
      expression<LHS,OP,RHS> const&,
      op_mul,
      decltype(std::forward<RHSXP>(rhs))>
      (*this, std::forward<RHSXP>(rhs));
  }

  template<typename RHSXP>
  decltype(auto) operator/(RHSXP&& rhs) const
  {
    return expression<
      expression<LHS,OP,RHS> const&,
      op_div,
      decltype(std::forward<RHSXP>(rhs))>
      (*this, std::forward<RHSXP>(rhs));
  }
}; // end class expression

#include "vecexpr.cpp"
}; // end namespace


#endif
