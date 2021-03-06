#include "stdafx.h"
#include "GSLevel2.h"
#include "LoadingScreen.h"
#include "SceneManager.h"
#include "ResourceManager.h"
#include "Camera.h"

GSLevel2::GSLevel2() {
	
}

GSLevel2::~GSLevel2() {

}

void GSLevel2::Init() {

	//Init SM
	m_SM = new SceneManager(2);

	char* SM = "../Resources/Managers/SM2.txt";
	char* MAP = "../Resources/Map/maplv2.txt";
	m_SM->SetFileManager(SM, MAP);
	m_SM->Init();
	ResourceManager::GetInstance()->PlaySound("../Resources/Sounds/SotsugyouMemories.mp3", true);

	//Set Current State
	m_currentState = GSLEVEL2;
	Singleton<LoadingScreen>::GetInstance()->SetIsLoading(false);
}

void GSLevel2::Draw() {
	
	m_SM->Draw();
}

void GSLevel2::Update(float deltaTime) {
	
	m_SM->Update(deltaTime);
}

void GSLevel2::CleanUp() {
	m_SM->CleanUp();
	delete m_SM;
}

void GSLevel2::Resume() {
	ResourceManager::GetInstance()->StopAllSound();
	ResourceManager::GetInstance()->PlaySound("../Resources/Sounds/SotsugyouMemories.mp3", true);
}

void GSLevel2::Pause() {
	ResourceManager::GetInstance()->StopAllSound();
}


//Events
void GSLevel2::HandleKeyEvents(unsigned char key, int X, int Y, bool bIsPressed) {
	m_SM->Key(key, bIsPressed);
	
}

void GSLevel2::OnMouseMoving(int X, int Y) {
}

void GSLevel2::OnMouseButtonDown(int X, int Y, char Button) {
	m_SM->OnMouseButtonDown(X, Y, Button);
}

void GSLevel2::OnMouseButtonUp(int X, int Y, char Button) {
	m_SM->OnMouseButtonUp(X, Y, Button);
}

void GSLevel2::OnMouseButtonMove(int X, int Y, char Button) {
	m_SM->OnMouseButtonMove(X, Y, Button);
}
