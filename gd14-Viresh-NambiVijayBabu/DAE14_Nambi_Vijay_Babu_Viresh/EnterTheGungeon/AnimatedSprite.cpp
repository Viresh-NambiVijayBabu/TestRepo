#include "pch.h"
#include "AnimatedSprite.h"
#include "Texture.h"
#include <iostream>

AnimatedSprite::AnimatedSprite(const std::string& filePath, int cols, int frames, float animationSpeed, float scale) :
	m_pTexture{ new Texture{filePath} },
	m_Frames{ frames }, m_Cols{ cols },
	m_AnimationSpeed{ animationSpeed },
	m_FrameTimer{ animationSpeed },
	m_Scale{scale}
{
	m_FrameWidth = m_pTexture->GetWidth() / m_Cols;
	m_FrameHeight = m_pTexture->GetHeight() / (m_Frames / m_Cols);
	
}

AnimatedSprite::~AnimatedSprite()
{
	delete m_pTexture;
}

void AnimatedSprite::Draw(const Vector2f& pos, bool isFlipped) const
{
	float widthOffset{ (m_FrameWidth * m_Scale) / 2 };
	float heightOffset{ (m_FrameHeight * m_Scale) / 2 };
	const Rectf sourceRect{ m_FrameWidth * (m_CurrentFrame%m_Cols), 
		m_FrameHeight * (m_CurrentFrame/m_Cols),
	m_FrameWidth, m_FrameHeight};
	glPushMatrix();
	{
		const Rectf destRect{ -widthOffset, -heightOffset, 
			m_FrameWidth* m_Scale, m_FrameHeight* m_Scale};
		glTranslatef(pos.x, pos.y, 0.f);
		if (isFlipped) {
			glScalef(-1.f, 1.f, 1.f);
		}
		m_pTexture->Draw(destRect, sourceRect);
	}
	glPopMatrix();
	
}

void AnimatedSprite::Update(float deltaTime)
{
	//::cout << m_CurrentRow;
	m_FrameTimer -= deltaTime;
	if (m_FrameTimer <= 0.f) {
		m_FrameTimer += m_AnimationSpeed;
		LoopRow();
	}
}

int AnimatedSprite::GetRow() const
{
	return m_CurrentRow;
}


void AnimatedSprite::SetRow(int row)
{
	m_CurrentRow = row;
	KeepFrameInRow();
}


void AnimatedSprite::LoopRow()
{
	++m_CurrentFrame;
	KeepFrameInRow();
	
}

void AnimatedSprite::KeepFrameInRow()
{
	if (m_CurrentFrame >= m_Cols * (m_CurrentRow + 1) or
		m_CurrentFrame < m_Cols * m_CurrentRow)
	{
		int currentCol = m_CurrentFrame % m_Cols;
		m_CurrentFrame = m_Cols * m_CurrentRow + currentCol;
	}
}
