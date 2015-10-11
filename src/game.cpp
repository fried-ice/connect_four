#include "game.h"

// All compile time standard variables are set here in the main game class
// to ensure clarity
Game::Game() {}

Game::~Game() {
    delete player1;
    delete player2;
    delete currentField;
}

int Game::launch(std::vector<std::string>* arguments) {

    // Set up the game, gather all needed information
    if(Game::setUp(arguments))
        return 1;

    if(Game::run())
        return 2;

    if(Game::finish())
        return 3;
        
    return 0;
}

int Game::run() {
    unsigned int input = 0;
    int tmp = -1;

    // Draw the empty game a first time
    currentField->setMaxTokenLengt(player1->getColor(), player2->getColor());
    currentField->draw(std::cout);

    // Main Game Loop
    while(winner == NULL) {
        std::cout << currentPlayer->getName() << ", enter a column number to make your move!" << std::endl;

        // Check player input for being legit
        do {
            tmp = currentField->addDisc(Game::getUserInput(std::cin), currentPlayer);
            if(tmp == 1)
                std::cout << "Entered column number not in range, please try another one." << std::endl;
            else if(tmp == 2)
                std::cout << "Column is full, please try another one." << std::endl;
        } while(tmp != 0);

        currentField->draw(std::cout);
        winner = Game::checkForWin(currentField->getLastPosition());
        currentPlayer == player1 ? currentPlayer = player2 : currentPlayer = player1;
    }

    return 0;
}

unsigned int Game::getUserInput(std::istream& is) {
        unsigned int input;
        is >> input;
        while(!is) {
            std::cout << "Only numbers are accepted, enter again" << std::endl;
            is.clear();
            is.ignore(1024, '\n');
            is >> input;
        }
    return input-1;
}

Player* Game::checkForWin(std::array<int, 2>* position) {
    // Check all possible direction with a subrutine
    if(Game::checkStraight(position, 0, 1) || Game::checkStraight(position, 1, 0) || Game::checkStraight(position, 1, 1) || Game::checkStraight(position, -1, 1))
        return currentPlayer;
    return NULL;
}

bool Game::checkStraight(std::array<int, 2>* position, int shiftV, int shiftH) {
    Disc* dsc;

    int signV = shiftV; int signH = shiftH;

    // FIRST, Shift to the straight´s origin
    bool explorationFinished = false;
    while(!explorationFinished) {
        dsc = currentField->getDisc(position->at(0)-shiftV, position->at(1)-shiftH);
        if(dsc != NULL && dsc->getOwner() == currentPlayer) {
            if(shiftV > 0) ++shiftV;
            if(shiftV < 0) --shiftV;
            if(shiftH > 0) ++shiftH;
            if(shiftH < 0) --shiftH;
        } else explorationFinished = true;
    }
    // Correct, to match the distance
    if(shiftV > 0) --shiftV;
    if(shiftV < 0) ++shiftV;
    if(shiftH > 0) --shiftH;
    if(shiftH < 0) ++shiftH;

    // SECONDLY, Traverse the straight till it´s end
    unsigned int count = 0; // has to be equal to the win legth of discs
    bool countingFinished = false;
    while(!countingFinished) {
        dsc = currentField->getDisc(position->at(0)-shiftV, position->at(1)-shiftH);
        if(dsc != NULL && dsc->getOwner() == currentPlayer) {
            if(signV > 0) --shiftV;
            if(signV < 0) ++shiftV;
            if(signH > 0) --shiftH;
            if(signH < 0) ++shiftH;
            ++count;
        } else countingFinished = true;
        if(count >= straightLenght) return true;
    }
    return false;
}

int Game::finish() {
    std::cout << winner->getName() << " has won the game, congratulations!" << std::endl;
    return 0;
}

int Game::setUp(std::vector<std::string>* arguments) {
    //set default parameters
    unsigned int max = arguments->size();
    std::cout << "Launcher Argument count :: " << max/2 << std::endl;
    unsigned int c = 7;
    unsigned int r = 6;
    unsigned int l = 3;
    std::string player1Name = "Player 1";
    std::string player2Name = "Player 2";
    std::string player1Token = "x";
    std::string player2Token = "o";


    // Parse command line parameters
    for(int i = 0; i<max; ++i) {
        if(arguments->at(i) == "c") {
            c = stoi(arguments->at(i+1));
            ++i;
        } else if(arguments->at(i) == "r") {
            r = stoi(arguments->at(i+1));
            ++i;
        } else if(arguments->at(i) == "p1n") {
            player1Name = arguments->at(i+1);
            ++i;
        } else if(arguments->at(i) == "p2n") {
            player2Name = arguments->at(i+1);
            ++i;
        } else if(arguments->at(i) == "p1t") {
            player1Token = arguments->at(i+1);
            ++i;
        } else if(arguments->at(i) == "p2t") {
            player2Token = arguments->at(i+1);
            ++i;
        } else if(arguments->at(i) == "l") {
            l = stoi(arguments->at(i+1));
            ++i;
        }
    }

        // Construct Colors, Gamefield and players
        Color* player1Color = new Color(0,0,255, &player1Token);
        Color* player2Color = new Color(255,0,0, &player2Token);
        player1 = new Player(player1Name, player1Color);
        player2 = new Player(player2Name, player2Color);
        currentPlayer = player1;
        winner = NULL;
        currentField = new Field(c,r);
        straightLenght = l;

        // Just some Debugging outputs
        std::cout << "Field Dimensions :: " << c << " x " << r <<std::endl;
        std::cout << "Win Length :: " << straightLenght <<std::endl;
        std::cout << player1->getName() << " :: ";
        std::cout << player1->getColor() << std::endl;
        std::cout << player2->getName() << " :: ";
        std::cout << player2->getColor() << std::endl << std::endl;

        return 0;
}
