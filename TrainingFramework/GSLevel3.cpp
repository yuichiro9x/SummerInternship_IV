#include "GSLevel3.h"
#include "SceneManager.h"
#include "ResourceManager.h"
#include "Camera.h"
#include "stdlib.h"
#include "string.h"

GSLevel3::GSLevel3() {
	
}

GSLevel3::~GSLevel3() {

}

void GSLevel3::Init() {
	Camera::GetInstance()->i_state = 3;

	//Init SM
	m_SM = std::make_shared<SceneManager>(3);
	char* SM = "../Resources/Managers/SM3.txt";
	char* MAP = "../Resources/Map/maplv3.txt";
	m_SM->SetFileManager(SM, MAP);
	m_SM->Init();

	//ResourceManager::GetInstance()->PlaySound("../Resources/Sounds/WindyHill.mp3", true); // day, mp3 cung doc dc
}

void GSLevel3::Draw() {

	m_SM->Draw();

}

void GSLevel3::Update(float deltaTime) {
	m_SM->Update(deltaTime);
}

void GSLevel3::CleanUp() {
	ResourceManager::GetInstance()->CleanDump();
	m_SM->CleanUp();
	m_SM->FreeInstance();
}

void GSLevel3::Resume() {
	//Init();
	ResourceManager::GetInstance()->StopAllSound();
	//ResourceManager::GetInstance()->PlaySound("../Resources/Sounds/bg_MainMenu_Sound.wav", true);
}

void GSLevel3::Pause() {
	ResourceManager::GetInstance()->StopAllSound();
	//ResourceManager::GetInstance()->StopSound("../Resources/Sounds/bg_MainMenu_Sound.wav");
}


//Events
void GSLevel3::HandleKeyEvents(unsigned char key, int X, int Y, bool bIsPressed) {
	m_SM->Key(key, bIsPressed);
	if (!bIsPressed) {
		switch (key) {
		case KEY_NEW_STATE:
		case KEY_NEW_STATE + 32:
		{
			if (GameStateMachine::GetInstance()->HasInstance()) {
				GameStateMachine::GetInstance()->PushState(StateTypes::GS_LEVEL2);
			}
		}
		break;
		case KEY_BACK_STATE:
		case KEY_BACK_STATE + 32:
		{
			if (GameStateMachine::GetInstance()->GetIsCanPop()) {
				GameStateMachine::GetInstance()->PopState();
			}
		}
		break;
		}
	}
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
