#pragma once
#include <vector>
class CollisionShape;
class CharacterBody;
class CollisionManager final
{
public:
	static CollisionManager* GetCollisionManager();
	
	
	void DrawCollisionShapes() const;
	void Update(float deltaTime);

	void CheckCollisions();
	void PushCollisionShape(CollisionShape* shape);

private:
	std::vector<CollisionShape*> m_CollisionShapes{};
};

