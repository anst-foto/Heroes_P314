cmake_minimum_required(VERSION 3.30)
project(Heroes)

set(CMAKE_CXX_STANDARD 20)

add_executable(Heroes main.cpp
        Heroes/Hero.h
        Heroes/Mage.h
        Heroes/Warrior.h
        Game/Game.h
        HeroFactory/HeroFactory.h
        Heroes/God.h
        HeroFactory/HeroType.h
        Game/GameConfig.h
        HeroConfig/HeroesConfig.h
        HeroConfig/HeroConfig.h
        Logger/ILogger.h
        Logger/LogToConsole.h
        Logger/LogToFile.h
        Game/IGame.h
)
