#include "pch.h"
#include "Pistol.h"
#include "MyUtils.h"
#include "SpriteController.h"
#include <iostream>

Pistol::Pistol(const Vector2f& handPos) :
	Gun(Vector2f{ 6.f, 3.f }, Vector2f{30.f, 10.f}, handPos)
{
	GetSpriteController().PushAnimatedSprite("Sidearm_Idle.png", 1, 1, 1.f);
	SetProjectileType(Projectile::Types::PistolBullet);
}

void Pistol::UpdateAngle(const Vector2f& mousePos, const Vector2f& playerPos)
{
	Vector2f vectorToMouse{ mousePos - GetPosition() };
	float distanceToMouse{ MyUtils::Length(vectorToMouse) };
	if (distanceToMouse < 20.f) { return; }
	SetLookDirection(vectorToMouse);
	if (distanceToMouse > 50.f) 
	{
		SetBulletDirection(mousePos - (GetPosition() + GetRotatedBarrelOffset()));
	}
	else 
	{
		SetBulletDirection(vectorToMouse);
	}
}
