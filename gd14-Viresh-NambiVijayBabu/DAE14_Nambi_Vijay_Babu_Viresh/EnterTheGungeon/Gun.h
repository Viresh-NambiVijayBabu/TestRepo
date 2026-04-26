#pragma once
#include "CharacterBody.h"
#include "SpriteController.h"
#include "Projectile.h"

class Gun : public CharacterBody
{
public:
	explicit Gun(const Vector2f& pivotPoint, const Vector2f& barrelPoint,
		const Vector2f& handPos);
	virtual ~Gun() override = default;
	virtual void Draw() const override;
	void Update(float deltaTime, const Vector2f& handPos);
	void Shoot();

	SpriteController& GetSpriteController();
	void Flip(bool value);
	void SetLookDirection(const Vector2f& direction);
	void SetBulletDirection(const Vector2f& direction);
	Projectile::Types GetProjectileType() const;
	Vector2f GetRotatedBarrelOffset() const;
	float GetUpdatedAngle() const;

protected:
	void SetProjectileType(Projectile::Types type);

private:
	SpriteController m_SpriteController{};
	Projectile::Types m_ProjectileType{};
	Vector2f m_PivotOffset{};
	Vector2f m_BarrelOffset{};
	Vector2f m_Direction{};
	Vector2f m_BulletDirection{};
	float m_Angle{};
	
};

