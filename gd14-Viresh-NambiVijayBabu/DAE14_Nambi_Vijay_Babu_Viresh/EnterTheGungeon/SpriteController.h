#pragma once
#include <vector>
class AnimatedSprite;

class SpriteController
{
public:
	explicit SpriteController(float scale = 3.f);
	~SpriteController();
	void DrawActiveSprite(const Vector2f& pos) const;
	void UpdateActiveSprite(float deltaTime);
	bool GetIsFlipped() const;
	int GetActiveSpriteIndex() const;
	void SetActiveSprite(int index);
	void SetRow(int value);
	void SetIsFlipped(bool value);
	void PushAnimatedSprite(const std::string& filePath, int cols, int frames, float animationSpeed);
	
private:
	std::vector<AnimatedSprite*> m_AnimatedSprites{};
	int m_ActiveSpriteIdx{};
	float m_Scale{3.f};
	bool m_IsFlipped{};


};

