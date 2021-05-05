// -*- Mode:C++; Coding:us-ascii-unix; fill-column:132 -*-
/**********************************************************************************************************************************/
/**
   @file      readAllFile.cpp
   @author    Mitch Richling <https://www.mitchr.me>
   @Copyright Copyright 1997,1998,2014 by Mitch Richling.  All rights reserved.
   @brief     Read an entire file into memory in one go.@EOL
   @Keywords  none
   @Std       C++98
***********************************************************************************************************************************/

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>                                                      /* C++ iostream            C++11    */
#include <fstream>                                                       /* C++ fstream             C++98    */

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main (int argc, char *argv[]) {
  if(argc>1) {
    std::ifstream is (argv[1], std::ifstream::binary | std::ios::ate | std::ios::in);
    if (is) {
      int fileLength = is.tellg();
      char * buffer = new char [fileLength];
    
      // read the whole thing into buffer
      is.seekg (0, is.beg);
      is.read (buffer,fileLength);

      // Figure out how much of file we got
      int bytesRead;
      if (is)
        bytesRead = fileLength;
      else
        bytesRead = is.gcount();
      std::cout << "Read " << bytesRead << " bytes" << std::endl;

      // All done with file.  Close the file.
      is.close();

      // Do something with buffer here...

      // Clean up our buffer now
      delete[] buffer;
    } else {
      std::cout << "ERROR: Unable to open file (" << argv[1] << ")" << std::endl;
    } // end if/else
  } else {
    std::cout << "ERROR: Missing argument!" << std::endl;
  } // end if/else

  return 0;
} // end func main
