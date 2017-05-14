/* 
 * Name: Yunlu Huang
 * Student ID: A91008991
 * Partner name: Zhengyuan Xu
 * Student ID: A99076427
 */

#include "HCNode.hpp"


bool comp(HCNode* one, HCNode* other) {
  return *one < *other;
}
bool HCNode::operator<(HCNode const & other) const {

  if(count != other.count) return count > other.count;
// counts are equal. use symbol value to break tie.
// (for this to work, internal HCNodes
// must have symb set.)
  return symbol < other.symbol;
};
