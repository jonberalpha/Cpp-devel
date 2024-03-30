#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <asa.hpp>

#define TESTFILE1 "student_list.csv"
#define row 6
#define col 8

const std::string  str_9_6x8 =
  "Luke;Baxley;0;0\n"
  "Marnie;Lemmons;0;2\n"
  "Anne;Scott;0;4\n"
  "Lucy;Blakeslee;0;6\n"
  "Chelsea;Vlassman;1;0\n"
  "Kelly;Hudson;1;2\n"
  "Todd;Robertson;1;4\n"
  "Kirk;Mitchell;1;6\n"
  "Suzanne;Dunn;2;0\n";

SCENARIO("Automatic Seat Assignment Specification")
{
  GIVEN("A negative row number")
  {
    WHEN("the number is -6")
    {
      std::string result = asa(TESTFILE1, -row, col);

      THEN("the result is: failed")
      {
        REQUIRE(result == "failed\n");
      }
    }
  }

  GIVEN("A negative column number")
  {
    WHEN("the number is -8")
    {
      std::string result = asa(TESTFILE1, row, -col);

      THEN("the result is: failed")
      {
        REQUIRE(result == "failed\n");
      }
    }
  }

  GIVEN("A non-existing file")
  {
    WHEN("the filename is e.g. aabbcc.csv")
    {
      std::string result = asa("aabbcc.csv", row, col);

      THEN("the result is: failed")
      {
        REQUIRE(result == "failed\n");
      }
    }
  }

  GIVEN("9 students")
  {
    WHEN
    (
      "rows are " + std::to_string(row) + 
      " and column are " + std::to_string(col) + 
      " => " + std::to_string(row*col)  + " seats"
    )
    {
      std::string result = asa(TESTFILE1, row, col);

      THEN("the result is: " + str_9_6x8)
      {
        REQUIRE(result == str_9_6x8);
      }
    }
  }
}
