#pragma once
#include "Vector2f.h"
#include "CollisionShape.h"
#include <iostream>

class CharacterBody
{
public:
	explicit CharacterBody();
	explicit CharacterBody(const Vector2f& spawnPos);
	virtual ~CharacterBody() = default;
	
	virtual void Draw() const;
	virtual void Update(float deltaTime);
	
	Vector2f GetPosition() const;
	Vector2f GetDirectionVector() const;
	CollisionShape& GetCollisionShape();
	bool GetIsActive() const;
	void SetPosition(const Vector2f& pos);
	void SetDirectionVector(const Vector2f& directionVector);
	void SetCollisionShape(CollisionShape& collisionShape);
	void SetIsActive(bool value);
	
	
protected:
	float GetSpeed() const;
	void SetSpeed(float value);
	void MoveAndSlide(float deltaTime);

private:
	Vector2f m_Position{};
	Vector2f m_DirectionVector{}; //normalized vector corresponding to movement dierction
	float m_Speed{};
	CollisionShape* m_pCollisionShape{};
	bool m_IsActive{ true };

	virtual void OnCollisionDetected(const std::vector<CharacterBody*>& colliderlayers);
};

