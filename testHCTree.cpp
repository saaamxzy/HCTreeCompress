
#include "HCTree.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>


using namespace std;

int main(int argc, char * argv[])
{
  // test to construct the trees
  //

  HCTree* t1 = new HCTree();
  t1->isRootEmpty();

  // test for HCNodes

  HCNode* n1 = new HCNode(5, 'a');

  HCNode* n2 = new HCNode(10, 65);
  
  HCNode* n3 = new HCNode(15, 66);

  HCNode* n4 = new HCNode(20, 'b');

  cout << n1->count << ", " << n1->symbol << endl;
  // should be 5, a
  cout << n2->count << ", " << n2->symbol << endl;
  // 10, A
  cout << n3->count << ", " << n3->symbol << endl;
  // 15, B
  cout << n4->count << ", " << n4->symbol << endl;
  // 20, b
  //

  if ( (*n1) < (*n2) ) {
    cout << "n1 < n2, which is incorrect" << endl; 
  }

  if ( (*n4) < (*n3) ) {
    cout << "n4 < n3, which is correct" << endl;
  }


}
