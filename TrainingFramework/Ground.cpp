#include "stdafx.h"
#include "Ground.h"
#include "Camera.h"

void Ground::Init()
{
	InitWVP();
	Vertex * verticesData = new Vertex[m_numberOfVertex];
	for (int i = 0; i < (int)vertices.size(); ++i) {
		verticesData[i].pos = vertices[i].pos;
		verticesData[i].uv = vertices[i].uv;
	}
	int *indic = new int[m_numberOfIndices];
	for (int i = 0; i < (int)indices.size(); ++i) indic[i] = indices[i];
	glGenBuffers(1, &vboID);
	glBindBuffer(GL_ARRAY_BUFFER, vboID);
	glBufferData(GL_ARRAY_BUFFER, m_numberOfVertex * sizeof(Vertex), verticesData, GL_STATIC_DRAW);
	

	glGenBuffers(1, &iboID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_numberOfIndices * sizeof(int), indic, GL_STATIC_DRAW);
	
	delete[] verticesData;
	delete[] indic;
	vertices.clear();
	indices.clear();
}

void Ground::Draw()
{
	UpdateWVP();

	glBindBuffer(GL_ARRAY_BUFFER, vboID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboID);
	//Set Position
	if (m_shader->m_aPosition != -1)
	{
		glEnableVertexAttribArray(m_shader->m_aPosition);
		glVertexAttribPointer(m_shader->m_aPosition, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, pos));
	}

	//Set UV
	if (m_shader->m_aUV != -1)
	{
		glEnableVertexAttribArray(m_shader->m_aUV);
		glVertexAttribPointer(m_shader->m_aUV, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, uv));
	}

	//Set World Matrix
	if (m_shader->m_uWVP != -1)
	{
		glEnableVertexAttribArray(m_shader->m_uWVP);
		glUniformMatrix4fv(m_shader->m_uWVP, 1, GL_FALSE, (GLfloat*)m_WVP.m);
	}

	//Setting Texture Uniform
	if (m_shader->m_uTextures[0] != -1) {
		glBindTexture(GL_TEXTURE_2D, m_texture->mTextureId);
	}

	glDrawElements(GL_TRIANGLES, m_numberOfIndices, GL_UNSIGNED_INT, 0);


	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Camera::GetInstance()->iboId);
}

void Ground::InitWVP()
{
	m_WorldMatrix.SetScale(1, 1, 1);
	m_WVP = m_WorldMatrix * Camera::GetInstance()->GetViewMatrix();
}

void Ground::UpdateWVP()
{
	Matrix ma = Camera::GetInstance()->GetViewMatrix();
	m_WVP.m[3][0] = m_WorldMatrix.m[3][0] * ma.m[0][0] + ma.m[3][0];
	m_WVP.m[3][1] = m_WorldMatrix.m[3][1] * ma.m[1][1] + ma.m[3][1];
}

void Ground::addVertex(float spriteX, float spriteY, float spriteW, float spriteH, float textureW, float textureH, Vector2 origin)
{
	Vertex verticesData[4];
	origin.x = origin.x + 100.0f;
	origin.y = origin.y + 100.0f;

	Vector3 delta = Vector3(origin.x - spriteW / 2.0f, origin.y - spriteH / 2.0f, 0.0);
	verticesData[0].pos = Vector3(-spriteW / 2.0f, -spriteH / 2.0f, 0.0f) - delta;
	verticesData[1].pos = Vector3(spriteW / 2.0f, -spriteH / 2.0f, 0.0f) - delta;
	verticesData[2].pos = Vector3(-spriteW / 2.0f, spriteH / 2.0f, 0.0f) - delta;
	verticesData[3].pos = Vector3(spriteW / 2.0f, spriteH / 2.0f, 0.0f) - delta;
	verticesData[0].uv = Vector2(spriteX / textureW, (spriteY + spriteH) / textureH);
	verticesData[1].uv = Vector2((spriteX + spriteW) / textureW, (spriteY + spriteH) / textureH);
	verticesData[2].uv = Vector2(spriteX / textureW, spriteY / textureH);
	verticesData[3].uv = Vector2((spriteX + spriteW) / textureW, spriteY / textureH);

	int a = addNewV(verticesData[0]);
	int b = addNewV(verticesData[1]);
	int c = addNewV(verticesData[2]);
	int d = addNewV(verticesData[3]);

	indices.push_back(a);
	indices.push_back(b);
	indices.push_back(d);
	indices.push_back(a);
	indices.push_back(c);
	indices.push_back(d);
	m_numberOfIndices += 6;
}

int Ground::addNewV(Vertex v)
{
	++m_numberOfVertex;
	vertices.push_back(v);
	return (m_numberOfVertex - 1);
}

void Ground::setTexture(Texture * tex)
{
	m_texture = tex;
}

void Ground::setShader(Shaders * shader)
{
	m_shader = shader;
}
