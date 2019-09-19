#include <vector>
#include <string>
#include "../include/Read.h"
#include "../include/CellType.h"
#include "../include/Board.h"
#include "../catch/catch.h"


TEST_CASE( "test for board" , "[Board]" ){

    /**
     * instantiations of board for various test cases
     */
    std::vector<std::vector<CellT> > blank_init;
    blank_init = ReadFile("./test/test1.txt");
    Board test(blank_init);

    //populated board
    std::vector<std::vector<CellT> > init;
    init = ReadFile("./test/test2.txt");
    Board good(init);

    //populated board glider
    std::vector<std::vector<CellT> > Ginit;
    Ginit = ReadFile("./test/test3.txt");
    Board glide(Ginit);

    //populated edge test
    std::vector<std::vector<CellT> > Einit;
    Einit = ReadFile("./test/test4.txt");
    Board edge(Einit);

    SECTION( "testing getter"){
        bool agg = true;
        std::vector<std::vector<CellT> > temp = test.getNewState();
        for(int r=0; r<temp.size(); r++){
            for(int c=0; c<temp.size(); c++){
                if(temp[r][c].status == 0){
                    agg = agg && true;
                }
                else{
                    agg = agg && false;
                }
            }
        }
        REQUIRE( agg );
    }

    //generic oscillator test
    SECTION( "testing update with oscillator" ){
        bool agg = true;
        good.update();
        std::vector<std::vector<CellT> > temp = good.getNewState();

        //checking 0th row
        for(int c=0; c<temp[0].size(); c++){
            if(temp[0][3].status == 1){
                agg = agg && true;
            }
            else if (temp[0][c].status == 0){
                agg = agg && true;
            }
            else{
                agg = agg && false;
            }
        }
        //checking 1st row
        for(int c=0; c<temp[1].size(); c++){
            if(temp[1][3].status == 1){
                agg = agg && true;
            }
            else if (temp[1][c].status == 0){
                agg = agg && true;
            }
            else{
                agg = agg && false;
            }
        }

        //checking 2nd row
        for(int c=0; c<temp[2].size(); c++){
            if(temp[2][3].status == 1){
                agg = agg && true;
            }
            else if (temp[2][c].status == 0){
                agg = agg && true;
            }
            else{
                agg = agg && false;
            }
        }

        //checking 3rd row
        for(int c=0; c<temp[4].size(); c++){
            if(temp[3][c].status == 0){
                agg = agg && true;
            }
            else{
                agg = agg && false;
            }
        }
        //checking 4th row
        for(int c=0; c<temp[3].size(); c++){
            if(temp[4][c].status == 0){
                agg = agg && true;
            }
            else{
                agg = agg && false;
            }
        }

        //osciallates back
        good.update();
        std::vector<std::vector<CellT> > t2 = good.getNewState();
        //checking 0th row
        for(int c=0; c<t2[0].size(); c++){
            if (t2[0][c].status == 0){
                agg = agg && true;
            }
            else{
                agg = agg && false;
            }
        }
        //checking 1st row
        for(int c=0; c<t2[1].size(); c++){
            if(t2[1][2].status == 1 || t2[1][3].status == 1 || t2[1][4].status == 1){
                agg = agg && true;
            }
            else if (t2[1][c].status == 0){
                agg = agg && true;
            }
            else{
                agg = agg && false;
            }
        }

        //checking 2nd row
        for(int c=0; c<t2[2].size(); c++){
            if (t2[2][c].status == 0){
                agg = agg && true;
            }
            else{
                agg = agg && false;
            }
        }

        //checking 3rd row
        for(int c=0; c<t2[4].size(); c++){
            if(t2[3][c].status == 0){
                agg = agg && true;
            }
            else{
                agg = agg && false;
            }
        }
        //checking 4th row
        for(int c=0; c<t2[3].size(); c++){
            if(t2[4][c].status == 0){
                agg = agg && true;
            }
            else{
                agg = agg && false;
            }
        }

        REQUIRE( agg );
    }

    //glider test
    SECTION( "testing update with glider" ){
        bool agg=true;
        glide.update();
        std::vector<std::vector<CellT> > t = glide.getNewState();
        //0th row
        for(int c=0; c<t[0].size(); c++){
            if (t[0][c].status == 0){
                agg = agg && true;
            }
            else{
                agg = agg && false;
            }
        }
        //1st row
        for(int c=0; c<t[1].size(); c++){
            if(t[1][2].status == 1 || t[1][4].status == 1){
                agg = agg && true;
            }
            else if (t[1][c].status == 0){
                agg = agg && true;
            }
            else{
                agg = agg && false;
            }
        }
        //2nd row
        for(int c=0; c<t[2].size(); c++){
            if(t[2][3].status == 1 || t[2][4].status == 1){
                agg = agg && true;
            }
            else if (t[2][c].status == 0){
                agg = agg && true;
            }
            else{
                agg = agg && false;
            }
        }

        //3rd row
        for(int c=0; c<t[3].size(); c++){
            if(t[3][3].status == 1 ){
                agg = agg && true;
            }
            else if (t[3][c].status == 0){
                agg = agg && true;
            }
            else{
                agg = agg && false;
            }
        }
        //4th row
        for(int c=0; c<t[4].size(); c++){
            if (t[4][c].status == 0){
                agg = agg && true;
            }
            else{
                agg = agg && false;
            }
        }

        REQUIRE( agg );
    }

    //edge test
    SECTION( "testing edges of board" ){
        bool agg=true;
        edge.update();
        std::vector<std::vector<CellT> > t = edge.getNewState();
        //0th row
        for(int c=0; c<t[0].size(); c++){
            if (t[0][c].status == 0){
                agg = agg && true;
            }
            else{
                agg = agg && false;
            }
        }
        //1st row
        for(int c=0; c<t[1].size(); c++){
           if (t[1][c].status == 0){
                agg = agg && true;
            }
            else{
                agg = agg && false;
            }
        }
        //2nd row
        for(int c=0; c<t[2].size(); c++){
            if(t[2][0].status == 1 || t[2][1].status == 1){
                agg = agg && true;
            }
            else if (t[2][c].status == 0){
                agg = agg && true;
            }
            else{
                agg = agg && false;
            }
        }

        //3rd row
        for(int c=0; c<t[3].size(); c++){
            if(t[3][c].status == 0){
                agg = agg && true;
            }
            else{
                agg = agg && false;
            }
        }
        //4th row
        for(int c=0; c<t[4].size(); c++){
            if (t[4][c].status == 0){
                agg = agg && true;
            }
            else{
                agg = agg && false;
            }
        }

        REQUIRE( agg );
    }

}