#include "MainCharacter.h"
#include "Camera.h"
#include "define.h"


void MainCharacter::SetHP(float hp) {
	m_HP = hp;
}

float MainCharacter::GetHP() {
	return m_HP;
}

void MainCharacter::Update(float deltaTime)
{
	m_Position.x = m_body->GetPosition().x;
	m_Position.y = m_body->GetPosition().y;
	Camera::GetInstance()->SetPosition(m_Position.x, m_Position.y);
	Camera::GetInstance()->SetTarget(m_Position.x, m_Position.y, 0.0f);
	if (m_Model->b_IsAnimation == true) {
		m_Model->updateAnimation(deltaTime, m_current_anim);
	}
	Matrix translationMatrix, scaleMatrix;
	translationMatrix.SetTranslation(m_Position);
	scaleMatrix.SetScale(m_Scale);
	m_WorldMatrix = scaleMatrix * translationMatrix;
	UpdateWVP();
}

bool MainCharacter::isDie() {
	if (m_HP <= 0) {
		return true;
	}
	return false;
}


void MainCharacter::SetBodyObject(float positionX, float positionY, b2World* world) {
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(positionX, positionY);
	m_body = world->CreateBody(&bodyDef);
	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(m_spriteW, m_spriteH);
	b2FixtureDef fixtureDef;
	float area = m_spriteW * m_spriteH * 4.0f;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.filter.categoryBits = CATEGORY_PLAYER;
	fixtureDef.filter.maskBits = MASK_PLAYER;
	fixtureDef.density = 5000.0f / area;
	m_body->CreateFixture(&fixtureDef);
}
