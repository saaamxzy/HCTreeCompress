/* 
 * Name: Yunlu Huang
 * Student ID: A91008991
 * Partner name: Zhengyuan Xu
 * Student ID: A99076427
 */

#include "BitOutputStream.hpp"

using namespace std;

void BitOutputStream::flush() {
  out.put(buffer);
  out.flush();
  buffer = 0;
  position = 0;
}

void BitOutputStream::writeBit(int bit) {
  // left shift the bit to the position
  bit <<= (7-position);
  // bitwise or to write the bit to the buffer
  buffer = buffer | bit;
  position++;
  //check if the buffer is full, if so, flush it
  if (position == 8) {
    flush();
  }
}

int BitOutputStream::getPosition(){
  return position;
}

