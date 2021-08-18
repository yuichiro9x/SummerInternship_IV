#include "Boss.h"
#include "Camera.h"
#include "define.h"

void Boss::SetHP(float hp) {
	m_HP = hp;
}

void Boss::SetMaxHP(float maxhp) {
	m_MaxHP = maxhp;
	m_HP = maxhp;
	m_isMove = true;
}

float Boss::GetHP() {
	return m_HP;
}

void Boss::SetSpeed(float speedx, float speedy) {
	m_speedx = speedx;
	m_speedy = speedy;
}

int Boss::GetNumOfBullet() {
	if (m_HP * 2 > m_MaxHP) {
		return 3;
	}
	return 5;
}

void Boss::SetTarget(b2Body* target) {
	m_target = target;
}

Vector2 Boss::GetSpeed() {
	return Vector2(m_speedx, m_speedy);
}

void Boss::SetDestiny(float destiny) {
	m_destiny = destiny;
}

float Boss::GetDestiny() {
	return m_destiny;
}

void Boss::UpdateAttack(float deltaTime) {
	m_time += deltaTime;
}

void Boss::Update(float deltaTime)
{
	m_Position.x = m_body->GetPosition().x;
	m_Position.y = m_body->GetPosition().y;

	//if (m_Position.y <= m_high || m_Position.y >= m_low) {
	//	m_body->SetLinearVelocity(b2Vec2(0, 0));
	//}


	Matrix translationMatrix, scaleMatrix;
	translationMatrix.SetTranslation(m_Position);
	scaleMatrix.SetScale(m_Scale);
	m_WorldMatrix = scaleMatrix * translationMatrix;
}

void Boss::SetLimit(float left, float right) {
	m_left = left;
	m_right = right;
}

bool Boss::isDie() {
	if (m_HP <= 0) {
		return true;
	}
	return false;
}

void Boss::SwapGun() {
	Bullet* bullet = m_listBullet[0];
	m_listBullet.erase(m_listBullet.begin());
	m_listBullet.push_back(bullet);
}

bool Boss::isAttack() {
	if (m_time >= m_ListAttackSpeed[0]) {
		float attackspeed = m_ListAttackSpeed[0];
		m_time = 0;
		m_ListAttackSpeed.erase(m_ListAttackSpeed.begin());
		m_ListAttackSpeed.push_back(attackspeed);
		return true;
	}
	return false;
}

void Boss::AddBullet(Bullet* bullet) {
	m_time = 0;
	m_listBullet.push_back(bullet);
}

void Boss::SetBodyObject(float positionX, float positionY, b2World* world) {
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(positionX, positionY);
	m_body = world->CreateBody(&bodyDef);
	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(m_spriteW / 2, m_spriteH / 2);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = 0;
	//	fixtureDef.density = 1;
	fixtureDef.filter.categoryBits = CATEGORY_ENEMY;
	fixtureDef.filter.maskBits = MASK_ENEMY;
	m_body->CreateFixture(&fixtureDef);
	m_body->SetLinearVelocity(b2Vec2(m_speedx, m_speedy));
}

Bullet* Boss::GetBullet() {
	return m_listBullet[0];
}