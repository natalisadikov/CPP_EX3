This project implements a simplified version of the game Catan using C++. It includes player management, resource handling, trading, and basic game mechanics.

## Project Structure

The project consists of the following main components:

- `main.cpp`.
- `catan.cpp` and `catan.hpp`: Implement the main game logic.
- `player.cpp` and `player.hpp`: Define the Player class and its methods.
- `board.cpp` and `board.hpp`: Implement the game board and its operations.
- `Test.cpp`: Contains unit tests for various game components.

## Key Classes and Methods

### Catan Class (`catan.cpp`, `catan.hpp`)

The Catan class manages the overall game flow and interactions between players and the board.

Key methods:
- `setup()`: Initializes the game by setting up players.
- `update_resources(player& p, int loc)`: Updates a player's resources based on the location.
- `initiate_prep()`: Handles the initial placement of settlements and roads.
- `initiate_round()`: Manages a game round, including dice rolling and player actions.
- `trade_item(int player_num, string item1, string item2)`: Facilitates trading between players.
- `declare_winner()`: Checks if a player has reached 10 points and declares them the winner.

### Player Class (`player.cpp`, `player.hpp`)

The Player class represents a player in the game, managing their resources and actions.

Key methods:
- `set_name(string name)`: Sets the player's name.
- `get_name()`: Returns the player's name.
- `update_points(int x)`: Updates the player's points.
- `get_points()`: Returns the player's current points.
- `roll_dice()`: Simulates rolling two dice and returns the result.

### Board Class (`board.cpp`, `board.hpp`)

The Board class manages the game board, including resource distribution and settlement/road placement.

Key methods:
- `print_board()`: Displays the current state of the game board.
- `is_occupied(int loc, int dir)`: Checks if a location and direction are already occupied.
- `check_loc(int loc)`: Verifies if a location is valid for placement.
- `append_file(int player, int loc, int dir)`: Records a player's placement on the board.


## Game Rules

This implementation includes simplified Catan rules:

1. The game supports 3 players.
2. Players start with 2 points each.
3. Resources include wood, bricks, wool, oats, and iron.
4. Players can build settlements and roads.
5. Trading between players is supported.
6. The first player to reach 10 points wins.

## Game Flow

1. Game setup: Players enter their names.
2. Initial placement: Each player places two settlements and two roads.
3. Main game loop:
   - Roll dice to determine resource production.
   - Players can trade resources.
   - Players can build new settlements or roads.
4. The game continues until a player reaches 10 points.
