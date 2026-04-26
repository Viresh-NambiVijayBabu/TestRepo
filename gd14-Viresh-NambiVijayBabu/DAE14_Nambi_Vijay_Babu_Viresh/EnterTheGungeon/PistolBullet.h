#pragma once
#include "Projectile.h"
class AnimatedSprite;
class PistolBullet final : public Projectile
{
public:
	explicit PistolBullet(const Vector2f& spawnPos, const Vector2f& direction);
private:
};

