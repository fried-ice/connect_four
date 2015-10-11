#ifndef FIELD_H
#define FIELD_H

#include <vector>
#include <array>
#include <iostream>
#include "disc.h"
#include "player.h"

class Field {
private:
    int width;
    int height;
    unsigned int tlMax = 1;
    std::array<int, 2> LastPosition;
    std::vector<std::vector<Disc*>> currentDiscs;
    bool isAccessable(int column, int row);
    bool isAccessable(int column);
    std::ostream& spacer(std::ostream& os, unsigned int count, std::string character);
public:
    Field(int column, int row);
    unsigned int getCurrentHeight(int column);
    Disc* getDisc(int column, int row);
    int addDisc(int column, Player* newOwner);
    std::array<int, 2>* getLastPosition();
    void draw(std::ostream& os);
    void setMaxTokenLengt(Color* col1, Color* col2);

};

#endif
