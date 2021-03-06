#include "stdafx.h"
#include "GSLevel3.h"
#include "LoadingScreen.h"
#include "SceneManager.h"
#include "ResourceManager.h"
#include "Camera.h"

GSLevel3::GSLevel3() {
	
}

GSLevel3::~GSLevel3() {

}

void GSLevel3::Init() {

	//Init SM
	m_SM = new SceneManager(3);

	char* SM = "../Resources/Managers/SM3.txt";
	char* MAP = "../Resources/Map/maplv3.txt";
	m_SM->SetFileManager(SM, MAP);
	m_SM->Init();

	ResourceManager::GetInstance()->PlaySound("../Resources/Sounds/LoveIsBeautifulPain.mp3", true); // day, mp3 cung doc dc

	//Set Current State
	m_currentState = GSLEVEL3;
	Singleton<LoadingScreen>::GetInstance()->SetIsLoading(false);
}

void GSLevel3::Draw() {
	
	m_SM->Draw();

}

void GSLevel3::Update(float deltaTime) {
	
	m_SM->Update(deltaTime);
}

void GSLevel3::CleanUp() {
	m_SM->CleanUp();
	delete m_SM;

}

void GSLevel3::Resume() {
	ResourceManager::GetInstance()->StopAllSound();
	ResourceManager::GetInstance()->PlaySound("../Resources/Sounds/LoveIsBeautifulPain.mp3", true);
}

void GSLevel3::Pause() {
	ResourceManager::GetInstance()->StopAllSound();
}


//Events
void GSLevel3::HandleKeyEvents(unsigned char key, int X, int Y, bool bIsPressed) {
	m_SM->Key(key, bIsPressed);
	
}

void GSLevel3::OnMouseMoving(int X, int Y) {
}

void GSLevel3::OnMouseButtonDown(int X, int Y, char Button) {
	m_SM->OnMouseButtonDown(X, Y, Button);
}

void GSLevel3::OnMouseButtonUp(int X, int Y, char Button) {
	m_SM->OnMouseButtonUp(X, Y, Button);
}

void GSLevel3::OnMouseButtonMove(int X, int Y, char Button) {
	m_SM->OnMouseButtonMove(X, Y, Button);
}
