#include "pch.h"
#include "ProjectileManager.h"
#include "PistolBullet.h"
#include "CollisionManager.h"

ProjectileManager* ProjectileManager::GetProjectileManager()
{
	static ProjectileManager projectileManager{};
	return &projectileManager;
}

ProjectileManager::~ProjectileManager()
{
	return;
	for (Projectile* projectile : m_Projectiles)
	{
		delete projectile;
	}
}



void ProjectileManager::AddProjectile(Projectile* projectile)
{
	m_Projectiles.push_back(projectile);
}

void ProjectileManager::AddProjectile(Projectile::Types type, const Vector2f& spawnPos, const Vector2f& direction)
{
	switch (type)
	{
	case (Projectile::Types::PistolBullet):
		{
			Projectile* projectile{ new PistolBullet{spawnPos, direction} };
			AddProjectile(projectile);
			break;
		}
	}
}

void ProjectileManager::DrawProjectiles() const
{
	for (const Projectile* projectile : m_Projectiles)
	{
		if (!projectile->GetIsActive()) { continue; }
		projectile->Draw();
	}
}

void ProjectileManager::UpdateProjectiles(float deltaTime)
{
	for (Projectile* projectile : m_Projectiles)
	{
		if (!projectile->GetIsActive()) { continue; }
		projectile->Update(deltaTime);
	}
}

