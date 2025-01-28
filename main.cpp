#include <iostream>

#include "Game/Game.h"
#include "Logger/LogToConsole.h"

using namespace std;

int main() {
    auto game = new Game(new LogToConsole());
    game->prepare("HERO", HeroType::HeroType_Mage, "ENEMY", HeroType::HeroType_God);

    game->run();
    cout << game->getWinName() << " YOU WIN" << endl;

    return 0;
}