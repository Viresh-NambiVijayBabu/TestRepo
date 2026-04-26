#include "pch.h"
#include "Bullhead.h"

Bullhead::Bullhead(const Vector2f& spawnPos, const Player* player) :
	Enemy(spawnPos, player)
{
	GetSpriteController().PushAnimatedSprite("Bullhead_Running.png", 6, 24, 0.15f);
	SetSpeed(20.f);
}
