#include "../include/CellType.h"
#include "../include/View.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


void viewScreen(std::vector<std::vector<CellT>> state){  
    for(int r=0; r<state.size(); r++){
        for(int c=0; c<state[r].size(); c++){

            if(state[r][c].status == 1){
                std::cout << "1" << " ";
            }
            else if(state[r][c].status == 0){
                std::cout << "0" << " ";
            }
        }
        std::cout << std::endl;
    }
}

void WriteFile(std::vector<std::vector<CellT> > state){
    std::ofstream write;
    write.open("./experiment/output.txt");
    for(int r=0; r<state.size(); r++){
        for(int c=0; c<state.size(); c++){
            if(state[r][c].status == 1){
                write << "1" << " ";
            }
            else if(state[r][c].status == 0){
                write << "0" << " ";
            }
        }
        write << std::endl;
    }
    write.close();
}