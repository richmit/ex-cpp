#include <fstream>
#include <iostream>
#include <string>
#include <filesystem>
namespace fs = std::filesystem;

int main()
{

  fs::path daPathRel {"../../learn"};
  fs::path daPathAbs = fs::canonical(daPathRel);
  std::cout << daPathRel << " = " << daPathAbs << ": ";
  
  unsigned long numDir = 0, numLink = 0, numFile = 0, numUnk = 0, numErr = 0, sizFile = 0;
  for(auto& p: fs::recursive_directory_iterator(daPathAbs)) {  // Note: recursive_directory_iterator can take a string (c or c++) instead of a path
    if(p.exists()) {
      if(p.is_directory()) {
        numDir++;
      } else if(p.is_symlink()) {
        numLink++;
      } else if(p.is_regular_file()) {
        numFile++;
        sizFile += p.file_size();
      } else {
        numUnk++;
      }
    } else {
      numErr++;
    }
  }
  std::cout << "DIR: " << numDir << " SYM: " << numLink << " REG: " << numFile << " UNK: " << numUnk << " ERR: " << numErr << " Size: " << sizFile << std::endl;
}
