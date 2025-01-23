cmake_minimum_required(VERSION 3.30)
project(Heroes)

set(CMAKE_CXX_STANDARD 20)

add_executable(Heroes main.cpp
        Hero.h
        Mage.h
        Warrior.h
        Game.h
        HeroFactory.h
        God.h
        HeroType.h
        GameConfig.h)
