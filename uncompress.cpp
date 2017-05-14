/*
 * Name: Yunlu Huang
 * Student ID: A91008991
 * Partner Name: Zhengyuan Xu
 * Partner ID: A99076427
 * Date: Aug 5, 2016
 */


#include "HCTree.hpp"
#include "BitInputStream.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

int getFreqs(vector<int>& freqs, ifstream& in);

int main(int argc, char * argv[])
{

  //the vector that holds each pattern's frequency
  vector<int> freqs = vector<int>(256, 0);
  
  if ( argc != 3 ) {
		cout << "Invalid number of arguments.\n" 
		     << "Usage: ./compress <encoded filename> <decoded filename>.\n";
		return -1;
	}

	//Open file 
	ifstream in;
	in.open(argv[1], ios::binary);

	//Check if input file was actually opened
	if(!in.is_open()) 
	{
		cout<< "Invalid input file. No file was opened. Please try again.\n";
		return -1;
	}

	//Check for empty file
	in.seekg(0, ios_base::end); 
	unsigned int len = in.tellg();
	if(len==0) 
	{
		cout << "The file is empty. \n";
		return -1;
	}

	//Resets the stream to beginning of file
	in.seekg(0, ios_base::beg); 

  //get the freqs from the header
  int totalBytes = getFreqs(freqs, in);
  //set the internal position past the header

  //build the HCTree from the freqs
  HCTree hct;
  hct.build( freqs );
  byte symbol;
  
  ofstream out;
  out.open(argv[2], ofstream::out);
  //BitInputStream for decoding
  BitInputStream bitIn(in);
  int i = 0;
  while (i<totalBytes) {
    // keep decoding untill expected number of bytes is reached
    symbol = hct.decode(bitIn);
    i++;
    out << symbol;
  }

  in.close();
  out.close();
  return 0;
}

int getFreqs(vector<int>& freqs, ifstream& in) {
  // get the frequencies from the compressed file header
  int totalBytes = 0;
  for(int i=0; i<256; i++) {
    char* buf = new char[3];
    //read 3 bytes from the file
    in.read(buf, 3);
    //initialize freq to 0
    freqs[i] = 0;
    for (int j=2; j>=0; j--) {
      freqs[i] <<= 8;
      // shift the bit to the left by 8 bits for next 8 bits
      freqs[i] |= (int)buf[j] & 0xFF;
      // combine previous bits with the ones in the buffer
    }
    delete[] buf;
    // delete the pointer created
    totalBytes += freqs[i];
  }
  //get the total bytes
  return totalBytes; 
}
