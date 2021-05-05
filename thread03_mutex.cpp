// -*- Mode:C++; Coding:us-ascii-unix; fill-column:132 -*-
/**********************************************************************************************************************************/
/**
   @file      thread03_mutex.cpp
   @author    Mitch Richling <https://www.mitchr.me>
   @Copyright Copyright 2012 by Mitch Richling.  All rights reserved.
   @brief     Demo C++11 mutexes with old school-style syntax.@EOL
   @Keywords  none
   @Std       C++11
***********************************************************************************************************************************/

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>                                                      /* C++ iostream            C++11    */
#include <thread>                                                        /* threads                 C++11    */
#include <mutex>                                                         /* Mutexes                 C++11    */
 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// This is a mutex that will protect std::cout (STDOUT in C-lingo).  In C++11 we are only guaranteed that writes to cout will be
// "safe" at a byte level, not that entire writes will be atomic.  So we need to protect STDOUT if we want to guarantee that our
// output will be human readable.
std::mutex stdout_mutex;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// This little function will be called by a thread. It locks the stdout_mutex using explicit lock/unlock code very much like the raw
// POSIX APIs.  The technique used by workerThread1 is very C-like -- see workerThread2 for a more C++ way of doing things.
void workerThread1() {
  stdout_mutex.lock();
  std::cout << "Hello from workerThread1! Our thread ID is: " << std::this_thread::get_id() << std::endl;
  stdout_mutex.unlock();
} // end func workerThread1

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// This little function will be called by a thread.  It works just like workerThread1, but uses a RAII approach that seems more
// natural for a C++ programmer.
void workerThread2() {
  std::lock_guard<std::mutex> stdout_guard(stdout_mutex);
  std::cout << "Hello from workerThread2! Our thread ID is: " << std::this_thread::get_id() << std::endl;
} // end func workerThread2

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()  {

  // Construct and launch our threads
  std::thread thread1(workerThread1);
  std::thread thread2(workerThread2);

  { // We need to lock here because we potentially have three threads in flight that want to write to stdout -- workerThread1,
    // workerThread2, and main.
    std::lock_guard<std::mutex> stdout_guard(stdout_mutex);
    std::cout << "Hello from main!          Our thread ID is: " << std::this_thread::get_id() << std::endl;
  } // end scope

  // Join to each thread so that main will wait for them all to finish
  thread1.join();
  thread2.join();

  // No need to lock here because we only have one thread in flight, main, because we used .join on thread1 & thread2 above.
  std::cout << "DONE!" << std::endl;
} // end func main
