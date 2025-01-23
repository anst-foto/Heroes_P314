#pragma once

#include "Hero.h"

class God : public Hero {
public:
    God(string name, int health, int damage)
        : Hero(name, health, damage) {}

    void attack(Hero *enemy) override {
        enemy->setHealth(0);
    }
};
