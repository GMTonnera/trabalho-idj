#include "Game.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main(int argc, char** argv) {
    Game game = Game::GetInstance();
    game.Run();

    return 0;
}