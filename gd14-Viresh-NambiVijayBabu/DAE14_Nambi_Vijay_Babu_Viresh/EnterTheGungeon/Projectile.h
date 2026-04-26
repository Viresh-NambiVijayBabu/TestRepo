#pragma once
#include "CharacterBody.h"
#include "SpriteController.h"
class ProjectileManager;

class Projectile : public CharacterBody
{
public:
	enum class Types {
		PistolBullet,
		EnemyBullet
	};
	explicit Projectile(const Vector2f& spawnPos, const Vector2f& direction);
	virtual ~Projectile() override = default;

	virtual void Draw() const override;
	virtual void Update(float deltaTime) override;
	//virtual void OnCollisionDetected(const std::vector<CollisionShape::Layers>& colliderlayers) override;

	SpriteController& GetSpriteController();
	Types GetType() const;
	
	
protected:
	void SetType(Types type);
private:
	SpriteController m_SpriteController{1.f};
	Types m_Type{};
	CollisionShape m_CollisionShape{ 20.f, 20.f };
	
};

