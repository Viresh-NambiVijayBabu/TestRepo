#include "pch.h"
#include "EnemyManager.h"
#include "Enemy.h"
#include "Bullhead.h"

EnemyManager* EnemyManager::GetEnemyManager()
{
	static EnemyManager enemyManager{};
	return &enemyManager;
}


EnemyManager::~EnemyManager()
{
	return;
	for (Enemy* enemy : m_Enemies)
	{
		delete enemy;
	}
}

void EnemyManager::DrawEnemies() const
{
	for (const Enemy* enemy : m_Enemies) {
		enemy->Draw();
	}
}

void EnemyManager::UpdateEnemies(float deltaTime)
{
	for (Enemy* enemy : m_Enemies) {
		enemy->Update(deltaTime);
	}
}

void EnemyManager::AddEnemy(Types type, const Vector2f& spawnPos, Player* player)
{
	switch (type) {
	case (Types::Bullhead):
		Enemy* bullhead{ new Bullhead{spawnPos, player} };
		m_Enemies.push_back(bullhead);
		
	}
}

