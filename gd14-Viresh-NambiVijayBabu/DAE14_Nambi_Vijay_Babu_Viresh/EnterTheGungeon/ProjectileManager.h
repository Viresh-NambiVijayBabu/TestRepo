#pragma once
#include <vector>
#include "Projectile.h"
class ProjectileManager final
{
public:
	static ProjectileManager* GetProjectileManager();

	
	~ProjectileManager();
	void AddProjectile(Projectile* projectile);
	void AddProjectile(Projectile::Types type, const Vector2f& spawnPos, const Vector2f& direction);
	void DrawProjectiles() const;
	void UpdateProjectiles(float deltaTime);
private:
	std::vector<Projectile*> m_Projectiles{};
	
};

