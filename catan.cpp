#include "catan.hpp"

catan::catan() {}

void catan::setup() {
    cout << "Enter name of player 1: ";
    getline(cin, names);
    p1.set_name(names);

    cout << "Enter name of player 2: ";
    getline(cin, names);
    p2.set_name(names);

    cout << "Enter name of player 3: ";
    getline(cin, names);
    p3.set_name(names);
}

void catan::update_resources(player& p, int loc) {
    ifstream file("regions.txt");
    if (!file.is_open()) {
        cerr << "Unable to open file" << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        if (loc < 10 && line[0] == ('0' + loc)) {
            int len = line.length() - 1;
            for (int i = len; i >= len - 2; --i) {
                switch (line[i]) {
                    case 'F':
                        p.wood++;
                        break;
                    case 'H':
                        p.bricks++;
                        break;
                    case 'P':
                        p.wool++;
                        break;
                    case 'A':
                        p.oats++;
                        break;
                    case 'M':
                        p.iron++;
                        break;
                    default:
                        break;
                }
            }
            break;
        } else if (loc >= 10 && line[0] == '1' && line[1] == ('0' + (loc - 10))) {
            int len = line.length() - 1;
            for (int i = len; i >= len - 2; --i) {
                switch (line[i]) {
                    case 'F':
                        p.wood++;
                        break;
                    case 'H':
                        p.bricks++;
                        break;
                    case 'P':
                        p.wool++;
                        break;
                    case 'A':
                        p.oats++;
                        break;
                    case 'M':
                        p.iron++;
                        break;
                    default:
                        break;
                }
            }
            break;
        }
    }

    file.close();
}

void catan::initiate_prep() {
    int choice, direction;
    for (int i = 1; i <= 3; ++i) {
        player& p = (i == 1) ? p1 : (i == 2) ? p2 : p3;
        for (int j = 1; j <= 2; ++j) {
            while (true) {
                cout << p.get_name() << " enter location number to place settlement: ";
                cin >> choice;
                cin.ignore();
                cout << "Enter direction to place road: ";
                cin >> direction;
                cin.ignore();
                if (!is_occupied(choice, direction))
                    break;
                cout << "Location already entered. Please try again..." << endl;
            }
            append_file(i, choice, direction);
            update_resources(p, choice);
        }
    }
}

void catan::initiate_round() {
    int choice;
    for (int i = 1; i <= 3; ++i) {
        player& p = (i == 1) ? p1 : (i == 2) ? p2 : p3;
        cout << "Rolling dice for " << p.get_name() << endl;
        int number = p.roll_dice();
        cout << "Alloting resources to players..." << endl;
        cout << "bricks: " << p.bricks << ", iron: " << p.iron << ", oats: " << p.oats << ", wood: " << p.wood << ", wool: " << p.wool << endl;

        if (p.iron >= 1 && p.wool >= 1 && p.oats >= 1) {
            cout << "Would you like to buy development card. Enter 1 for yes, 0 for no: ";
            cin >> choice;
            if (choice == 1)
                cout << "Development Card Issued..." << endl;
        }

        cout << "Would you like to trade with someone. Enter 1 for yes, 0 for no: ";
        cin >> choice;
        cin.ignore();
        if (choice == 1) {
            int player_num;
            string item1, item2;
            cout << "Enter player number whom you want to trade with: ";
            cin >> player_num;
            cin.ignore();
            cout << "Enter item you want to trade: ";
            cin >> item1;
            cin.ignore();
            cout << "Enter item you want to receive: ";
            cin >> item2;
            cin.ignore();
            trade_item(player_num, item1, item2);
            curr = (i == 1) ? p2 : (i == 2) ? p3 : p1;
        }

        cout << "Would you like to place settlement. Enter 1 for yes, 0 for no: ";
        cin >> choice;
        cin.ignore();
        if (choice == 1) {
            while (true) {
                cout << p.get_name() << " enter location number to place settlement: ";
                cin >> choice;
                cin.ignore();
                if (!check_loc(choice))
                    break;
                cout << "Invalid location. Please try again..." << endl;
            }
            ofstream file("occupied.txt", ios::app);
            if (!file.is_open()) {
                cerr << "Unable to open file" << endl;
                return;
            }
            file << i << "\t" << choice << "\t0" << endl;
            file.close();
        }
    }
}

void catan::trade_item(int player_num, string item1, string item2) {
    player& giver = (player_num == 1) ? p2 : (player_num == 2) ? p1 : p3;
    player& receiver = (player_num == 1) ? p1 : (player_num == 2) ? p2 : p3;

    // Decrease the item from the giver
    if (item1 == "wood")
        giver.wood--;
    else if (item1 == "bricks")
        giver.bricks--;
    else if (item1 == "wool")
        giver.wool--;
    else if (item1 == "oats")
        giver.oats--;
    else if (item1 == "iron")
        giver.iron--;

    // Increase the item for the receiver
    if (item2 == "wood")
        receiver.wood++;
    else if (item2 == "bricks")
        receiver.bricks++;
    else if (item2 == "wool")
        receiver.wool++;
    else if (item2 == "oats")
        receiver.oats++;
    else if (item2 == "iron")
        receiver.iron++;

    // Ensure no negative values
    giver.bricks = max(giver.bricks, 0);
    giver.iron = max(giver.iron, 0);
    giver.oats = max(giver.oats, 0);
    giver.wood = max(giver.wood, 0);
    giver.wool = max(giver.wool, 0);

    cout << "Trade complete..." << endl;
}

void catan::declare_winner() {
    int p1_points = p1.get_points();
    int p2_points = p2.get_points();
    int p3_points = p3.get_points();

    if (p1_points >= 10)
        cout << "Player 1 is the winner!" << endl;
    else if (p2_points >= 10)
        cout << "Player 2 is the winner!" << endl;
    else if (p3_points >= 10)
        cout << "Player 3 is the winner!" << endl;
    else
        cout << "No one has reached 10 points yet. The game continues." << endl;
}

catan::~catan() {}