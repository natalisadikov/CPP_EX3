#include <iostream>
#include <stdexcept>
#include <vector>
#include "catan.hpp"
using namespace std;

int main()
{
    catan test;
    test.setup();
    test.print_board();
    test.initiate_prep();
    test.initiate_round();
    test.declare_winner();
    return 0;
}