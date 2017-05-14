/* 
 * Name: Yunlu Huang
 * Student ID: A91008991
 * Partner name: Zhengyuan Xu
 * Student ID: A99076427
 */


#include "HCTree.hpp"
#include "HCNode.hpp"

using namespace std;

HCTree::~HCTree() {
  // destructor
  deleteAll(root);
  root = 0;
  leaves.clear();
  return;
}

void HCTree::build(const vector<int>& freqs) {
  // create a priority queue
  priority_queue<HCNode*, vector<HCNode*>, HCNodePtrComp> q;
  // build vector leaves and the priority queue
  for (int i=0; i<256; i++ ) {
    // create HCNode which represents the byte pattern
    // only needs those whose counts are non-zero
    if (freqs[i] != 0) {
      leaves[i] = new HCNode(freqs[i], i, 0, 0, 0); 
      q.push(leaves[i]);
    }
  } 
  
  
  // connect the forest of trees together
  while (q.size() != 1) {
    // get the two least freq nodes
    HCNode* L0 = q.top(); 
    q.pop();
    HCNode* L1 = q.top();
    q.pop();
    // build a tree whose c0 is L0 and c1 is L1, the root uses c0's symbol
    root = new HCNode((L0->count + L1->count), L0->symbol, L0, L1, 0);
    // update L0 and L1's parent
    L0->p = root;
    L1->p = root; 
    // push back the new tree to the queue
    q.push(root);
  }
}

/* void HCTree::encode(byte symbol, BitOutputStream& out) const { 
  // for final submission only
}
*/

void HCTree::encode(byte symbol, BitOutputStream& out) const {
  stack<int> code;
  //cout<<"symbol: "<<symbol<<"; code is";
  HCNode* cur = leaves[symbol];
  while ( cur->p ) {
    if (cur == cur->p->c0) {
      code.push(0);
    } else {
       code.push(1);
    }
    cur = cur->p;
  }
  while (code.size() != 0) {
    out.writeBit(code.top());
    //cout<<code.top();
    code.pop();
  }
  //cout<<endl;
}

/* void HCTree::decode(BitInputStream& in) const {
  // for final submission only
}
*/
int HCTree::decode(BitInputStream& in) const { 
  int code;
  // set the current node to the root
  HCNode* cur = root;
  // while the leaves are not reached, continue searching
  while (cur->c0) {
    // get the next code bit
    code = in.readBit();
    // if it is 1, goes to c1
    if (code) { 
      cur = cur->c1;
    } else {
      cur = cur->c0;
    }
  }
  return cur->symbol;
} 

void HCTree::deleteAll(HCNode* n) {
  if (n == 0) return;
  deleteAll(n->c0);
  deleteAll(n->c1);
  delete n;
  n = 0;
}

