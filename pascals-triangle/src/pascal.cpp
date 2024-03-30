#include <iostream> // use cin and cout
#include <iomanip>  // use stew() ... specifies tke width of the display field 
                    //                 for the next element in the stream
#include <string>  
#include <sstream>  // stringstream is used because with that the triangle can be easily built
#include <cstdlib>  // used for abs()

// Prototypes
int faq(int number);
int calcBinomCoef(int n, int j);

std::string pascal(int numrows)
{
  std::stringstream buffer;
  int i = 0, j = 0, k = 0; 

  numrows = abs(numrows); // ensure line numbers are positive
  if(numrows > 10)        // limit line numbers to 10
  {
    numrows = 10;
  }
  
  buffer << "\n";

  for(i = 0; i < numrows; i++)
  {
    for(j = 0; j < numrows - i - 1; j++) // spacescounter for leading spaces starting 0 so - 1
    {
      buffer << "  ";
    }

    for (k = 0; k <= i; k++)
    {
      if (calcBinomCoef(i, k) >= 10)
      {
        buffer << std::setw(4) << std::right << calcBinomCoef(i, k); // increase distance at 1 on 2-digit numbers
      }
      else
      {
        buffer << "   " << calcBinomCoef(i, k); // write 3 spaces on 1-digit numbers
      }
    }

    buffer << "\n"; // add newline
  }

  return buffer.str(); // stringstream to string
}

// calculate fractals
int faq(int number)
{
  int res = number;

  for (int i = number; i > 1; i--)
  {
    res *= (i - 1);
  }

  return res;
}

// calculate the Binominal Coefficent
int calcBinomCoef(int n, int j)
{
  int result;

  if (j == 0) // if j = 0 than the BinomCoef is 1
  {
    result = 1;
  }
  else if (j == n) // if j = n than the BinomCoef is 1
  {
    result = 1;
  }
  else
  {
    result = faq(n) / (faq(j) * faq(n - j)); // else use the equation to calculate the BinomCoef
  }

  return result;
}
