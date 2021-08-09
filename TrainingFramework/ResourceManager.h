#pragma once
#include <fstream>
#include <crtdbg.h>
#include "Object.h"
#include <vector>
#include "soloud.h"
#include "soloud_wav.h"
#include <map>

class ResourceManager
{
private:
	static ResourceManager* s_Instance;
	std::vector<Model*> m_Models;
	std::vector<Texture*> m_Textures;
	std::vector<Shaders*> m_Shaders;
	std::vector<Animation*> m_Animations;

	std::map<std::string, std::shared_ptr<SoLoud::Wav>> m_MapWave; //TruongNV - Add Map Sound
	//std::string m_SoundPath; //Truong NV - Add SoundPath
	SoLoud::Soloud m_Soloud; //Truong NV - Engine Core
public:
	ResourceManager();
	~ResourceManager();

	void Init();
	void CleanUp();
	void ReadFile(FILE* f_RM);
	Model* GetModelAtID(int ID);
	Animation* GetAnimationAtID(int ID);
	Texture* GetTextureAtID(int ID);
	Shaders* GetShaderAtID(int ID);

	//TruongNV - Add Function Sound
	void AddSound(const std::string& name);
	void PlaySound(const std::string& name, bool loop = false);
	void StopSound(const std::string& name);
	void StopAllSound();

	static ResourceManager* GetInstance();

	
};





