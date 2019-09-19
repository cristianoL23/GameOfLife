/**
 * \file Read.h
 * \author Lucia Cristiano, cristial
 * \brief These methods are used to read the
 * initial board state from a file and then 
 * write the board state to a file.
 */
#ifndef A4_READ_H
#define A4_READ_H
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <vector>
#include "CellType.h"

/**
 * \brief This method reads the initial board 
 * configuration from a file
 * \param s A string representing the file name
 * \returns A 2D vector of CellT type
 */
std::vector<std::vector<CellT> > ReadFile(std::string s);

#endif