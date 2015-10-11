#ifndef COLOR_H
#define COLOR_H

#include <sstream>
#include <iostream>

class Color {
private:
    unsigned char r;
    unsigned char g;
    unsigned char b;
    std::string token;

public:
    Color();
    Color(unsigned char newR, unsigned char newG, unsigned char newB, std::string* newToken);
    void setColor(unsigned char newR, unsigned char newG, unsigned char newB);
    void setToken(std::string* newToken);
    unsigned char getR();
    unsigned char getG();
    unsigned char getB();
    std::string* getToken();
    std::ostream& print(std::ostream& os);
};

    extern std::ostream& operator<<(std::ostream& os, Color* col);

#endif
