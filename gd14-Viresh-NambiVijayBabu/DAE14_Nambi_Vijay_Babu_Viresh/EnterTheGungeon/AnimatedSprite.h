#pragma once
class Texture;
#include "Vector2f.h"


class AnimatedSprite final
{
public:
	explicit AnimatedSprite(const std::string& filePath, int cols, int frames, float animationSpeed, float scale = 3.f);
	~AnimatedSprite();

	void Draw(const Vector2f& pos, bool isFlipped = false) const;
	void Update(float deltaTime);
	
	int GetRow() const;
	
	void SetRow(int row);
	

private:
	Texture* m_pTexture{};
	const float m_Scale{ 3.f };
	int m_Frames{};
	int m_Cols{};

	float m_FrameWidth{};
	float m_FrameHeight{};
	
	const float m_AnimationSpeed{};
	int m_CurrentRow{};
	int m_CurrentFrame{};
	float m_FrameTimer{};
	

	void LoopRow();
	void KeepFrameInRow();
};

