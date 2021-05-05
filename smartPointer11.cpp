// -*- Mode:C++; Coding:us-ascii-unix; fill-column:132 -*-
/**********************************************************************************************************************************/
/**
   @file      unique_ptr11.cpp
   @author    Mitch Richling <https://www.mitchr.me/>
   @Copyright Copyright 2000,2013,2014 by Mitch Richling.  All rights reserved.
   @brief     Example of some C++11 goodness for STL vectors.@EOL
   @Keywords  Standard C++11 STL unique_ptr
   @Std       C++11
***********************************************************************************************************************************/

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <memory>
#include <string>
#include <iostream>                                                      /* C++ iostream            C++11    */
#include <algorithm>                                                     /* STL algorithm           C++11    */

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() {
  // You can now initialize a vector with a list
  std::unique_ptr<std::string> aString(new std::string("hi"));

  std::cout << "The string: " << (*aString) << std::endl;

  // Note we don't delete aString...

  //aString = new std::string("bye");

  // Note we don't delete aString...

} // end main
