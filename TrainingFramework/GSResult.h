#pragma once
#include "GameStateBase.h"
class GSResult :
    public GameStateBase
{
	std::shared_ptr<ButtonManager> m_BM;
	std::shared_ptr<Sprite2D> m_Background;
	std::shared_ptr<Sprite2D> m_Frame;
	bool m_bIsVictory;
	int m_currentLevel;
public:
	GSResult();
	GSResult(bool isVictory, int currentLevel);
	~GSResult(void);

	void Init();
	void Update(float deltaTime);
	void CleanUp();

	void Pause();
	void Resume();

	void HandleKeyEvents(unsigned char key, int X, int Y, bool bIsPressed);
	void OnMouseButtonDown(int X, int Y, char Button);
	void OnMouseButtonUp(int X, int Y, char Button);
	void OnMouseButtonMove(int X, int Y, char Button);
	void OnMouseMoving(int X, int Y);

	void Draw();
};

