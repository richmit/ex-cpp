// -*- Mode:C++; Coding:us-ascii-unix; fill-column:132 -*-
/**********************************************************************************************************************************/
/**
   @file      for11.cpp
   @author    Mitch Richling <https://www.mitchr.me>
   @Copyright Copyright 2013 by Mitch Richling.  All rights reserved.
   @brief     C++11 for loop example.@EOL
   @Keywords  for C++
   @Std       C++11

   Demonstrate the new C++11 for loop.  This construct is much like the foreach loop in Perl and the for loop in bash.  While not
   quite the same as the internal iterators of Ruby and lisp, this syntax helps to avoid the cumbersome syntax of external iterator
   construction and manipulation.
***********************************************************************************************************************************/

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>                                                      /* C++ iostream            C++11    */

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() {

  // Array
  int anIntArr[] = {0,1,2,3,4,5,6,7};  /* Do not need size */

  // We can travarse the array by value like so.
  std::cout << "The list: " << std::endl;
  for(auto x : anIntArr) 
    std::cout << x << " ";
  std::cout << std::endl;

  // We can travarse the array by refrence like so.
  for(auto &x : anIntArr) 
    x = x * 2;
  std::cout << "The new list: " << std::endl;
  for(auto x : anIntArr) 
    std::cout << x << " ";
  std::cout << std::endl;

} /* end func main */




