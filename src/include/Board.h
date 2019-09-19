/**
 * \file Board.h
 * \author Lucia Cristiano, cristial
 * \brief this class creates and modifies the board based on 
 * the rules of Conway's game of life
 */
#ifndef A4_BOARD_H
#define A4_BOARD_H
#include "CellType.h"
#include <vector>


class Board{
    private:
        std::vector<std::vector<CellT> > board_state;
        std::vector<std::vector<CellT> > new_state;
        int checkNeighbour(CellT c);

    public:
        /**
         * \brief Used to construct the initial
         * configuaration of the board
         * \param takes in a 2D vector of CellT
         */
        Board(std::vector<std::vector<CellT> > init_state); 

        /**
         * \brief uses the rules of the game of life to
         * update the board
         */ 
        void update();

        /**
         * \brief Getter for the board
         * \returns a 2D vector of CellT representing the
         * board state
         */
        std::vector<std::vector<CellT> > getNewState();
        //int checkNeighbour(CellT c);
};
#endif