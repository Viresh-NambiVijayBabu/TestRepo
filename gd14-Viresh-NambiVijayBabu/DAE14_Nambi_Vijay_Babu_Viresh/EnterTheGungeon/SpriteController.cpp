#include "pch.h"
#include "SpriteController.h"
#include "AnimatedSprite.h"
#include <iostream>

SpriteController::SpriteController(float scale) :
m_Scale{scale}
{
}

SpriteController::~SpriteController()
{
	for (AnimatedSprite* sprite : m_AnimatedSprites)
	{
		delete sprite;
	}
}

void SpriteController::DrawActiveSprite(const Vector2f& pos) const
{
	m_AnimatedSprites[m_ActiveSpriteIdx]->Draw(pos, m_IsFlipped);
}

void SpriteController::UpdateActiveSprite(float deltaTime)
{
	m_AnimatedSprites[m_ActiveSpriteIdx]->Update(deltaTime);
}

bool SpriteController::GetIsFlipped() const
{
	return m_IsFlipped;
}

int SpriteController::GetActiveSpriteIndex() const
{
	return m_ActiveSpriteIdx;
}

void SpriteController::SetActiveSprite(int index)
{
	
	int currentRow{ m_AnimatedSprites[m_ActiveSpriteIdx]->GetRow() };
	m_ActiveSpriteIdx = index;
	m_AnimatedSprites[m_ActiveSpriteIdx]->SetRow(currentRow);
	
}

void SpriteController::SetRow(int value)
{
	m_AnimatedSprites[m_ActiveSpriteIdx]->SetRow(value);
}

void SpriteController::SetIsFlipped(bool value)
{
	m_IsFlipped = value;
}

void SpriteController::PushAnimatedSprite(const std::string& filePath, int cols, int frames, float animationSpeed)
{
	AnimatedSprite* animatedSprite{ new AnimatedSprite{filePath, cols, frames, animationSpeed, m_Scale} };
	m_AnimatedSprites.push_back(animatedSprite);
}

