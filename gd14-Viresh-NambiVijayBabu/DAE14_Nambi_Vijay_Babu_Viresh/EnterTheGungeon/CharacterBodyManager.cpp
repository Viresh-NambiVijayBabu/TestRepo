#include "pch.h"
#include "CharacterBodyManager.h"
#include "Player.h"
#include "Gun.h"

CharacterBodyManager* CharacterBodyManager::GetCharacterBodyManager()
{
	static CharacterBodyManager characterBodyManager{};
	return &characterBodyManager;
}

CharacterBodyManager::~CharacterBodyManager()
{
	for (CharacterBody* body : m_CharacterBodies)
	{
		delete body;
	}
	
}



void CharacterBodyManager::DrawCharacterBodies() const
{
	static CharacterBody* pGun{};
	if (pGun != nullptr) {
		if (pGun->GetIsActive())
		{
			pGun->Draw();
		}
	}
	for (CharacterBody* body : m_CharacterBodies)
	{
		if (pGun == nullptr) {
			if (typeid(*body) == typeid(Pistol)) 
			{
				pGun = body;
			}
		}
		if (body->GetIsActive() and body != pGun)
		{
			body->Draw();
		}
		
	}
	
	
}

void CharacterBodyManager::UpdateCharacterBodies(float deltaTime)
{
	for (CharacterBody* body : m_CharacterBodies)
	{
		if (body->GetIsActive())
		{
			body->Update(deltaTime);
		}
		
	}
}

void CharacterBodyManager::PushCharacterBody(CharacterBody* body)
{
	m_CharacterBodies.push_back(body);
}
