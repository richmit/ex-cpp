// -*- Mode:C++; Coding:us-ascii-unix; fill-column:132 -*-
/**********************************************************************************************************************************/
/**
   @file      thread05_pool.cpp
   @author    Mitch Richling <https://www.mitchr.me>
   @Copyright Copyright 2014 by Mitch Richling.  All rights reserved.
   @brief     Demonstrate how one might manage many threads (like a pool)@EOL
   @Keywords  none
   @Std       C++11              
***********************************************************************************************************************************/

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>                                                      /* C++ iostream            C++11    */
#include <vector>                                                        /* STL vector              C++11    */ 
#include <thread>                                                        /* threads                 C++11    */
#include <mutex>                                                         /* Mutexes                 C++11    */

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// A mutex to protect STDOUT.
std::mutex stdout_mutex;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// This little function will be what our thread calls
void workerThread(int ourThreadID) {
  std::lock_guard<std::mutex> stdout_guard(stdout_mutex);
  std::cout << "Hello from thread " << std::this_thread::get_id() << "(" << ourThreadID << ")" << std::endl;
} // end func workerThread

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() {
  const int numberOfThreads = 10;
  std::vector<std::thread> someThreads;

  // Construct and launch our threads
  for (int i=0; i<numberOfThreads; ++i) {
    {
      std::lock_guard<std::mutex> stdout_guard(stdout_mutex);
      std::cout << "Launching thread " << i << std::endl;
    } // end scope

    someThreads.push_back(std::thread(workerThread, i));
  } // end for

  // Join to each thread so that main will wait for them all to finish
  for(auto& aThread : someThreads) {
    aThread.join();
  } // end for

  std::cout << "DONE!" << std::endl;

  return 0;
} // end func main
