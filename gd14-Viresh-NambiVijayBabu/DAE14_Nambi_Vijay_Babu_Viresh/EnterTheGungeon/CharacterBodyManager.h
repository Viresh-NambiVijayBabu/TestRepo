#pragma once
#include "CharacterBody.h"
#include <vector>
class CharacterBodyManager final
{
public:
	static CharacterBodyManager* GetCharacterBodyManager();
	
	~CharacterBodyManager();

	void DrawCharacterBodies() const;
	void UpdateCharacterBodies(float deltaTime);

	void PushCharacterBody(CharacterBody* body);

private:
	std::vector <CharacterBody*> m_CharacterBodies{};
};

