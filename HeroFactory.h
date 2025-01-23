#pragma once

#include <string>

#include "HeroType.h"

#include "Mage.h"
#include "Warrior.h"
#include "God.h"

#include "GameConfig.h"

using namespace std;

class HeroFactory {
private:
    string name;
    HeroType heroType;

public:
    HeroFactory(string name, HeroType heroType) {
        this->name = name;
        this->heroType = heroType;

        GameConfig::loadConfig("game.config");
    }
    ~HeroFactory() = default;

    Hero* createHero() {
        switch (heroType) {
            case HeroType::HeroType_Mage:
                return new Mage(name, GameConfig::mageHealth, GameConfig::mageDamage);
            case HeroType::HeroType_Warrior:
                return new Warrior(name, GameConfig::warriorHealth, GameConfig::warriorDamage);
            case HeroType::HeroType_God:
                return new God(name, GameConfig::godHealth, GameConfig::godDamage);
        }
    }
};
