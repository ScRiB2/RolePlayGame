cmake_minimum_required(VERSION 3.14)
project(RPG)

set(CMAKE_CXX_STANDARD 17)

add_executable(RPG main.cpp item/Item.cpp item/Item.h item/weapons/Weapon.cpp item/weapons/Weapon.h item/weapons/WeaponTypes.h item/weapons/pistols/Pistol.cpp item/weapons/pistols/Pistol.h item/weapons/rifle/Rifle.cpp item/weapons/rifle/Rifle.h item/weapons/shotgun/Shotgun.cpp item/weapons/shotgun/Shotgun.h item/upgrades/IAim.h)