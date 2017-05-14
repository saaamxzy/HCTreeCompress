/*
 * Name: Yunlu Huang
 * Student ID: A91008991
 * Partner Name: Zhengyuan Xu
 * Partner ID: A99076427
 * Date: Aug 5, 2016
 */


#include "HCTree.hpp"
#include "BitOutputStream.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

void createHeader(vector<int>& headInfo, ofstream& headerOut);

int main(int argc, char * argv[])
{
  //create a vector to store the freqs for 256 byte patterns
  vector<int> freqs = vector<int>(256, 0);
  
  //check if the program is called correctly
  if ( argc != 3 ) {
		cout << "Invalid number of arguments.\n" 
		     << "Usage: ./compress <input filename> <output filename>.\n";
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

  char x; // used to store the byte read
  
  while (in.get(x)) {
    // keeps reading until eof is reached
    // increment the count in the frequency vector
    if (!in.eof())
      
      freqs[(int)(unsigned char)x]++;
  }
  // close the file
  in.close();
  // the out file to write to
  ofstream out;
  // BitOutputStream
  BitOutputStream bitOut(out);
  // open the file to write
  out.open(argv[2], ofstream::out);
  // construct the tree
  HCTree hct;
  hct.build( freqs );
  
  //create the header
  createHeader(freqs, out);

  // reopen the file to read again 
  in.open(argv[1], ios::binary);
  
  // keeps reading until there is no more to read
  while (in.get(x)) {
    // encode and write the code to out file
    if (!in.eof())
      hct.encode(x, bitOut);
  }
  if(bitOut.getPosition()!=8) {
    bitOut.flush();
  }

  // close the out file 
  out.close();
  
}

void createHeader(vector<int>& headInfo, ofstream& headerOut) {
  // note down the header for the encoded file
  for (int i=0; i<256; i++) {
    int count = headInfo[i];
    // only uses 3 bytes to cover from 0 - 10 million
    headerOut.write((char*)&count, 3);
  }
}
