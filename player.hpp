#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <cstdlib>
#include <ctime> 
#include <string>
using namespace std;


class player{
    private:
        string name;
        int points;
    public:
        int wood, bricks, wool, oats, iron;
        player();
        void set_name(string name);
        string get_name();
        void update_points(int x);
        int roll_dice();
        int get_points();
        ~player();
};
#endif