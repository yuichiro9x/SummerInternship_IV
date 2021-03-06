#include "stdafx.h"
#include "GSResult.h"
#include "Globals.h"
#include "ResourceManager.h"
#include "TextManager.h"
#include "GameplayUI.h"

GSResult::GSResult() {
}

GSResult::GSResult(bool isVictory, int currentLevel) {
	m_currentLevel = currentLevel;
	m_bIsVictory = isVictory;
}

GSResult::~GSResult() {

}

void GSResult::Init() {
	//Manager Initialize
	

	//Buttons
	char* BM = "../Resources/Managers/BM_Result.txt";
	m_BM = std::make_shared<ButtonManager>(BM, m_currentLevel);
	if(m_bIsVictory){
		if(m_currentLevel != 4) ResourceManager::GetInstance()->PlaySound("../Resources/Sounds/victory.mp3", false);
		for (register int i = 0; i < size_as_int(m_BM->m_listButton); ++i) {
			if (m_BM->m_listButton[i]->GetID() == 1) m_BM->m_listButton[i]->SetActive(true);
			else if(m_BM->m_listButton[i]->GetID() == 0) m_BM->m_listButton[i]->SetActive(false);
		}
	}
	else {
		ResourceManager::GetInstance()->PlaySound("../Resources/Sounds/lose.mp3", false);
	}

	Models * model = ResourceManager::GetInstance()->GetModelAtID(0);

	//Background Initialize
	m_Background = std::make_shared<Sprite2D>(0);
	m_Background->setModel(model);
	m_Background->setShader(ResourceManager::GetInstance()->GetShaderAtID(0));
	m_Background->SetTexture(ResourceManager::GetInstance()->GetTextureAtID(36));
	m_Background->Set2DPosition(Globals::screenWidth / 2, Globals::screenHeight / 2);
	m_Background->SetSize(Globals::screenWidth, Globals::screenHeight);

	//Frame Initialize
	m_Frame = std::make_shared<Sprite2D>(0);
	m_Frame->setModel(model);
	m_Frame->setShader(ResourceManager::GetInstance()->GetShaderAtID(0));
	if (m_bIsVictory) {
		m_Frame->SetTexture(ResourceManager::GetInstance()->GetTextureAtID(34));
	} else m_Frame->SetTexture(ResourceManager::GetInstance()->GetTextureAtID(35));
	
	m_Frame->Set2DPosition(Globals::screenWidth / 2, Globals::screenHeight / 2);
	m_Frame->SetSize(Globals::screenWidth / 2, Globals::screenHeight / 2 - 50);

	if(m_currentLevel != 4 || !m_bIsVictory) ResourceManager::GetInstance()->PlaySound("../Resources/Sounds/bg_PlayAgain_Sound.wav", true);

	//Set Current State
	m_currentState = GSRESULT;
}

void GSResult::Draw() {
	m_Background->Draw();
	m_Frame->Draw();
	m_BM->Draw();
}

void GSResult::Update(float deltaTime) {
}

void GSResult::CleanUp() {
	m_Frame->CleanUp();
	m_BM->CleanUp();
}

void GSResult::Resume() {
	ResourceManager::GetInstance()->StopAllSound();
	ResourceManager::GetInstance()->PlaySound("../Resources/Sounds/bg_PlayAgain_Sound.wav", true);
}

void GSResult::Pause() {
	ResourceManager::GetInstance()->StopAllSound();
}


//Events
void GSResult::HandleKeyEvents(unsigned char key, int X, int Y, bool bIsPressed) {
	//m_SM->Key(key, bIsPressed);
	
}

void GSResult::OnMouseMoving(int X, int Y) {
}

void GSResult::OnMouseButtonDown(int X, int Y, char Button) {
	//m_SM->OnMouseButtonDown(X, Y, Button);
}

void GSResult::OnMouseButtonUp(int X, int Y, char Button) {
	m_BM->OnMouseButtonUp(X, Y, Button);
}

void GSResult::OnMouseButtonMove(int X, int Y, char Button) {
	//m_SM->OnMouseButtonMove(X, Y, Button);
}
