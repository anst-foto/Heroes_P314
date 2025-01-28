#pragma once

#include "Hero.h"

class God : public Hero {
public:
    God(string name, int health, int damage)
        : Hero(name, health, damage) {}

    God(string name, const HeroConfig &config)
        : Hero(name, config) {}

    void attack(Hero *enemy) override {
        enemy->setHealth(0);
    }
};
