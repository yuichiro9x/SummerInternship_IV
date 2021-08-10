#pragma once
#include "../Utilities/utilities.h" // if you use STL, please include this line AFTER all other include

#define PI 3.1459f

#define LMB 0
#define RMB 1

//key value
#define KEY_JUMP 'W'
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

// bullet categories
#define CATEGORY_QUICK_PISTOL 1
#define CATEGORY_HEAVY_PISTOL 2
#define CATEGORY_BAZOKA 3
#define CATEGORY_HELL_GUN 4
#define CATEGORY_BOOMERANG 5

// filter catefories
#define CATEGORY_TERRAIN 1
#define CATEGORY_PLAYER 1 << 1
#define CATEGORY_BULLET_PLAYER 1 << 2
#define CATEGORY_ENEMY 1 << 3
#define CATEGORY_BULLET_ENEMY 1 << 4

// mask
#define MASK_TERRAIN CATEGORY_PLAYER | CATEGORY_BULLET_PLAYER | CATEGORY_ENEMY | CATEGORY_BULLET_ENEMY
#define MASK_PLAYER CATEGORY_TERRAIN | CATEGORY_ENEMY | CATEGORY_BULLET_ENEMY
#define MASK_BULLET_PLAYER CATEGORY_TERRAIN | CATEGORY_ENEMY
#define MASK_ENEMY CATEGORY_PLAYER | CATEGORY_TERRAIN | CATEGORY_BULLET_PLAYER
#define MASK_BULLET_ENEMY CATEGORY_TERRAIN | CATEGORY_PLAYER