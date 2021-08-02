#include "Application.h"
#include "GameStateMachine.h"
#include "GameStatebase.h"
#include "ResourceManager.h"

Application::Application()
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}


Application::~Application()
{
}


void Application::Init()
{
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	GameStateMachine::GetInstance()->PushState(StateTypes::GS_LEVEL1);
}

void Application::Update(GLfloat deltaTime)
{
	GameStateMachine::GetInstance()->PerformStateChange();
	if (GameStateMachine::GetInstance()->HasState())
		GameStateMachine::GetInstance()->CurrentState()->Update(deltaTime);
}

void Application::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if (GameStateMachine::GetInstance()->HasState())
		GameStateMachine::GetInstance()->CurrentState()->Draw();
}


void Application::HandleKeyEvents(unsigned char key, GLint X, GLint Y, bool bIsPressed) {
	if (GameStateMachine::GetInstance()->HasState())
		GameStateMachine::GetInstance()->CurrentState()->HandleKeyEvents(key, X, Y, bIsPressed);
}
void Application::OnMouseButtonDown(GLint X, GLint Y, char Button) {
	if (GameStateMachine::GetInstance()->HasState());
	GameStateMachine::GetInstance()->CurrentState()->OnMouseButtonDown(X, Y, Button);
		
}
void Application::OnMouseButtonUp(GLint X, GLint Y, char Button) {
	if (GameStateMachine::GetInstance()->HasState());
	GameStateMachine::GetInstance()->CurrentState()->OnMouseButtonUp(X, Y, Button);
}
void Application::OnMouseButtonMove(GLint X, GLint Y, char Button) {
	if (GameStateMachine::GetInstance()->HasState());
	GameStateMachine::GetInstance()->CurrentState()->OnMouseButtonMove(X, Y, Button);
}
void Application::OnMouseMoving(GLint X, GLint Y) {
	if (GameStateMachine::GetInstance()->HasState());
	GameStateMachine::GetInstance()->CurrentState()->OnMouseMoving(X, Y);
}


void Application::Exit()
{
	ResourceManager::GetInstance()->CleanUp();
	if (GameStateMachine::GetInstance()->HasState());
	GameStateMachine::GetInstance()->CurrentState()->CleanUp();
	glDisable(GL_DEPTH_TEST);
	exit(0);
}
