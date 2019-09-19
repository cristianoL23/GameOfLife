#include "../include/CellType.h"
#include "../include/Board.h"
#include <vector>
#include <iostream>

Board::Board(std::vector<std::vector<CellT> > init_state){
    this->board_state = init_state;
    this->new_state = init_state;
}

void Board::update(){
    this->board_state = this->new_state;
    for(int r=0; r<board_state.size(); r++){
        for(int c=0; c<board_state.size(); c++){
            int n=0;
            n = Board::checkNeighbour(board_state[r][c]) ;//<< std::endl;
            //std::cout << n << std::endl;
            //solitude
            if( (board_state[r][c].status == 1) && (n < 2) ){
                new_state[r][c].status = 0;
            }
            //overpop
            if( (board_state[r][c].status == 1) && (n > 3) ){
                new_state[r][c].status = 0;
            }
            //alive
            if( (board_state[r][c].status == 1) && (n == 3 || n == 2) ){
                new_state[r][c].status = 1;
            }
            //born
            if((board_state[r][c].status == 0) && (n == 3) ){
                new_state[r][c].status = 1;
            }
        }
    }

}


int Board::checkNeighbour(CellT n){
    int neigh=0;
    int r = n.r;
    int c = n.c;

    //top left
    if((r-1)>=0 && (c-1)>=0){
        neigh += board_state[r-1][c-1].status;
        //std::cout << board_state[r-1][c-1].status << std::endl;
    }
    //top mid
    if((r-1)>=0){
        neigh += board_state[r-1][c].status;
        //std::cout << board_state[r-1][c].status << std::endl;
    }
    //top right
    if((r-1)>=0 && (c+1)<board_state.size()){
        neigh += board_state[r-1][c+1].status;
        //std::cout << board_state[r-1][c+1].status << std::endl;
    }

    //mid left
    if((c-1)>=0){
        neigh += board_state[r][c-1].status;
        //std::cout << board_state[r][c-1].status << std::endl;
    }
    //mid right
    if((c+1)<board_state.size()){
        neigh += board_state[r][c+1].status;
        //std::cout << board_state[r][c+1].status << std::endl;
    }

    //bottom left
    if((r+1)<board_state.size() && (c-1)>=0){
        neigh += board_state[r+1][c-1].status;
        //std::cout << board_state[r+1][c-1].status << std::endl;
    }
    //bottom mid
    if((r+1)<board_state.size() ){
        neigh += board_state[r+1][c].status;
        //std::cout << board_state[r+1][c].status << std::endl;
    }
    //bottom right
    if((r+1)<board_state.size() && (c+1)<board_state.size()){
        neigh += board_state[r+1][c+1].status;
        //std::cout << board_state[r+1][c+1].status << std::endl;
    }
    //std::cout << neigh << std::endl;
    return neigh;
}

std::vector<std::vector<CellT> > Board::getNewState(){
    return this->new_state;
}