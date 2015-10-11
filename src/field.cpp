#include "field.h"

Field::Field(int column, int row) {
    currentDiscs.resize(column);
    width = column;
    height = row;
}

bool Field::isAccessable(int column, int row) {
    if(column >= width || column < 0 || row >= height || row < 0 || Field::getCurrentHeight(column) <= row )
        return false;
    return true;
}

bool Field::isAccessable(int column) {
    if(column >= width || column < 0)
        return false;
    return true;
}

unsigned int Field::getCurrentHeight(int column) {
    if(!Field::isAccessable(column))
        return -1;
    return currentDiscs.at(column).size();
}

Disc* Field::getDisc(int column, int row) {
    if(!isAccessable(column, row))
        return NULL;
    return currentDiscs.at(column).at(row);
}

int Field::addDisc(int column, Player* newOwner) {
    if(!Field::isAccessable(column))
        return 1;
    unsigned int currentHeight = Field::getCurrentHeight(column);
    if(currentHeight >= height)
        return 2;

    currentDiscs.at(column).push_back(new Disc(newOwner));
    LastPosition[0] = column;
    LastPosition[1] = currentHeight;
    return 0;
}

void Field::draw(std::ostream& os) {
    Disc* dsc;
    for(unsigned int i = height; i > 0; i--) {
        for(unsigned int j = 0; j < width; j++) {
            dsc = getDisc(j,i-1);
            if(dsc == NULL) {
                os << " [";
                Field::spacer(os, tlMax, " ");
                os << "]";
             } else {
                 os << " [" << *dsc->getColor()->getToken();
                 Field::spacer(os, (unsigned int)(tlMax-dsc->getColor()->getToken()->length()), " ");
                 os << "]";
             }
        }
        os << std::endl;
    }
    // draw column numbers and separation line
    for(unsigned int i = 0; i < width; i++) {
        os << "---";
        Field::spacer(os, tlMax, "-");
    }
    os << std::endl;
    for(unsigned int i = 0; i < width; i++) {
        os << " [" << i+1;
        Field::spacer(os, tlMax-1, " ");
        os << "]";
    }
    os << std::endl << std::endl;
}

std::array<int, 2>* Field::getLastPosition() {
    return &LastPosition;
}

std::ostream& Field::spacer(std::ostream& os, unsigned int count, std::string character) {
    for(unsigned int i = 0; i < count; ++i)
        os << character;
    return os;
}

void Field::setMaxTokenLengt(Color* col1, Color* col2) {
    unsigned int p1tl = (unsigned int)col1->getToken()->length();
    unsigned int p2tl = (unsigned int)col2->getToken()->length();
    p1tl > p2tl ? tlMax = p1tl : tlMax = p2tl;
}
