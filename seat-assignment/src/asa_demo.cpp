#include <asa.hpp>

#include <iostream>
#include <string>
#include <cstdlib>

int main(int argc, char *argv[])
{
  std::string filename, buf;
  int row = 0, col = 0;

  if(argc == 1) // if no cl-argument is given than set to 10 lines
  {
    std::cerr << "ERROR: No filename given!\n";
    exit(EXIT_FAILURE);
  }
  else
  {
    if(argc > 2) // if too many command line arguments given exit the program
    {
      std::cerr << "ERROR: Too many command line arguments given! Only give one filename!\n";
      exit(EXIT_FAILURE);
    }
    else // normal input
    {
      filename = argv[1];
      row = 6;
      col = 8;
      //row = std::stoi(argv[2]);
      //col = std::stoi(argv[3]);
    }
  }

  buf = asa(filename, row, col); // compute pascals triangle

  std::cout << buf; // output the result

  return 0;
}
