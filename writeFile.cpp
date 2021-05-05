#include <iostream>                                                      /* C++ iostream            C++11    */
#include <fstream>                                                       /* C++ fstream             C++98    */

int main () {
  std::ofstream outputFile ("aFileName.txt");

  if (outputFile.good() && outputFile.is_open()) {
    outputFile << "Line 1\n";
    outputFile << "Line 2\n";
    outputFile.close();
  } else
    std::cout << "ERROR: Could not open file!!!";
  return 0;
}
