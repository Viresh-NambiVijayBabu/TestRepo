#include "pch.h"
#include "Enemy.h"
#include "Player.h"


Enemy::Enemy(const Vector2f& spawnPos, const Player* player) :
	CharacterBody(spawnPos),
	m_pPlayer{player}
{
	CharacterBody::SetCollisionShape(m_CollisionShape);
}

void Enemy::Draw() const 
{
	m_SpriteController.DrawActiveSprite(GetPosition());
}

void Enemy::Update(float deltaTime)
{
	CharacterBody::Update(deltaTime);
	m_SpriteController.UpdateActiveSprite(deltaTime);
	SetDirectionVector(m_pPlayer->GetPosition() - GetPosition());
	UpdateSpriteDirection();
	MoveAndSlide(deltaTime);
}

void Enemy::UpdateSpriteDirection()
{
	Vector2f direction{ GetDirectionVector() };
	if (direction.y < 0.f) 
	{
		if (direction.x < 0.f) {
			m_SpriteController.SetRow(0);
		}
		else if (direction.x > 0.f) {
			m_SpriteController.SetRow(1);
		}
	}
	else if (direction.y > 0.f) 
	{
		if (direction.x < 0.f) {
			m_SpriteController.SetRow(2);
		}
		else if (direction.x > 0.f) {
			m_SpriteController.SetRow(3);
		}
	}
}

void Enemy::OnCollisionDetected(const std::vector<CharacterBody*>& collidingBodies)
{
	for (CharacterBody* body : collidingBodies)
	{
		if (body->GetCollisionShape().GetCollisionLayer() == CollisionShape::Layers::playerProjectile)
		{
			health -= 1;
			body->SetIsActive(false);
			if (health <= 0)
			{
				SetIsActive(false);
			}
		}
	}
}

SpriteController& Enemy::GetSpriteController() 
{
	return m_SpriteController;
}