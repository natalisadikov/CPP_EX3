#include "player.hpp"

player::player(){
    this->points = 2;
    this->wood = 0;
    this->bricks = 0;
    this->wool = 0;
    this->oats = 0;
    this->iron = 0;
}

void player::set_name(string name){
    this->name = name;
    cout << "Welcome " << this->name << endl;
}

string player::get_name(){
    return this->name;
}


void player::update_points(int x){
    this->points += x;
}

int player::get_points(){
    return this->points;
}

int player::roll_dice(){
    int randomNumber = 0;
    srand(time(0));  // Seed the random number generator
    randomNumber += rand() % 6 + 1;  // Random number between 1 and 100
    randomNumber += rand() % 6 + 1;  // Random number between 1 and 100
    cout << "DICE PRODUCED " << randomNumber << endl;
    return randomNumber;
}
player::~player(){

}