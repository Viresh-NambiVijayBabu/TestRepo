#include "pch.h"
#include "CollisionShape.h"
#include "CollisionManager.h"
#include "CharacterBody.h"


CollisionShape::CollisionShape(float width, float height, const Vector2f& offset) :
	m_Offset{ offset },
	m_Rect{ width / 2 + offset.x, height / 2 + offset.y, width, height }
{
	CollisionManager::GetCollisionManager()->PushCollisionShape(this);
}

CollisionShape::CollisionShape(Layers collisionLayer,
	float width, float height, const Vector2f& offset) :
	CollisionShape(width, height, offset)
	
{
	m_CollisionLayer = collisionLayer;
}


void CollisionShape::Draw() const
{
	return;
	utils::SetColor(Color4f{ 1.f, 0.f, 0.f, 1.f });
	utils::DrawRect(m_Rect);
}

void CollisionShape::Update(float deltaTime) 
{
	
}

Rectf CollisionShape::GetRect() const
{
	return m_Rect;
}


std::vector<CharacterBody*> CollisionShape::GetCollidingBodies() const
{

	return m_CollidingBodies;
}

CollisionShape::Layers CollisionShape::GetCollisionLayer() const
{
	return m_CollisionLayer;
}

CharacterBody* CollisionShape::GetParentBody()
{
	return m_ParentBody;
}



void CollisionShape::SetPosition(const Vector2f& pos)
{
	m_Rect.left = pos.x - m_Rect.width/2 + m_Offset.x;
	m_Rect.bottom = pos.y - m_Rect.width/2 + m_Offset.y;
}


void CollisionShape::UpdateCollidingBodies(CharacterBody* body)
{
	if (body == nullptr)
	{
		m_CollidingBodies.clear();
		return;
	}
	
	for (CharacterBody* storedBody : m_CollidingBodies) 
	{
		if (body == storedBody) {
			return;
		}
	}
	
	m_CollidingBodies.push_back(body);
	
}

void CollisionShape::SetCollisionLayer(Layers layer)
{
	m_CollisionLayer = layer;
	
	
}

void CollisionShape::SetParentBody(CharacterBody* body)
{
	m_ParentBody = body;
}

