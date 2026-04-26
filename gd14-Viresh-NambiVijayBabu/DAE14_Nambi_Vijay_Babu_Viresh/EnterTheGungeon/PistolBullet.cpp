#include "pch.h"
#include "PistolBullet.h"
#include "SpriteController.h"

PistolBullet::PistolBullet(const Vector2f& spawnPos, const Vector2f& direction) :
	Projectile(spawnPos, direction)
{
	GetSpriteController().PushAnimatedSprite("Pistol_Projectile.png", 1, 1, 1.f);
	SetType(Projectile::Types::PistolBullet);
	GetCollisionShape().SetCollisionLayer(CollisionShape::Layers::playerProjectile);
	SetSpeed(300.f);
}

