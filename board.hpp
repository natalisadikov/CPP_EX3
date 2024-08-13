#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class board
{
private:
    
 
public:
    char land[5][5];
    int arr[5][5];
    board();
    void print_board();
    bool check_loc(int loc);
    void append_file(int player,int loc, int dir);
    bool is_occupied(int loc, int dir);
    ~board();
};

#endif
