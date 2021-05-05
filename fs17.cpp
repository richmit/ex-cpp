#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;
using namespace std;

int main()
{
  //fs::path aPath {"./path/to/file.txt"};
  //fs::path aPath {"/usr/bin/ls.exe"};
  //fs::path aPath {"C:\\msys64\\usr\\bin\\ls.exe"};
  fs::path aPath {"C:/msys64/usr/bin/ls.exe"};


  cout << "Parent path: " << aPath.parent_path() << endl;
  cout << "Filename: "    << aPath.filename() << endl;
  cout << "Extension: "   << aPath.extension() << endl;

  cout << "Exists: "      << fs::exists(aPath) << endl;

    
  return 0;
}
