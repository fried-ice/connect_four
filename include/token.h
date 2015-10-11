#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <iostream>
#include "player.h"

class Token {
private:
    Player player1;
    Token* currentToken;
public:
    Player* getPlayer();
    //virtual void draw();
};

#endif
