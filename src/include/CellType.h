/**
 * \file CellType.h
 * \author Lucia Cristian, cristial
 * \brief This module creates the cell type
 * used in the Game of Life board
 */
#ifndef A4_CELLTYPE_H
#define A4_CELLTYPE_H

/**
 * \brief creates the CellT 
 * used to make the board
 * \description cell consists of
 * status (alive or dead) and
 * coordinate position in grids
 */
struct CellT{
    int r;
    int c;
    bool status;
};

#endif