#pragma once

#include <string>

/**
 * Function asa() reads a csv file containing students, and 
 * produces a seating list for an exam seating in a room which has a defined 
 * number of seats in predefines positions. The function makes sure that the students 
 * are evenly distributed, and the result of your program is a csv file which 
 * contains the students plus the assigned seats (row, column)
 * Input: filename as a string
 * Ouput: filestream of the created file called "seating_list.csv"
 */
std::string asa(std::string filename, int row, int col);

