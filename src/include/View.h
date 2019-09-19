/**
 * \file View.h
 * \brief This file gives the methods
 * for printing the board to the screen
 * \description This is the view portion of 
 * the project
 * \author Lucia Cristiano, cristial
 */
#ifndef A4_VIEW_H
#define A4_VIEW_H
#include "CellType.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

/**
 * \brief This method takes the board's 
 * current state and outputs it to the 
 * screen
 * \param state takes a 2D vector representing the board
 */
void viewScreen(std::vector<std::vector<CellT> > state);

/**
 * \brief This methode reads the board state given
 * to a file
 * \param state Takes in a 2D vector of CellT representing
 * the board state
 */
void WriteFile(std::vector<std::vector<CellT> > state); 

#endif