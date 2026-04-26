#pragma once
#include "Enemy.h"
class Player;

class Bullhead : public Enemy
{
public:
	Bullhead(const Vector2f& spawnPos, const Player* player);
private:
};

