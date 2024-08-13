// 206396863
// natalisadikov2318@gmail.com

#ifndef CATAN_HPP
#define CATAN_HPP

#include <iostream>
#include <fstream>
#include <string>
#include "player.hpp"
#include "board.hpp"

using namespace std;

class catan : public board {
private:
    

public:
    string names;
    player p1, p2, p3, curr;
    catan();
    void setup();
    void update_resources(player& p, int loc);
    void initiate_prep();
    void initiate_round();
    void trade_item(int player, string item1, string item2);
    void declare_winner();
    ~catan();
};

#endif