#include <iostream>
#include <vector>
#include "game.h"

using namespace std;


int main(int argc, char* argv[]) {

    cout << "\n";
    // Display Welcome Message
    std::cout << "Connect four - a simple C++ CLI Game.\n" << std::endl;

    vector<string> arguments;

    if (argc == 1) {
        std::cout << "Starting a new game with default settings!" << std::endl;
        std::cout << "Use \"" << argv[0] << " -h\" to view help.\n" << endl;
    } else {
        bool widthIsSet = false;
        bool heightIsSet = false;
        bool p1nIsSet = false;
        bool p2nIsSet = false;
        bool p1tIsSet = false;
        bool p2tIsSet = false;
        bool lengthIsSet = false;
        for(int i = 1; i<argc; ++i) {
            string arg = argv[i];
            if (arg == "-h" || arg == "--help") {
                std::cout << "USAGE: "
                << argv[0] << endl
                << " -h display this help\n"
                << " -c adjust the number of columns\n"
                << " -r adjust the number of rows\n"
                << " -l adjust the number of discs in a row to win\n"
                << " -p1n change the name of Palyer 1\n"
                << " -p2n change the name of Palyer 2\n"
                << " -p1t change the token of Palyer 1\n"
                << " -p2t change the token of Palyer 2\n"
                << " Yes, you are able to create a game that cannot be won!"
                << std::endl << std::endl;
                return 1;
            } if(arg == "-c" || arg == "--columns") {
                if(i+1<argc && !widthIsSet) {
                    arguments.push_back("c");
                    arguments.push_back(argv[i+1]);
                    widthIsSet = true;
                }
            } if(arg == "-r" || arg == "--rows") {
                if(i+1<argc && !heightIsSet) {
                    arguments.push_back("r");
                    arguments.push_back(argv[i+1]);
                    heightIsSet = true;
                }
            } if(arg == "-p1n" || arg == "--player1name") {
                if(i+1<argc && !p1nIsSet) {
                    arguments.push_back("p1n");
                    arguments.push_back(argv[i+1]);
                    p1nIsSet = true;
                }
            } if(arg == "-p2n" || arg == "--player2name") {
                if(i+1<argc && !p2nIsSet) {
                    arguments.push_back("p2n");
                    arguments.push_back(argv[i+1]);
                    p2nIsSet = true;
                }
            } if(arg == "-p1t" || arg == "--player1token") {
                if(i+1<argc && !p1tIsSet) {
                    arguments.push_back("p1t");
                    arguments.push_back(argv[i+1]);
                    p1tIsSet = true;
                }
            } if(arg == "-p2t" || arg == "--player2token") {
                if(i+1<argc && !p2tIsSet) {
                    arguments.push_back("p2t");
                    arguments.push_back(argv[i+1]);
                    p2tIsSet = true;
                }
            } if(arg == "-l" || arg == "--legth") {
                if(i+1<argc && !lengthIsSet) {
                    arguments.push_back("l");
                    arguments.push_back(argv[i+1]);
                    lengthIsSet = true;
                }
            }

        }
    }

    Game currentGame;
    return currentGame.launch(&arguments);
}
