// 206396863
// natalisadikov2318@gmail.com

#include "board.hpp"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

board::board() {
    // Initialize the board with hexagon values
    arr[0][1] = 10; arr[0][2] = 2;  arr[0][3] = 9;
    arr[1][1] = 12; arr[1][2] = 6;  arr[1][3] = 4;  arr[1][4] = 10;
    arr[2][0] = 9;  arr[2][1] = 11; arr[2][2] = -1; arr[2][3] = 3; arr[2][4] = 8;
    arr[3][1] = 8;  arr[3][2] = 3;  arr[3][3] = 4;  arr[3][4] = 5;
    arr[4][1] = 5;  arr[4][2] = 6;  arr[4][3] = 11;

    // Initialize land types
    land[0][1] = 'M'; land[0][2] = 'P'; land[0][3] = 'F';
    land[1][1] = 'A'; land[1][2] = 'H'; land[1][3] = 'P'; land[1][4] = 'H';
    land[2][0] = 'A'; land[2][1] = 'F'; land[2][2] = 'D'; land[2][3] = 'F'; land[2][4] = 'M';
    land[3][1] = 'F'; land[3][2] = 'M'; land[3][3] = 'A'; land[3][4] = 'P';
    land[4][1] = 'H'; land[4][2] = 'A'; land[4][3] = 'P';
}

void board::print_board() {
    //print the land types and their resources
    std::cout << std::endl;
    std::cout << "F = forest (yields wood)" << std::endl;
    std::cout << "H = hills (yields bricks)" << std::endl;
    std::cout << "P = pasture land (yields wool)" << std::endl;
    std::cout << "A = agricultural land (yields oats)" << std::endl;
    std::cout << "M = mountains (yields iron)" << std::endl;
    std::cout << "D = desert (yields nothing)" << std::endl << std::endl;

    //print the board with the land types, hexagon values and numbers of junctions
    for(int i = 0; i < 5; i++) {
        if (i == 1 || i == 3) {
            std::cout << "      ";
        } else if (i == 0 || i == 4) {
            std::cout << "\n             ";
        }
        for (int j = 0; j < 5; j++) {
            if(arr[i][j] != 0 && land[i][j] != 0)
                std::cout << "[ " << land[i][j] << ", " << std::setw(2) << arr[i][j] << " ]" << "     ";
        }
        if (i == 0) {
            std::cout << std::endl << std::endl << std::endl;
            std::cout << "\t\t 1\t      2\t\t   3" << std::endl << std::endl;
        } else if (i == 1) {
            std::cout << std::endl << std::endl << std::endl;
            std::cout << "\t 4\t        5\t     6\t\t   7" << std::endl << std::endl;
        } else if (i == 2) {
            std::cout << std::endl << std::endl << std::endl;
            std::cout << "\t 8\t        9\t     10\t\t   11" << std::endl << std::endl;
        }
        if (i == 3) {
            std::cout << std::endl << std::endl << std::endl;
            std::cout << "\t\t12\t    13\t\t  14" << std::endl << std::endl;
        } else {
            std::cout << std::endl << std::endl;
        }
    }
    //print the direction map for the road
    std::cout << std::endl << "Directions: \n";
    std::cout << "1\t\t2\t\t3\n\n\t\t*\n\n4\t\t5\t\t6\n\n";
}

bool board::is_occupied(int loc, int dir) {
    if (loc <= 0 || loc > 14 || dir <= 0 || dir > 6) {
        std::cout << "Invalid location or direction.\n";
        return false;
    }
    //using file to check occupeid location
    std::ifstream file("occupied.txt");
    if (!file.is_open()) {
        std::cerr << "Unable to open file" << std::endl;
        return false;
    }

    int player, file_loc, file_dir;
    while (file >> player >> file_loc >> file_dir) {
        if (file_loc == loc && file_dir == dir) {
            file.close();
            std::cout << "Already occupied \n";
            return true;
        }
    }

    file.close();
    return false;
}

bool board::check_loc(int loc) {
    if (loc <= 0 || loc > 14) {
        std::cout << "Invalid location.\n";
        return false;
    }

    std::ifstream file("occupied.txt");
    if (!file.is_open()) {
        std::cerr << "Unable to open file" << std::endl;
        return false;
    }

    int player, file_loc, file_dir;
    while (file >> player >> file_loc >> file_dir) {
        if (file_loc == loc) {
            file.close();
            std::cout << "Already occupied \n";
            return true;
        }
    }

    file.close();
    return false;
}

void board::append_file(int player, int loc, int dir) {
    if (loc <= 0 || loc > 14 || dir <= 0 || dir > 6) {
        std::cout << "Invalid location or direction.\n";
        return;
    }

    if (is_occupied(loc, dir)) {
        std::cout << "This space is already occupied.\n";
        return;
    }

    std::ofstream file("occupied.txt", std::ios::app);
    if (!file.is_open()) {
        std::cerr << "Unable to open file" << std::endl;
        return;
    }
    file << player << "\t" << loc << "\t" << dir << std::endl;
    file.close();
}

board::~board() {
    // Destructor (remains empty if no dynamic memory allocation is used)
}