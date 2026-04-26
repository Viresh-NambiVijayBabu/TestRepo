#include "pch.h"
#include <iostream>
#include "CharacterBody.h"
#include "SpriteController.h"
#include "CharacterBodyManager.h"
#include "MyUtils.h"

CharacterBody::CharacterBody() :
	CharacterBody(Vector2f{0.f, 0.f})
{
}

CharacterBody::CharacterBody(const Vector2f& spawnPos) :
	m_Position{ spawnPos }
{
	CharacterBodyManager::GetCharacterBodyManager()->PushCharacterBody(this);
}

void CharacterBody::Draw() const 
{
	return;
}

void CharacterBody::Update(float deltaTime)
{
	if (m_pCollisionShape != nullptr) {
		m_pCollisionShape->SetPosition(m_Position);
		if (m_pCollisionShape->GetCollidingBodies().size() > 0) 
		{
			OnCollisionDetected(m_pCollisionShape->GetCollidingBodies());
		}
	}
	
	
}

Vector2f CharacterBody::GetPosition() const
{
	return m_Position;
}

Vector2f CharacterBody::GetDirectionVector() const
{
	return m_DirectionVector;
}

CollisionShape& CharacterBody::GetCollisionShape()
{
	return *m_pCollisionShape;
}

bool CharacterBody::GetIsActive() const
{
	return m_IsActive;
}



void CharacterBody::SetPosition(const Vector2f& pos)
{
	m_Position = pos;
}

void CharacterBody::SetDirectionVector(const Vector2f& directionVector)
{
	m_DirectionVector = MyUtils::Normalized(directionVector);
}

void CharacterBody::SetCollisionShape(CollisionShape& collisionShape)
{
	m_pCollisionShape = &collisionShape;
	m_pCollisionShape->SetParentBody(this);
}

void CharacterBody::SetIsActive(bool value)
{
	m_IsActive = value;
}


float CharacterBody::GetSpeed() const
{
	return m_Speed;
}

void CharacterBody::SetSpeed(float value)
{
	m_Speed = value;
}



void CharacterBody::MoveAndSlide(float deltaTime)
{
	m_Position += m_DirectionVector * m_Speed * deltaTime;
}

void CharacterBody::OnCollisionDetected(const std::vector<CharacterBody*>& colliderlayers)
{
	
}