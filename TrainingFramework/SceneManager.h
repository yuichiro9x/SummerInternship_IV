#pragma once
#include <fstream>
#include <crtdbg.h>
#include <vector>
#include <map>
#include "box2d/b2_world.h"
#include"box2d/b2_body.h"
#include"box2d/b2_fixture.h"
#include"box2d/b2_circle_shape.h"
#include"box2d/b2_polygon_shape.h"
#include "Object.h"
#include "MainCharacter.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Terrain.h"
#include "Ground.h"
#include "Singleton.h"
#include "Boss.h"

class SceneManager : public Singleton<SceneManager> 
{
private:
	int wlow, whigh, hlow, hhigh;

	Ground * groundTest;
	std::vector<std::vector<Terrain*>> m_listTerrain;
	std::vector<Terrain*> m_ListBackground;
	std::vector<std::vector<int>> map;
	std::map<std::pair<int, int>, int> mapEnemy;
	std::map<std::pair<int, int>, std::pair<int, int>> mapLimit;
	std::vector<std::vector<int>> isInit;
	MainCharacter* m_MainCharacter;
	Boss* m_boss;
	std::vector<Bullet*> m_ListGunOfPlayer;
	std::vector<Bullet*> m_ListGunOfEnemy;
	std::vector<Bullet*> m_listBulletInWorld;
	std::vector<Enemy*> m_listEnemy;
	std::vector<Enemy*> m_listEnemyInWorld;
	Object * mainIcon;

	b2Filter filterMain, filterRoll;
	int m_direction;
	float m_Horizontal;
	float m_Vertical;
	float m_shoot;
	float m_changeGun;
	float m_time;
	float m_timeChangeGun;
	float m_time_roll;
	bool is_roll;
	int roll_step;
	int keyPressed;
	bool m_IsBossAppear;
	bool m_IsTowerDefend;

	bool m_bIsFighting = false;
	bool is_in_ground;
	Vector2 m_oTarget;
	char* m_fileSM;
	char* m_fileMAP;
	b2World * m_world;
	int jumpstep;
	int numJump;

	//ChangeToScreenRESULT
	bool m_bChangeScreen = false, m_bIsVictory = false;
public:
	int * indices;
	SceneManager();
	~SceneManager();

	void Init();
	void Update(float deltaTime);
	void Draw();
	void Key(unsigned char key, bool bIsPressed);
	void OnMouseButtonDown(int X, int Y, char Button);
	void OnMouseButtonUp(int X, int Y, char Button);
	void OnMouseButtonMove(int X, int Y, char Button);

	void AddGun(Bullet* gun);
	void AddBullet(Bullet* bullet);
	void RemoveBullet(int index);
	void AddEnemy(Enemy* enemy);

	bool enemySeen(Enemy* enemy);
	void CheckMovement();
	
	void Shoot();
	void ChangeGun(bool isEmptyBullet = true);
	void SetStateHellGun(Bullet* hellBullet, float enemyWidth);
	void EnemyAttack(Enemy* enemy);
	void BossAttack();

	void CleanUp();
	void ReadFile(FILE* f_SM);
	void ReadMap(FILE* f_MAP);
	void SetFileManager(char* fileSM, char* fileMAP);

	void ChangeToResultScreen(bool bIsVictory);
};





