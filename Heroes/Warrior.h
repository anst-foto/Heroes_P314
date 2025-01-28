#pragma once

#include "Hero.h"

class Warrior : public Hero {
public:
    Warrior(const string &name, int health, int damage)
        : Hero(name, health, damage) {
    }

    Warrior(string name, const HeroConfig &config)
        : Hero(name, config) {}
};
