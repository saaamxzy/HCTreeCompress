/* 
 * Name: Yunlu Huang
 * Student ID: A91008991
 * Partner name: Zhengyuan Xu
 * Student ID: A99076427
 */

#ifndef BITOUTPUTSTREAM_HPP
#define BITOUTPUTSTREAM_HPP

#include <iostream>

class BitOutputStream {

private:
  char buffer;  // to temporarily stores the data to output
  int position; // indicates the current bit position
  std::ostream & out;

public:
  //constructor
  BitOutputStream(std::ostream & output): out(output) {
    position = 0; // initially at the first bit
    buffer = 0;
  }

  void flush();

  void writeBit(int bit);
  
  int getPosition();

};

#endif
