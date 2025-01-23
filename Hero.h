#pragma once

#include <string>

using namespace std;

class Hero {
private:
    string name;
    int health;
    int damage;

protected:
    Hero(string name, int health, int damage) {
        this->health = health;
        this->damage = damage;
        this->name = name;
    }

public:
    string getName() const{
        return name;
    }

    void setHealth(int health) {
        if (health < 0) {
            this->health = 0;
        } else {
            this->health = health;
        }
    }
    int getHealth() const{
        return health;
    }

    int getDamage() const{
        return damage;
    }

    bool isDead() const {
        return health <= 0;
    }

    virtual void attack(Hero* enemy) {
        auto new_health = enemy->getHealth() - damage;
        enemy->setHealth(new_health);
    }
};
