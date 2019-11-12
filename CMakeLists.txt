cmake_minimum_required(VERSION 3.13)
project(ants_vs_bees)

set(CMAKE_CXX_STANDARD 14)

add_executable(ants_vs_bees main.cpp Insect.h Ant.cpp Ant.h Bee.cpp Bee.h Fire.cpp Fire.h LongThrower.cpp LongThrower.h ShortThrower.cpp ShortThrower.h Wall.cpp Wall.h Ninja.cpp Ninja.h Bodyguard.cpp Bodyguard.h Harvester.cpp Harvester.h Thrower.cpp Thrower.h Game.cpp Game.h)