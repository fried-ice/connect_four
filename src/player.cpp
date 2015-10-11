#include "player.h"

unsigned int Player::playercount = 0;

Player::Player() {
    ++playercount;
    std::stringstream ss;
    ss << "Player " << std::to_string(playercount);
    name = ss.str();

}

Player::Player(std::string newName, Color* newColor) {
    ++playercount;
    name = newName;
    playerColor = newColor;
}

std::string Player::getName() {
    return name;
}

void Player::setName(std::string newName) {
    name = newName;
}

Color* Player::getColor() {
    return playerColor;
}

void Player::setColor(Color* newColor) {
    playerColor = newColor;
}
