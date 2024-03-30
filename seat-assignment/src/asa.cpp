#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>

/***************************************************************/
/*                     Type definitions                        */
/***************************************************************/
/**
 * Type Definition: t_student
 * Contains the definition of a student with firstname and lastname
 **/
struct t_student
{
  std::string firstname;
  std::string lastname;
};

/**
 * Type Definition: t_student
 * Contains the definition of a student with the full name,
 * row and column
 **/
struct t_seated_student
{
  t_student name;
  int row;
  int col;
};

/***************************************************************/
/*                         Prototypes                          */
/***************************************************************/
std::vector<t_student> getStudentsFromCSV(std::string filename);
std::vector<t_seated_student> seatStudents(std::vector<t_student> &studentlist, int row, int col);
std::string outputSeatedStudentsInCSV(std::vector<t_seated_student> &studentlist);

/***************************************************************/
/*                     asa - subroutine                        */
/***************************************************************/
std::string asa(std::string filename, int row, int col)
{
  std::vector<t_student> studentlist;
  std::vector<t_seated_student> seatedstudents;
  std::string ret;

  if((row > 0) && (col > 0)) // check for negative row or column number
  {
    studentlist = getStudentsFromCSV(filename); // get students from csv-file and store it in a vector
    if((studentlist.size() > 0) && (studentlist.size() <= ((row * col) / 2))) // check for amount of students between zero and seat-amount
    {
      seatedstudents = seatStudents(studentlist, row, col); // seating algorithm
      ret = outputSeatedStudentsInCSV(seatedstudents); // output studentlist in csv
    }
    else
    {
      ret = "failed\n";
    }
  }
  else
  {
    ret = "failed\n";
  }

  return ret;
}

/***************************************************************/
/*                        Subroutines                          */
/***************************************************************/
/**
 * Read students with firstname and lastname from csv,
 * store it in a vector and return it
 **/
std::vector<t_student> getStudentsFromCSV(std::string filename)
{
  std::string const csvfolderlocation = "../data/";
  std::ifstream inputcsv;
  std::string field;
  t_student student;
  std::vector<t_student> studentlist;

  inputcsv.open(csvfolderlocation + filename);
  if(inputcsv.fail())
  {
    return studentlist; // return empty studentlist
  }

  while(inputcsv.peek() != EOF)
  {
    std::getline(inputcsv, student.firstname, ';');
    std::getline(inputcsv, student.lastname, '\n');
    studentlist.push_back(student);
    student = {};
  }
  inputcsv.close();

  return studentlist;
}

/**
 * Seat the students according to amount of students, rows and columns
 * and return a vector of seated students
 **/
std::vector<t_seated_student> seatStudents(std::vector<t_student> &studentlist, int row, int col)
{
  int i = 0, j = 0, seats = 0, it = 0, rowcount = 0, colcount = 0, studentcount = 0, s = 0;
  float stepwidth = 0, laststepwidth = 0, position = 0;
  t_seated_student tempseatedstudent;
  std::vector<t_seated_student> seatedstudents;

  seats = row * col;  // max seats

  for(i = 0; i < row; i++)
  {
    for(j = 0; j < col; j = j + 2)
    {
      tempseatedstudent.name.firstname = studentlist[it].firstname;
      tempseatedstudent.name.lastname = studentlist[it].lastname;
      tempseatedstudent.row = i;
      tempseatedstudent.col = j;
      seatedstudents.push_back(tempseatedstudent);
      tempseatedstudent = {};
      if(it == (studentlist.size() - 1))
      {
        i = row;
        j = col;
      }
      it++;
    }
  }

  return seatedstudents;
}

/**
 * Output seated students in csv
 **/
std::string outputSeatedStudentsInCSV(std::vector<t_seated_student> &studentlist) // given studentlist as reference not as pointer
{
  std::ofstream outputcsv;
  std::stringstream ss;
  int i = 0;

  outputcsv.open("../data/seatlist.csv");
  if(outputcsv.fail())
  {
    return "failed"; // return with failed
  }
  else
  {
    outputcsv << "First name;Last name;Row;Column\n";
    for(auto it : studentlist)
    {
      ss << it.name.firstname << ";" << it.name.lastname << ";" << it.row << ";" << it.col << "\n";
    }
    outputcsv << ss.str();
  }
  outputcsv.close();

  return ss.str();
}
