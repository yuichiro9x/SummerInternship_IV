#include "stdafx.h"
#include "GSLevel4.h"
#include "LoadingScreen.h"
#include "SceneManager.h"
#include "ResourceManager.h"
#include "Camera.h"

GSLevel4::GSLevel4() {
	
}

GSLevel4::~GSLevel4() {

}

void GSLevel4::Init() {

	//Init SM
	m_SM = new SceneManager(4);

	char* SM = "../Resources/Managers/SM4.txt";
	char* MAP = "../Resources/Map/maplv4.txt";
	m_SM->SetFileManager(SM, MAP);
	m_SM->Init();
	ResourceManager::GetInstance()->PlaySound("../Resources/Sounds/titan.mp3", false);
	ResourceManager::GetInstance()->StopAllSound();
	ResourceManager::GetInstance()->PlaySound("../Resources/Sounds/WindyHill.mp3", true); // day, mp3 cung doc dc

	//Set Current State
	m_currentState = GSLEVEL4;
	Singleton<LoadingScreen>::GetInstance()->SetIsLoading(false);
}

void GSLevel4::Draw() {
	
	m_SM->Draw();

}

void GSLevel4::Update(float deltaTime) {
	
	m_SM->Update(deltaTime);
}

void GSLevel4::CleanUp() {
	m_SM->CleanUp();
	delete m_SM;
}

void GSLevel4::Resume() {
	ResourceManager::GetInstance()->StopAllSound();
	ResourceManager::GetInstance()->PlaySound("../Resources/Sounds/WindyHill.mp3", true);
}

void GSLevel4::Pause() {
	ResourceManager::GetInstance()->StopAllSound();
}


//Events
void GSLevel4::HandleKeyEvents(unsigned char key, int X, int Y, bool bIsPressed) {
	m_SM->Key(key, bIsPressed);
	
}

void GSLevel4::OnMouseMoving(int X, int Y) {
}

void GSLevel4::OnMouseButtonDown(int X, int Y, char Button) {
	m_SM->OnMouseButtonDown(X, Y, Button);
}

void GSLevel4::OnMouseButtonUp(int X, int Y, char Button) {
	m_SM->OnMouseButtonUp(X, Y, Button);
}

void GSLevel4::OnMouseButtonMove(int X, int Y, char Button) {
	m_SM->OnMouseButtonMove(X, Y, Button);
}
