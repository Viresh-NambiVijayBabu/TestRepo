#include "pch.h"
#include "CollisionManager.h"
#include "CollisionShape.h"
#include "CharacterBody.h"
#include "utils.h"
#include <iostream>

CollisionManager* CollisionManager::GetCollisionManager()
{
	static CollisionManager collisionManager{};
	return &collisionManager;
}



void CollisionManager::DrawCollisionShapes() const
{
	for (const CollisionShape* shape : m_CollisionShapes) 
	{
		shape->Draw();
	}
}

void CollisionManager::Update(float deltaTime)
{ 
	CheckCollisions();
}

void CollisionManager::CheckCollisions()
{
	for (CollisionShape* currentShape : m_CollisionShapes) 
	{
		
		if (currentShape->GetParentBody() == nullptr) { continue; }
		if (!currentShape->GetParentBody()->GetIsActive()) { continue; }
		bool hasCollided{};
		for (CollisionShape* checkingShape : m_CollisionShapes)
		{
			if (checkingShape == currentShape) { continue; }
			if (!checkingShape->GetParentBody()->GetIsActive()) { continue; }
			if (utils::IsOverlapping(checkingShape->GetRect(), currentShape->GetRect() ))
			{
				currentShape->UpdateCollidingBodies(checkingShape->GetParentBody());
				hasCollided = true;
			}
			if (!hasCollided)
			{
				currentShape->UpdateCollidingBodies(nullptr); //reset collision vector
			}
		}
		
	}
}

void CollisionManager::PushCollisionShape(CollisionShape* shape)
{
	m_CollisionShapes.push_back(shape);
}
