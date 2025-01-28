#pragma once

#include <string>

#include "IGame.h"
#include "GameConfig.h"

#include "../Heroes/Hero.h"
#include "../HeroConfig/HeroesConfig.h"

#include "../Logger/ILogger.h"

using namespace std;

class Game : public IGame {
private:
    HeroesConfig heroes_config;
    ILogger* logger;

protected:
    Hero* hero;
    Hero* enemy;

public:
    Game(ILogger* logger) {
        this->logger = logger;
    }

    //FIXME
    void prepare(string heroName, HeroType heroType, string enemyName, HeroType enemyType) override {
        try {
            GameConfig::loadConfig("game.config");
            heroes_config = GameConfig::heroes_config;
            logger->logInfo("Load config - success");

            auto hero_factory = new HeroFactory(heroName, heroType, heroes_config);
            auto enemy_factory = new HeroFactory(enemyName, enemyType, heroes_config);

            hero = hero_factory->createHero();
            logger->logInfo("Create hero" + heroName);

            enemy = enemy_factory->createHero();
            logger->logInfo("Create enemy" + enemyName);
        } catch(string ex) {
            logger->logError(ex);
            throw ex;
        }
    }

    void run() override { //FIXME
        do {
            hero->attack(enemy);
            logger->logInfo("Hero attack -> enemy");
            if (enemy->isDead()) {
                logger->logInfo("Enemy is dead");
                break;
            }

            enemy->attack(hero);
            logger->logInfo("Enemy attack -> hero");
            if (hero->isDead()) {
                logger->logInfo("Hero is dead");
                break;
            }
        } while (true);
    }

    string getWinName() override {
        if (enemy->isDead()) {
            return  hero->getName();
        }

        if (hero->isDead()) {
            return  enemy->getName();
        }
    }
};
