#include <vector>
#include <string>
#include "../include/Read.h"
#include "../include/View.h"
#include "../include/CellType.h"
#include "../include/Board.h"
#include "../catch/catch.h"


TEST_CASE( "Test the View module" , "[View]" ){
    /**
     * set-up for test cases
     */
    std::vector<std::vector<CellT> > read_state;

    //used for writing tests
    std::string outF = "./experiment/output.txt";
    std::vector<CellT> temp;
    std::vector<std::vector<CellT> > write_state;
    CellT n1 = {0,0,1};
    CellT n2 = {0,1,0};
    CellT n3 = {1,0,0};
    CellT n4 = {1,1,0};
    temp.push_back(n1);
    temp.push_back(n2);
    write_state.push_back(temp);
    temp.pop_back();
    temp.pop_back();
    temp.push_back(n3);
    temp.push_back(n4);
    write_state.push_back(temp);

    //uses the reading method to determine if file
    //was written in correct format
    SECTION( "writing test" ){
        WriteFile(write_state);
        read_state = ReadFile(outF);   
        bool agg=true; 
        if(read_state[0][0].status == 1){
            agg = agg && true;
        }
        else if (read_state[0][1].status == 0){
            agg = agg && true;
        }
        else if (read_state[1][0].status == 0){
            agg = agg && true;
        }
        else if (read_state[1][1].status == 0){
            agg = agg && true;
        }
        else{
            agg = agg && false;
        }
        REQUIRE( agg );
    }

    //No test case for ViewScreen since it can be manually verified
}