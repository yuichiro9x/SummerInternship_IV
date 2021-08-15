#pragma once
#include "../Utilities/Math.h"

struct Vertex 
{
	Vertex();
	Vertex(const Vertex &v);
	Vector3 pos;

	//Vector3 norm;
	//Vector3 binorm;
	//Vector3 tgt;
	Vector2 uv;
	Vector3 color;
	
};