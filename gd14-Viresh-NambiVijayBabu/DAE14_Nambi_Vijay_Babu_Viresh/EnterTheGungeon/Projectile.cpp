#include "pch.h"
#include "Projectile.h"
#include "SpriteController.h"

#include "CollisionShape.h"


Projectile::Projectile(const Vector2f& spawnPos, const Vector2f& direction) :
	CharacterBody(spawnPos)
{
	SetDirectionVector(direction);	
	CharacterBody::SetCollisionShape(m_CollisionShape);
}

void Projectile::Draw() const
{
	m_SpriteController.DrawActiveSprite(GetPosition());
}

void Projectile::Update(float deltaTime)
{
	m_SpriteController.UpdateActiveSprite(deltaTime);
	MoveAndSlide(deltaTime);
	CharacterBody::Update(deltaTime);
}

//void Projectile::OnCollisionDetected(const std::vector<CollisionShape::Layers>& colliderlayers)
//{
//	for (CollisionShape::Layers layer : colliderlayers)
//	{
//		if (layer == CollisionShape::Layers::enemy) 
//		{
//			std::cout << "hi";
//		}
//	}
//}


SpriteController& Projectile::GetSpriteController()
{
	return m_SpriteController;
}

Projectile::Types Projectile::GetType() const
{
	return m_Type;
}

void Projectile::SetType(Types type)
{
	m_Type = type;
}
