//-//////////////////////////////////////////////////////////////////////////-//
// @file vecexpr.cpp
// @info Vector expression.
// @author Sayan Bhattacharjee
// @date 4-AUG-2019
//-//////////////////////////////////////////////////////////////////////////-//

template<typename LHS,typename OP, typename RHS>
xn::vecexpr<LHS,OP,RHS>
  ::vecexpr(const LHS& lhs_,const RHS& rhs_ )
  : lhs(lhs_), op(OP()), rhs(rhs_)
{

}


