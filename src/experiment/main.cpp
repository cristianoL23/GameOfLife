#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "../include/CellType.h"
#include "../include/Read.h"
#include "../include/View.h"
#include "../include/Board.h"


int main(){
    std::cout << "Running main" << std::endl;
    std::vector<std::vector<CellT> > init;
    std::vector<std::vector<CellT> > changed;
    //viewScreen(ReadFile("./experiment/boardLoad.txt"));

    init = ReadFile("./experiment/boardload.txt");
    viewScreen(init);
    std::cout << std::endl;
    Board board(init);
    board.update();
    viewScreen(board.getNewState());
    std::cout << std::endl;
    board.update();
    viewScreen(board.getNewState());
    std::cout << std::endl;
    board.update();
    viewScreen(board.getNewState());
    std::cout << std::endl;
    board.update();
    viewScreen(board.getNewState());
    std::cout << std::endl;
    board.update();
    viewScreen(board.getNewState());
    std::cout << std::endl;
    viewScreen(board.getNewState());
    std::cout << std::endl;
    viewScreen(board.getNewState());
    std::cout << std::endl;
    viewScreen(board.getNewState());
    std::cout << std::endl;

    WriteFile(board.getNewState());

    return 0;
}