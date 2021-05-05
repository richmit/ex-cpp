// -*- Mode:C++; Coding:us-ascii-unix; fill-column:132 -*-
/**********************************************************************************************************************************/
/**
   @file      random11.cpp
   @author    Mitch Richling <https://www.mitchr.me>
   @Copyright Copyright 2009,2014 by Mitch Richling.  All rights reserved.
   @Revision  $Revision: 1.1 $ 
   @SCMdate   $Date: 2014/08/24 18:28:28 $
   @brief     Minimal example of the great random number features of CPP+11.@EOL
   @Keywords  cpp random number
   @Std       C++11

              The new C++11 stuff seems to be based on the BOOST library, so this example is a reworking of an older BOOST example.
              
***********************************************************************************************************************************/

//----------------------------------------------------------------------------------------------------------------------------------
#include <iostream>                                                      /* C++ iostream            C++11    */
#include <random>                                                        /* C++ random numbers      C++11    */
 
//----------------------------------------------------------------------------------------------------------------------------------
int main() {

  //--------------------------------------------------------------------------------------------------------------------------------
  // Set seed using the random_device
  std::random_device rd;

  //--------------------------------------------------------------------------------------------------------------------------------
  // Create a "Random Engine"

  // Use the 32-bit Mersenne Twister seeded with rd() -- could seed with an integer.
  std::mt19937 rEng(rd());

  // The Standard Library has several, but I tend to use the following four:
  //  *  minstd_rand0 	MSG Park & Miller circa 1988 -- an LCG, but you know what to expect!
  //  *  minstd_rand 	MSG Park & Miller & Stockmeyer circa 1993 -- an LCG, but you know what to expect!
  //  *  mt19937 	    32-bit Mersenne Twister (Matsumoto & Nishimura circa 1998).  This is a good one!
  //  *  mt19937_64     64-bit Mersenne Twister (Matsumoto & Nishimura circa 2000).  This is a good one!

  //--------------------------------------------------------------------------------------------------------------------------------
  // Create a our "random variables"

  // Discrete uniform random variable on {1, 2, 3, 4, 5, 6}
  std::uniform_int_distribution<int> uniform_dist_int(1, 6);

  // Continuous (or as continuous as floating point can be) uniform random variable on [1, 6).
  std::uniform_real_distribution<double> uniform_dist_float(1.0, 2.0);

  // Here are the ones I use most:
  //  * uniform_int_distribution
  //  * generate_canonical ................... like uniform_real_distribution on [0, 1)
  //  * uniform_real_distribution
  //  * normal_distribution
  //  * binomial_distribution
  //  * geometric_distribution
  //  * negative_binomial_distribution
  //  * poisson_distribution
  //  * bernoulli_distribution
  //  * exponential_distribution
  //  * gamma_distribution
  //  * chi_squared_distribution
  //  * fisher_f_distribution
  //  * student_t_distribution
  //  * cauchy_distribution
  //  * lognormal_distribution
  //  * weibull_distribution
  //  * extreme_value_distribution

  //--------------------------------------------------------------------------------------------------------------------------------
  // Generate some random numbers from our distributions

  // First the discrete case
  std::cout << "Random Integers: ";
  for (int n = 0; n < 10; ++n)
    std::cout << uniform_dist_int(rEng) << " ";
  std::cout << std::endl;

  // Second the continuous case
  std::cout << "Random Doubles: ";
  for (int n = 0; n < 10; ++n)
    std::cout << uniform_dist_float(rEng) << " ";
  std::cout << std::endl;

} /* End func main */
