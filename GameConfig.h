#pragma once

#include <fstream>
#include <string>

using namespace std;

class GameConfig {
public:
    static inline int mageHealth;
    static inline int mageDamage;

    static inline int warriorHealth;
    static inline int warriorDamage;

    static inline int godHealth;
    static inline int godDamage;

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

            mageHealth = stoi(mage_health);
            mageDamage = stoi(mage_damage);
            warriorHealth = stoi(warrior_health);
            warriorDamage = stoi(warrior_damage);
            godHealth = stoi(god_health);
            godDamage = stoi(god_damage);
        }
        else {
            throw "File could not be opened";
        }
    }
};