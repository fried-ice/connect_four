#include "disc.h"

Disc::Disc() {
    owner = NULL;
}

Disc::Disc(Player* newOwner) {
    owner = newOwner;
}

Color* Disc::getColor() {
    return owner->getColor();
}

Player* Disc::getOwner() {
    return owner;
}
