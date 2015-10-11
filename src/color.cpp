#include "color.h"

Color::Color() {
    r = 0;
    g = 0;
    b = 0;
}

Color::Color(unsigned char newR, unsigned char newG, unsigned char newB, std::string* newToken) {
    r = newR;
    g = newG;
    b = newB;
    token = *newToken;

}

void Color::setColor(unsigned char newR, unsigned char newG, unsigned char newB) {
    r = newR;
    g = newG;
    b = newB;
}

void Color::setToken(std::string* newToken) {
    token = *newToken;
}

unsigned char Color::getR() {
    return r;
}

unsigned char Color::getG() {
    return g;
}

unsigned char Color::getB() {
    return b;
}

std::string* Color::getToken() {
    return &token;
}

extern std::ostream& operator<<(std::ostream& os, Color* col) {
    col->print(os);
    return os;
}

std::ostream& Color::print(std::ostream& os) {
    os << "Token: " << token << " | Red:" << (int)this->getR() << " Green: " << (int)this->getG() << " Blue: " << (int)this->getB();
    return os;
}
