#include <vector>
#include <string>
#include "../include/Read.h"
#include "../include/CellType.h"
#include "../include/Board.h"
#include "../catch/catch.h"


TEST_CASE( "Test the Read module" , "[Read]" ){
    /**
     * set-up for test cases
     */
    std::string file = "./test/test1.txt";
    std::vector<std::vector<CellT> > read_state;

    //test case for file reading
    SECTION( "file being correctly read" ){
        bool agg = true;
        read_state = ReadFile(file);
        for(int r=0; r<read_state.size(); r++){
            for(int c=0; c<read_state.size(); c++){
                if(read_state[r][c].status == 0){
                    agg = agg && true;
                }
                else{
                    agg = agg && false;
                }
            }
        }
        REQUIRE( agg );
    }
    
    //test case for file not being found
    SECTION( "reading exception" ){
        REQUIRE_THROWS_AS( ReadFile("../test/test.txt") , std::runtime_error );
    }
}