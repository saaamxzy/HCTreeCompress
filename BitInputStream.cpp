/*
 * Filename: BitInputStream.hpp
 * Description: BitInputStream class is inheritated from istream, and it
 *              reads files bit by bit
 * Name: Yunlu Huang
 * Student ID: A91008991
 * Partner name: Zhengyuan Xu
 * Student ID: A99076427
 */


#include "BitInputStream.hpp"

  
/*
 * This method fills the buffer
 */
void BitInputStream::fill() {
  buffer = (unsigned char) in.get();
  position = 0;
}

/*
 * This method read next bit
 */
int BitInputStream::readBit() {
  // check if all bits has been read
  // if so, fill the buffer
  if (position == 8) {
    fill();
  }
  // copy the buffer bytes
  char bits = buffer;
  // right shift the bits by position
  bits >>= (7-position);
  // perform and operation to the bits with
  bits = bits & 1;
  // inc the position
  position++;
  // return the remaining bits
  if (bits) {
    return 1;
  } else {
    return 0;
  }
  
}
