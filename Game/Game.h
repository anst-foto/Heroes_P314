#pragma once

#include <string>

#include "../Heroes/Hero.h"

using namespace std;

class Game {
private:
    Hero* hero;
    Hero* enemy;

public:
    Game(Hero *hero, Hero *enemy)
        : hero(hero), enemy(enemy) {}

    ~Game() {
        delete hero;
        delete enemy;
    }

    void run() {
        do {
            hero->attack(enemy);
            if (enemy->isDead()) break;

            enemy->attack(hero);
            if (hero->isDead()) break;

        } while (true);
    }

    string getWinName() {
        if (enemy->isDead()) {
            return  hero->getName();
        }

        if (hero->isDead()) {
            return  enemy->getName();
        }
    }
};
