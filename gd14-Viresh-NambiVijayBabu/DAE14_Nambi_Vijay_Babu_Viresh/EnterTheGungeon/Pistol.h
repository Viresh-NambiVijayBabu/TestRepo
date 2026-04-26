#pragma once
#include "Gun.h"
class ProjectileManager;
class Pistol final : public Gun
{
public:
	explicit Pistol(const Vector2f& handPos);

	void UpdateAngle(const Vector2f& mousePos, const Vector2f& playerPos);
private:

};

