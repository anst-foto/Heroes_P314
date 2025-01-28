#pragma once

#include <string>

#include "../HeroFactory/HeroFactory.h"

using namespace std;

class IGame {
protected:
    IGame() = default;
public:
    virtual void prepare(string nameHero, HeroType heroType, string enemyName, HeroType enemyType) = 0;
    virtual void run() = 0;
    virtual string getWinName() = 0;
};
