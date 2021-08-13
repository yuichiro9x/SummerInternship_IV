#pragma once
#include "Vertex.h"
#include "../Utilities/Math.h"

enum AnimationType {
	base,
	Idle,
	Run,
	Jump,
	RunJump,
	Falling,
	Gun0,
	Gun1,
	Gun2,
	Gun3
};

class Animation
{
public:
	Animation(const char* filePath);
	~Animation();

	void play(GLuint* vbo, Vector2 Tsize, Vector2 origin, float deltaTime, bool revert = false);

	void setAnimationSpeed(float newSpeed);
	void setID(int id);
	int GetID(){
		return m_ID;
	}
	void resetAnimation();
	void setFire(int fire);
	bool isGun;
private:
	bool isJump;
	double d_anim_cursor;
	int i_current_frame_index;
	int i_frame_count;
	float f_speed;
	Vector4* m_animation;
	int m_ID;
	int m_fire_pos;
};

