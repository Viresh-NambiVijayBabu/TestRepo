#include "pch.h"
#include "Gun.h"
#include <iostream>
#include "PistolBullet.h"
#include "MyUtils.h"
#include "Matrix2x3.h"
#include "ProjectileManager.h"

Gun::Gun(const Vector2f& pivotPoint, const Vector2f& barrelPoint, const Vector2f& handPos) :
	CharacterBody(handPos),
	m_PivotOffset{pivotPoint},
	m_BarrelOffset{barrelPoint}	
{
	
}

void Gun::Draw() const
{
	glPushMatrix();
	{
		
		glTranslatef(GetPosition().x, GetPosition().y, 1.f);
		glRotatef(GetUpdatedAngle(), 0.f, 0.f, 1.f);
		m_SpriteController.DrawActiveSprite(m_PivotOffset);
	}
	glPopMatrix();
	
}

void Gun::Update(float deltaTime, const Vector2f& handPos) 
{
	SetPosition(handPos);
	m_SpriteController.UpdateActiveSprite(deltaTime);
}

void Gun::Shoot()
{
	if (!GetIsActive()) { return; }
	Vector2f bulletSpawnPos{ GetPosition() + GetRotatedBarrelOffset() };
	ProjectileManager::GetProjectileManager()->AddProjectile(m_ProjectileType, bulletSpawnPos, m_BulletDirection);
}


SpriteController& Gun::GetSpriteController()
{
	return m_SpriteController;
}

void Gun::Flip(bool value)
{
	if (value)
	{
		m_PivotOffset.x = -abs(m_PivotOffset.x);
	}
	else {
		m_PivotOffset.x = abs(m_PivotOffset.x);
	}
	m_SpriteController.SetIsFlipped(value);
}

void Gun::SetLookDirection(const Vector2f& direction)
{
	m_Direction = MyUtils::Normalized(direction);
	m_Angle = MyUtils::Angle(m_Direction);
}

void Gun::SetBulletDirection(const Vector2f& direction)
{
	m_BulletDirection = MyUtils::Normalized(direction);
}

Projectile::Types Gun::GetProjectileType() const
{
	return m_ProjectileType;
}

Vector2f Gun::GetRotatedBarrelOffset() const
{
	Matrix2x3 rotationMatrix{};
	Vector2f updatedBarrelOffset{ m_BarrelOffset };
	Vector2f rotatedBarrelOffset{ };
	if (m_SpriteController.GetIsFlipped())
	{
		updatedBarrelOffset.y = -m_BarrelOffset.y;
	}
	rotationMatrix.SetAsRotate(m_Angle);
	rotationMatrix.Transform(&updatedBarrelOffset, &rotatedBarrelOffset, 1);
	return rotatedBarrelOffset;
}

float Gun::GetUpdatedAngle() const
{
	float updatedAngle{ MyUtils::Angle(m_Direction) };
	if (m_SpriteController.GetIsFlipped())
	{
		updatedAngle -= 180.f;
	}
	return updatedAngle;
}

void Gun::SetProjectileType(Projectile::Types type)
{
	m_ProjectileType = type;
}
