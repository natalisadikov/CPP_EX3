// 206396863
// natalisadikov2318@gmail.com

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "player.hpp"
#include "catan.hpp"
#include "board.hpp"

TEST_CASE("Player initialization") {
    player p;
    CHECK(p.get_points() == 2);
    CHECK(p.wood == 0);
    CHECK(p.bricks == 0);
    CHECK(p.wool == 0);
    CHECK(p.oats == 0);
    CHECK(p.iron == 0);
}

TEST_CASE("Player name") {
    player p;
    p.set_name("John");
    CHECK(p.get_name() == "John");
}

TEST_CASE("Player points update") {
    player p;
    p.update_points(3);
    CHECK(p.get_points() == 5);
}

TEST_CASE("Player dice roll") {
    player p;
    int dice_value = p.roll_dice();
    CHECK(dice_value >= 2);
    CHECK(dice_value <= 12);
}

TEST_CASE("Catan setup") {
    catan game;
    game.setup();
    CHECK(game.p1.get_name().length() > 0);
    CHECK(game.p2.get_name().length() > 0);
    CHECK(game.p3.get_name().length() > 0);
}

TEST_CASE("Catan update resources") {
    catan game;
    player p;
    game.update_resources(p, 1);
    CHECK(p.bricks > 0);
    CHECK(p.oats > 0);
    CHECK(p.iron > 0);;
}

TEST_CASE("Catan trade item") {
    catan game;
    game.p1.wood = 2;
    game.p2.bricks = 1;
    game.trade_item(2, "wood", "bricks");
    CHECK(game.p1.wood == 1);
    CHECK(game.p2.bricks == 2);
}

TEST_CASE("Board check_loc") {
    board b;
    CHECK(b.check_loc(1) == true);
    b.append_file(1, 1, 1);
    CHECK(b.check_loc(1) == true);
}
