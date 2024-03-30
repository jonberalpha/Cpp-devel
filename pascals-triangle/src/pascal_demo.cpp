#include <pascal.hpp>

#include <iostream>
#include <cstdlib>

int main(int argc, char *argv[])
{
  int numrows = 0; // row number as global variable
  std::string buf;

  if(argc == 1) // if no cl-argument is given than set to 10 lines
  {
   numrows = 10;
  }
  else
  {
    if(argc == 2) // if one cl-argument is given than convert it to number using stoi
    {
     numrows = abs(std::stoi(argv[1]));
      if(( numrows > 10) ||  (numrows <= 0)) // limit given line number between 1 and 10; on error set to 10
      {
        std::cerr << "ERROR: Number must be between 1 and 10!" << std::endl;
        exit(EXIT_FAILURE);
      }
    }
    else
    {
      if(argc > 2) // if too many command line arguments given exit the program
      {
        std::cerr << "ERROR: Too many command line arguments given! Only use ONE number between 1 and 10!" << std::endl;
        exit(EXIT_FAILURE);
      }
    }
  }

  buf = pascal(numrows); // compute pascals triangle
  std::cout << buf;      // cout the returned string

  return 0;
}
