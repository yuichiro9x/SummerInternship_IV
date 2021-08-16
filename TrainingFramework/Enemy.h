#pragma once
#include "Object.h"
#include "Bullet.h"

class Enemy :
	public Object
{
private:
	float m_HP;
	float m_speedx;
	float m_speedy;
	float m_attackDame;
	float m_time;
	float m_left;
	float m_right;
	Bullet* m_bullet;
public:
	Enemy(int ID) : Object(ID) {}
	void SetHP(float hp);
	float GetHP();
	void SetSpeed(float speedx, float speedy);
	Vector2 GetSpeed();
	bool isDie();
	bool isAttack();

	void UpdateAttack(float deltaTime);
	void Update(float deltaTime);
	void SetLimit(float left, float right);
	void SetBullet(Bullet* bullet);
	void SetBodyObject(float positionX, float positionY, b2World* world);
	bool checkDraw();

	Bullet* GetBullet();
};