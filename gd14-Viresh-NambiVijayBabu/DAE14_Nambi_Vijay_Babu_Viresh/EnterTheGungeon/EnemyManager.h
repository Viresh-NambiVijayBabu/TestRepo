#pragma once
#include <vector>
class Enemy;
class Player;

class EnemyManager final
{
public:
	static EnemyManager* GetEnemyManager();
	enum class Types 
	{
		Bullhead,
		ShotgunHead
	};

	~EnemyManager();
	void DrawEnemies() const;
	void UpdateEnemies(float deltaTime);
	void AddEnemy(Types type, const Vector2f& spawnPos, Player* player);
private:
	std::vector<Enemy*> m_Enemies{};
};

