//-//////////////////////////////////////////////////////////////////////////-//
// @file vecexpr.cpp
// @info Vector expression.
// @author Sayan Bhattacharjee
// @date 4-AUG-2019
//-//////////////////////////////////////////////////////////////////////////-//

XNDARR_EXPRESSION_LTSIG
XNDARR_EXPRESSION_STSIG
  ::expression(LHS&& lhs,RHS&& rhs )
  : lhs_(std::forward<LHS>(lhs)),
    rhs_(std::forward<RHS>(rhs))
{

}


