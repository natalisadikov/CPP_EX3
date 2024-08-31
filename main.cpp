// 206396863
// natalisadikov2318@gmail.com

#include <iostream>
#include <stdexcept>
#include <vector>
#include "catan.hpp"
using namespace std;

int main()
{
    catan test;
    test.setup();  // Set up the game by getting player names
    test.print_board();  // Print the game board
    test.initiate_prep();  // Players place initial settlements and roads
    test.initiate_round();  // Start the game round
    test.declare_winner();  // Declare the winner based on points
    return 0;
}