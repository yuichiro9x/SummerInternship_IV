#include "GameplayUI.h"
#include "Globals.h"
#include "ResourceManager.h"
#include <iostream>
#include "TextManager.h"

GameplayUI::GameplayUI() {

}

GameplayUI::~GameplayUI() {

}

void GameplayUI::Init() {
	//Manager Initialize
	ResourceManager::GetInstance()->Init();
	Singleton<TextManager>::GetInstance()->Initialize();
	char* BM = "../Resources/Managers/BM_Gameplay.txt";
	m_BM = std::make_shared<ButtonManager>(BM);
}

void GameplayUI::Draw() {
	//m_BM->Draw();

	//MainCharacter
	char buffer[20];

	//HP
	_itoa(m_MainCharacter->GetHP(), buffer, 10);
	char text[20] = " ";
	strcat_s(text, buffer);
	Singleton<TextManager>::GetInstance()->RenderString(text, Vector4(0.0f, 1.0f, 0.0f), 10.0f, 700.0f, 1.0f, 1.0f);

	//Bullet
	_itoa(m_NumberOfBullets1, buffer, 10);
	strcpy(text, " ");
	strcat_s(text, buffer);
	Singleton<TextManager>::GetInstance()->RenderString(text, Vector4(0.0f, 1.0f, 1.0f), 50.0f, 650.0f, 1.0f, 1.0f);

	_itoa(m_NumberOfBullets2, buffer, 10);
	strcpy(text, " ");
	strcat_s(text, buffer);
	Singleton<TextManager>::GetInstance()->RenderString(text, Vector4(0.0f, 1.0f, 1.0f), 50.0f, 610.0f, 1.0f, 1.0f);
	//Boss
	//if (m_pBossAppear == true) {
	//	_itoa(m_Boss->GetHP(), buffer, 10);
	//	strcpy(text, "BOSS: ");
	//	strcat_s(text, buffer);
	//	Singleton<TextManager>::GetInstance()->RenderString(text, Vector4(1.0f, 0.0f, 0.0f), 360.0f , 600.0f, 2.0f, 2.0f);
	//}
}

void GameplayUI::SetMainCharacter(MainCharacter* mainCharacter)
{
	m_MainCharacter = mainCharacter;
}

void GameplayUI::SetBoss(Boss* boss)
{
	m_Boss = boss;
	m_pBossAppear = true;
}

void GameplayUI::SetBossAppear(bool IsAppear)
{
	m_pBossAppear = IsAppear;
}

void GameplayUI::SetNumberOfBullets(int numberOfBullets1, int numberOfBullets2)
{
	m_NumberOfBullets1 = numberOfBullets1;
	m_NumberOfBullets2 = numberOfBullets2;
}

void GameplayUI::Update(float deltaTime) {
	m_BM->Update(deltaTime);
}

void GameplayUI::CleanUp() {
	m_BM->CleanUp();
}

void GameplayUI::Resume() {

}

void GameplayUI::Pause() {
	
}


//Events
void GameplayUI::HandleKeyEvents(unsigned char key, int X, int Y, bool bIsPressed) {
	//m_SM->Key(key, bIsPressed);
	if (!bIsPressed) {
		switch (key) {
		case KEY_NEW_STATE:
		case KEY_NEW_STATE + 32:
		{

		}
		break;
		case KEY_BACK_STATE:
		case KEY_BACK_STATE + 32:
		{

		}
		break;
		}
	}
}

void GameplayUI::OnMouseMoving(int X, int Y) {
}

void GameplayUI::OnMouseButtonDown(int X, int Y, char Button) {
	//m_SM->OnMouseButtonDown(X, Y, Button);
}

void GameplayUI::OnMouseButtonUp(int X, int Y, char Button) {
	m_BM->OnMouseButtonUp(X, Y, Button);
}

void GameplayUI::OnMouseButtonMove(int X, int Y, char Button) {
	//m_SM->OnMouseButtonMove(X, Y, Button);
}