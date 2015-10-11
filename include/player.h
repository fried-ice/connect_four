#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "color.h"

class Player {
private:
    std::string name;
    Color* playerColor;
    static unsigned int playercount;
public:
    Player();
    Player(std::string, Color* newColor);
    std::string getName();
    void setName(std::string newName);
    Color* getColor();
    void setColor(Color* newColor);
};

#endif
