#ifndef DISC_H
#define DISC_H

#include "color.h"
#include "player.h"

class Disc {
private:
    Player* owner;
public:
    Disc();
    Disc(Player* newOwner);
    Color* getColor();
    Player* getOwner();
};

#endif
