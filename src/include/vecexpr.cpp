//-//////////////////////////////////////////////////////////////////////////-//
// @file vecexpr.cpp
// @info Vector expression.
// @author Sayan Bhattacharjee
// @date 4-AUG-2019
//-//////////////////////////////////////////////////////////////////////////-//

// Constructor
XNDARR_EXPRESSION_LTSIG
XNDARR_EXPRESSION_STSIG
  ::expression(LHS lhs,RHS rhs )
  : lhs_(std::forward<LHS>(lhs)),
    rhs_(std::forward<RHS>(rhs))
{

}

// Copy constructor
XNDARR_EXPRESSION_LTSIG
XNDARR_EXPRESSION_STSIG
  ::expression(XNDARR_EXPRESSION_STSIG & other)
{
  lhs_ = other.lhs_;
  rhs_ = other.rhs_;
}

// Move constructor
XNDARR_EXPRESSION_LTSIG
XNDARR_EXPRESSION_STSIG
  ::expression(XNDARR_EXPRESSION_STSIG && other)
  : lhs_(std::forward<decltype(other.lhs_)>(other.lhs_)),
    rhs_(std::forward<decltype(other.rhs_)>(other.rhs_))
{
}

