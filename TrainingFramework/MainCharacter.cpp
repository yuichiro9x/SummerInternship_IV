#include "stdafx.h"
#include "MainCharacter.h"
#include "Camera.h"
#include "define.h"


void MainCharacter::SetHP(float hp) {
	if (hp > m_MaxHP) {
		m_HP = m_MaxHP;
	}
	else if (hp < 0) {
		m_HP = 0;
	}
	else {
		m_HP = hp;
	}
	Vector3 scale = m_redHp->GetScale();

	if (hp < 0) {
		m_redHp->SetScale(0);
	}
	else {
		float scalex = m_HP / m_MaxHP * m_redHp->GetScaleX();
		m_redHp->SetScale(scalex);
	}
}

void MainCharacter::SetMaxHP(float maxhp) {
	m_MaxHP = maxhp;
	m_HP = maxhp;
}

float MainCharacter::GetHP() {
	return m_HP;
}

void MainCharacter::Update()
{
	b2Vec2 pos = m_body->GetPosition();
	
	m_Position.x = pos.x;
	m_Position.y = pos.y;
		
	Vector3 posCamera = Camera::GetInstance()->GetPosition();
	float scalew = 1250;
	float scaleh = 900;

	m_whiteHp->SetPosition(posCamera.x - scalew, posCamera.y - scaleh, posCamera.z);
	m_redHp->SetPosition(posCamera.x - scalew, posCamera.y - scaleh, m_Position.z);

	UpdateWorld();
}

bool MainCharacter::isDie() {
	if (m_HP <= 0) {
		m_HP = 0;
		return true;
	}
	return false;
}

void MainCharacter::playDead(float deltaTime) {
	m_Model->updateDead(deltaTime);
}


void MainCharacter::SetBodyObject(float positionX, float positionY, b2World* world) {
	float w = m_spriteW / 2.5f, h = m_spriteH / 2.0f;
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(positionX, positionY);
	bodyDef.fixedRotation = true;
	m_body = world->CreateBody(&bodyDef);
	b2PolygonShape dynamicBox;
	b2Vec2 * vex = new b2Vec2[6];
	vex[0] = b2Vec2(-w, -h);
	vex[1] = b2Vec2(w, -h);
	vex[2] = b2Vec2(w, h - 1);
	vex[3] = b2Vec2(w - 1, h);
	vex[4] = b2Vec2(-w + 1, h);
	vex[5] = b2Vec2(-w, h-1);
	dynamicBox.Set(vex, 6);
	delete[] vex;

	b2FixtureDef fixtureDef;
	float area = m_spriteW * m_spriteH * 4.0f;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.filter.categoryBits = CATEGORY_PLAYER;
	fixtureDef.filter.maskBits = MASK_PLAYER;
	fixtureDef.filter.groupIndex = -1;
	fixtureDef.density = 6000.0f / area;
	fixtureDef.friction = 0;
	fixtureDef.userData.pointer = reinterpret_cast<uintptr_t>(this);
	m_body->CreateFixture(&fixtureDef);
	
}
void MainCharacter::resetAnimation(int type) {
	m_Model->getAnimation(type - 1)->resetAnimation();
}
void MainCharacter::resetGun() {
	m_Model->resetGun();
}

void MainCharacter::SetHPTexture(Healthy* healthy, bool isWhite) {
	if (isWhite) {
		m_whiteHp = healthy;
	}
	else {
		m_redHp = healthy;
	}
}

void MainCharacter::DrawHP() {
	m_whiteHp->Draw();
	m_redHp->Draw();
}

void MainCharacter::cleanHP()
{
	delete m_whiteHp;
	delete m_redHp;
}
