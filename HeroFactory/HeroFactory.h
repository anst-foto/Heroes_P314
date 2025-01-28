#pragma once

#include <string>

#include "HeroType.h"

#include "../Heroes/Mage.h"
#include "../Heroes/Warrior.h"
#include "../Heroes/God.h"

#include "../HeroConfig/HeroesConfig.h"

using namespace std;

class HeroFactory {
private:
    string name;
    HeroType heroType;
    HeroesConfig heroesConfig;

public:
    HeroFactory(string name, HeroType heroType, HeroesConfig heroes_config) {
        this->name = name;
        this->heroType = heroType;
        this->heroesConfig = heroes_config;
    }
    ~HeroFactory() = default;

    Hero* createHero() {
        switch (heroType) {
            case HeroType::HeroType_Mage:
                return new Mage(name, heroesConfig.mage_config);
            case HeroType::HeroType_Warrior:
                return new Warrior(name, heroesConfig.warrior_config);
            case HeroType::HeroType_God:
                return new God(name, heroesConfig.god_config);
        }
    }
};
