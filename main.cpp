#include <iostream>

#include "Game/Game.h"
#include "Game/GameConfig.h"

#include "HeroFactory/HeroFactory.h"

using namespace std;

void PrintHeroInfo(Hero* hero);

int main() {
    GameConfig::loadConfig("game.config");

    auto hero_factory = new HeroFactory("HERO", HeroType::HeroType_Mage, GameConfig::heroes_config);
    auto enemy_factory = new HeroFactory("ENEMY", HeroType::HeroType_God, GameConfig::heroes_config);

    auto hero = hero_factory->createHero();
    auto enemy = enemy_factory->createHero();

    PrintHeroInfo(hero);
    PrintHeroInfo(enemy);

    auto game = new Game(hero, enemy);
    game->run();
    cout << game->getWinName() << " YOU WIN" << endl;

    return 0;
}

void PrintHeroInfo(Hero* hero) {
    cout << "*** *** ***" << endl;
    cout << "Name: " << hero->getName() << endl;
    cout << "HEALTH: " << hero->getHealth() << endl;
    cout << "DAMAGE: " << hero->getDamage() << endl;
    cout << "*** *** ***" << endl;
    cout << endl;
}