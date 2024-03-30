#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <pascal.hpp>

SCENARIO("Pascals Triangle Specification")
{
  GIVEN("A negative number")
  {
    int const number = GENERATE(-2, 2);

    WHEN("the number is -2")
    {
      auto const result = pascal(number);

      THEN("the result is 2 lines of pascals triangle")
      {
        REQUIRE(result == "\n     1\n   1   1\n");
      }
    }
  }

  GIVEN("Neither negative nor positive number")
  {
    WHEN("the number is 0")
    {
      auto const result = pascal(0);

      THEN("the result is \\n, so a new line gets inserted")
      {
        REQUIRE(result == "\n");
      }
    }
  }

  GIVEN("A large positive number")
  {
    WHEN("the number is 100")
    {
      std::string str10lines = "\n                     1\n                   1   1\n                 1   2   1\n               1   3   3   1\n             1   4   6   4   1\n           1   5  10  10   5   1\n         1   6  15  20  15   6   1\n       1   7  21  35  35  21   7   1\n     1   8  28  56  70  56  28   8   1\n   1   9  36  84 126 126  84  36   9   1\n";
      auto const result = pascal(100);

      THEN("the result is 10 lines of pascals triangle")
      {
        REQUIRE(result == str10lines);
      }
    }
  }

  GIVEN("Line numbers between 1 and 10")
  {
    // Create Test-Number-Array and Reference-Result-Array
    int const number[] = {1, 3, 5, 10};
    std::string refstr[] = 
    {
      "\n   1\n", 
      "\n       1\n     1   1\n   1   2   1\n", 
      "\n           1\n         1   1\n       1   2   1\n     1   3   3   1\n   1   4   6   4   1\n", 
      "\n                     1\n                   1   1\n                 1   2   1\n               1   3   3   1\n             1   4   6   4   1\n           1   5  10  10   5   1\n         1   6  15  20  15   6   1\n       1   7  21  35  35  21   7   1\n     1   8  28  56  70  56  28   8   1\n   1   9  36  84 126 126  84  36   9   1\n"
    };

    const int ARRAYSIZE = sizeof(number)/sizeof(number[0]); // compute array size

    for(int i = 0; i < ARRAYSIZE; i++) // loop through the Test-Number-Array which creates dynamically test cases according to array size
    {
      WHEN("the line number is " + std::to_string(number[i]))
      {
        const std::string result = pascal(number[i]);

        THEN("the corresponding pascals triangle has " + std::to_string(number[i]) + " line(s)")
        {
          REQUIRE(result == refstr[i]);
        }
      }
    }
  }
}
