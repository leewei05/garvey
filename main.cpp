#include <iostream>
#include <fstream>

int main(int argc, char **argv){
  if (argc > 0 && argv[1] == nullptr){
    std::cout << "Please enter filename.\n";
    return 1;
  }

  std::fstream fs;

  fs.open(argv[1], std::fstream::in);

  char c;
  while(fs.get(c))
    if (c != '\n'){
      std::cout << c;
    }

  fs.close();

  return 0;
}
