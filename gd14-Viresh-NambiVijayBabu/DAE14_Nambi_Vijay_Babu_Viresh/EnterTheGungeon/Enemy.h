#pragma once
#include "CharacterBody.h"
#include "SpriteController.h"
class Player;
class CollisionManager;
class Enemy : public CharacterBody
{
public:
	explicit Enemy(const Vector2f& spawnPos, const Player* player);
	virtual ~Enemy() override = default;
	
	virtual void Draw() const override;
	virtual void Update(float deltaTime) override;
	void UpdateSpriteDirection();
	virtual void OnCollisionDetected(const std::vector<CharacterBody*>& colliderlayers) override;

	SpriteController& GetSpriteController();
	
private:
	SpriteController m_SpriteController{};
	const Player* m_pPlayer{};
	CollisionShape m_CollisionShape{CollisionShape::Layers::enemy, 30.f, 50.f, Vector2f{0.f, -20.f}};
	int health{ 5 };
};

