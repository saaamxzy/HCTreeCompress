/* 
 * Name: Yunlu Huang
 * Student ID: A91008991
 * Partner name: Zhengyuan Xu
 * Student ID: A99076427
 */

#ifndef BITINPUTSTREAM_HPP 
#define BITINPUTSTREAM_HPP 

#include <iostream>

class BitInputStream {

private:
  int position;   //indicates the current bit position
  char buffer;    //the 1 byte buffer
  std::istream & in;   //the input stream

public:
  BitInputStream(std::istream & input) : in(input) {
    position = 8;   //set the initial position past the last bit
    buffer = 0;
  }

  //~BitInputStream(); 

  void fill();

  int readBit();

};

#endif
