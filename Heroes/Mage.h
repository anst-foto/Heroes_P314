#pragma once

#include "Hero.h"

class Mage : public Hero {
public:
    Mage(string name, int health, int damage)
        : Hero(name, health, damage) {}

    Mage(string name, const HeroConfig &config)
        : Hero(name, config) {}
};
