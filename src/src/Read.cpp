#include "../include/CellType.h"
#include "../include/Read.h"
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <vector>

std::vector<std::vector<CellT> > ReadFile(std::string s){
    std::ifstream inFile;
    inFile.open(s);
    if(!inFile){
        throw std::runtime_error("File not found");
    }

    int r=0;
    std::string line;
    std::vector<std::vector<CellT> > init_state;
    while(std::getline(inFile, line)){
        int c=0;
        std::vector<CellT> temp;
        std::stringstream ss(line);

        while(getline (ss, line, ' ')){
            CellT n = {r,c,stoi(line)};
            temp.push_back(n);
            c++;
        }
        init_state.push_back(temp);
        r++;
    }
    inFile.close();

    return init_state;
}