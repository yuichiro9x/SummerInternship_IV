#pragma once
#include "../Utilities/utilities.h" // if you use STL, please include this line AFTER all other include

#define PI 3.1459f

#define LMB 0
#define RMB 1

// number of max bullet
#define NUM_BULLET 4

// texture hp
#define WHITE 28
#define RED 29
#define BOSS_ICON 30

// size of 
#define WIDTH 200.0f

//key value
#define KEY_JUMP 'W'
#define KEY_JUMP2 32
#define KEY_LEFT 'A'
#define KEY_RIGHT 'D'
#define KEY_CHANGE_GUN 'I'
#define KEY_SHOOT 'O'

// key
#define MOVE_JUMP 1
#define MOVE_LEFT 1 << 1
#define MOVE_RIGHT 1 << 2
#define CHANGE_GUN 1 << 3
#define SHOOT 1 << 4
#define ROLL 1 << 5

// bullet categories
#define CATEGORY_QUICK_PISTOL 6
#define CATEGORY_BAZOKA 7
#define CATEGORY_HELL_GUN 8
#define CATEGORY_BOOMERANG 9

// bullet enemy
#define CATEGORY_ENEMY_GUN 10
#define CATEGORY_FOLLOW_GUN 11
#define CATEGORY_RADIATE_GUN 12
#define CATEGORY_BAZOKA_ENEMY 13
#define CATEGORY_BOSS_GUN 14

// filter catefories
#define CATEGORY_TERRAIN 1
#define CATEGORY_PLAYER 1 << 1
#define CATEGORY_BULLET_PLAYER 1 << 2
#define CATEGORY_ENEMY 1 << 3
#define CATEGORY_BULLET_ENEMY 1 << 4
#define CATEGORY_SLOW_TRAP 1 << 5
#define CATEGORY_BOSS 1 << 6
#define CATEGORY_BULLET_BOSS 1 << 7

// mask
#define MASK_TERRAIN CATEGORY_PLAYER | CATEGORY_BULLET_PLAYER | CATEGORY_ENEMY | CATEGORY_BULLET_ENEMY
#define MASK_PLAYER CATEGORY_TERRAIN | CATEGORY_ENEMY | CATEGORY_BULLET_ENEMY | CATEGORY_SLOW_TRAP | CATEGORY_BOSS | CATEGORY_BULLET_BOSS
#define MASK_BULLET_PLAYER CATEGORY_TERRAIN | CATEGORY_ENEMY | CATEGORY_SLOW_TRAP | CATEGORY_BOSS
#define MASK_ENEMY CATEGORY_PLAYER | CATEGORY_TERRAIN | CATEGORY_BULLET_PLAYER | CATEGORY_SLOW_TRAP
#define MASK_BULLET_ENEMY CATEGORY_TERRAIN | CATEGORY_PLAYER | CATEGORY_SLOW_TRAP
#define MASK_SLOW_TRAP CATEGORY_PLAYER | CATEGORY_BULLET_PLAYER | CATEGORY_ENEMY | CATEGORY_BULLET_ENEMY
#define MASK_BOSS CATEGORY_PLAYER | CATEGORY_BULLET_PLAYER
#define MASK_BULLET_BOSS CATEGORY_PLAYER

//State Number
#define GSINTRO 999
#define GSMAINMENU 0
#define GSLEVEL1 1
#define GSLEVEL2 2
#define GSLEVEL3 3
#define GSLEVEL4 4
#define GSLOADLEVEL 5
#define GSRESULT 6
#define GSOPTIONS 7
#define GSABOUTUS 8