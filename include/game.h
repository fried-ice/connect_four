#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <array>
#include <vector>
#include "player.h"
#include "field.h"
#include "color.h"
#include "disc.h"

class Game {
private:
    unsigned int straightLenght;
    Player* player1;
    Player* player2;
    Field* currentField;
    Player* currentPlayer;
    Player* winner;
    int setUp(std::vector<std::string>* arguments);
    int run();
    unsigned int getUserInput(std::istream& is);
    Player* checkForWin(std::array<int, 2>* position);
    bool checkStraight(std::array<int, 2>* position, int shiftV, int shiftH);
    int finish();
public:
    Game();
    ~Game();
    int launch(std::vector<std::string>* arguments);
};

#endif
