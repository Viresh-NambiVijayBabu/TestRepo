#pragma once
#include "utils.h"
#include <vector>
class CharacterBody;

class CollisionShape
{
public:
	enum class Layers
	{
		none = -1,
		player,
		enemy,
		playerProjectile,
		enemyProjectile,
		surface
	};
	CollisionShape(float width, float height, const Vector2f& offset = Vector2f{ 0.f, 0.f });
	CollisionShape(Layers collisionLayer,
		float width, float height, const Vector2f& offset = Vector2f{0.f, 0.f});

	void Draw() const;
	void Update(float deltaTime);
	Rectf GetRect() const;
	std::vector<CharacterBody*> GetCollidingBodies() const;
	Layers GetCollisionLayer() const;
	CharacterBody* GetParentBody();
	void SetPosition(const Vector2f& pos);
	void UpdateCollidingBodies(CharacterBody* body);
	void SetCollisionLayer(Layers layer);
	void SetParentBody(CharacterBody* body);
private:
	Vector2f m_Offset{}; // offset from center
	Rectf m_Rect{};
	std::vector<CharacterBody*> m_CollidingBodies{};
	Layers m_CollisionLayer{};
	CharacterBody* m_ParentBody{};
};

