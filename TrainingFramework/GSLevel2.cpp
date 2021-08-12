#include "GSLevel2.h"
#include "SceneManager.h"
#include "ResourceManager.h"
#include "Camera.h"

GSLevel2::GSLevel2() {
	char* SM = "../Resources/Managers/SM2.txt";
	char* MAP = "../Resources/Map/tilemapr.txt";
	m_SM = m_SM = std::make_shared<SceneManager>(SM, MAP);
}

GSLevel2::~GSLevel2() {

}

void GSLevel2::Init() {
	m_SM->SetFileManager("../Resources/Managers/SM2.txt", "../Resources/Map/tilemapr.txt");
	m_SM->Init();
	ResourceManager::GetInstance()->PlaySound("../Resources/Sounds/FutariNoKimochi.mp3", true);

	auto bullet = std::make_shared<Bullet>(1);
	m_ListBullet.push_back(bullet);

}

void GSLevel2::Draw() {
	Camera::GetInstance()->i_state = 2;
	m_SM->Draw();
}

void GSLevel2::Update(float deltaTime) {
	m_SM->Update(deltaTime);
}

void GSLevel2::CleanUp() {
	m_SM->CleanUp();
	
}

void GSLevel2::Resume() {
	ResourceManager::GetInstance()->StopAllSound();
	ResourceManager::GetInstance()->PlaySound("../Resources/Sounds/bg_Play_Sound.wav", true);
}

void GSLevel2::Pause() {
	ResourceManager::GetInstance()->StopAllSound();
}


//Events
void GSLevel2::HandleKeyEvents(unsigned char key, int X, int Y, bool bIsPressed) {
	m_SM->Key(key, bIsPressed);
	if (!bIsPressed) {
		switch (key) {
		case KEY_NEW_STATE:
		case KEY_NEW_STATE + 32:
		{
			if (GameStateMachine::GetInstance()->HasInstance()) {
				GameStateMachine::GetInstance()->PushState(StateTypes::GS_LEVEL1);
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
