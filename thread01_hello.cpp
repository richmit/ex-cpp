// -*- Mode:C++; Coding:us-ascii-unix; fill-column:132 -*-
/**********************************************************************************************************************************/
/**
   @file      thread01_hello.cpp
   @author    Mitch Richling <https://www.mitchr.me>
   @Copyright Copyright 2012 by Mitch Richling.  All rights reserved.
   @brief     Hello World for C++11 threads.@EOL
   @Keywords  none
   @Std       C++11
***********************************************************************************************************************************/

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>                                                      /* C++ iostream            C++11    */
#include <thread>                                                        /* threads                 C++11    */

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// This little function will be what our thread calls
void workerThread() {
  std::cout << "Hello from thread!" << std::endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() {
  std::cout << "Hello from main!" << std::endl;

  // Construct thread (which will launch workerThread in a new thread)
  std::thread aThread(workerThread);

  // We "Join" with thread aThread so that the main thread will wait for aThread to finish.
  aThread.join();

  std::cout << "DONE!" << std::endl;

  return 0;

} // end func main
