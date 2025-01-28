#pragma once

#include <fstream>
#include <string>

#include "../HeroConfig/HeroesConfig.h"

using namespace std;

class GameConfig {
public:
    static inline HeroesConfig heroes_config;

    static void loadConfig(string file_path) {
        ifstream file;
        file.open(file_path);
        if (file.is_open()) {
            string str;
            getline(file,str);

            int pos = str.find('|');
            auto god_health = str.substr(0, pos);
            str = str.substr(pos + 1);

            pos = str.find('|');
            auto god_damage = str.substr(0, pos);
            str = str.substr(pos + 1);

            pos = str.find('|');
            auto mage_health = str.substr(0, pos);
            str = str.substr(pos + 1);

            pos = str.find('|');
            auto mage_damage = str.substr(0, pos);
            str = str.substr(pos + 1);

            pos = str.find('|');
            auto warrior_health = str.substr(0, pos);
            auto warrior_damage = str.substr(pos+1);

            heroes_config.mage_config.health = stoi(mage_health);
            heroes_config.mage_config.damage = stoi(mage_damage);

            heroes_config.warrior_config.health = stoi(warrior_health);
            heroes_config.warrior_config.damage = stoi(warrior_damage);

            heroes_config.god_config.health = stoi(god_health);
            heroes_config.god_config.damage = stoi(god_damage);
        }
        else {
            throw "File could not be opened";
        }
    }
};