#pragma once
#include "CharacterBody.h"
#include "SpriteController.h"
#include "Pistol.h"
#include "AnimatedSprite.h"


class Player final : public CharacterBody
{
public:
	enum class States
	{
		idle,
		running,
		rolling
	};
	explicit Player(const Vector2f& spawnPos);
	virtual ~Player() override;
	virtual void Draw() const override;
	void Update(float deltaTime, const Vector2f& direction);
	void UpdateSpriteDirection(const Vector2f& mousePos);
	void StartDodgeRoll();
	void Shoot();


private:
	Vector2f m_HandOffset{ 22.f, -25.f };
	Vector2f m_HandPosition{};
	SpriteController m_PlayerSpriteController{};
	AnimatedSprite m_HandSprite;
	Pistol* m_Gun{};
	const float m_WalkSpeed{ 100.f };
	const float m_DodgeSpeed{ 200.f };
	const float m_DodgeTime{ 0.9f };
	float m_DodgeTimer{ m_DodgeTime };
	States m_CurrentState{};
	CollisionShape m_CollisionShape{CollisionShape::Layers::player, 40.f, 40.f };


	void DodgeRoll(float deltaTime);
	bool CheckFlip(float angle) const;
	void UpdateHandPosition(bool isFlipped);
	virtual void OnCollisionDetected(const std::vector<CharacterBody*>& colliderlayers) override;
};

