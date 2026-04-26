#include "pch.h"
#include "Player.h"
#include <iostream>
#include "MyUtils.h"

Player::Player(const Vector2f& spawnPos) :
	CharacterBody(spawnPos),
	m_HandSprite{ "Marine_Hand.png", 1, 1, 1.f },
	m_Gun{ new Pistol{ GetPosition() + m_HandOffset } }
{
	
	m_PlayerSpriteController.PushAnimatedSprite("Marine_Idle.png", 4, 16, 0.1f);
	m_PlayerSpriteController.PushAnimatedSprite("Marine_Run.png", 6, 24, 0.15f);
	m_PlayerSpriteController.PushAnimatedSprite("Marine_DodgeRoll.png", 9, 36, 0.1f);
	SetSpeed(m_WalkSpeed);
	CollisionShape::Layers collisionMasks[]{CollisionShape::Layers::enemy, CollisionShape::Layers::enemyProjectile};
	m_CollisionShape.SetCollisionLayer(CollisionShape::Layers::player);
	CharacterBody::SetCollisionShape(m_CollisionShape);
}

Player::~Player()
{
	
}

void Player::Draw() const
{
	
	if (m_CurrentState != States::rolling) 
	{
		m_HandSprite.Draw(m_HandPosition);
	}
	m_PlayerSpriteController.DrawActiveSprite(GetPosition());
}

void Player::Update(float deltaTime, const Vector2f& direction)
{
	MoveAndSlide(deltaTime); 
	CharacterBody::Update(deltaTime);
	//sprite related
	m_Gun->Update(deltaTime, m_HandPosition);
	m_PlayerSpriteController.UpdateActiveSprite(deltaTime);
	int currentStateIdx{ static_cast<int>(m_CurrentState) };
	if (currentStateIdx != m_PlayerSpriteController.GetActiveSpriteIndex())
	{
		m_PlayerSpriteController.SetActiveSprite(currentStateIdx);
	}
	//dodge roll update
	if (m_CurrentState == States::rolling) {
		DodgeRoll(deltaTime);
		return;
	}
	//movement update
	if (direction.x == 0.f and direction.y == 0.f) {
		m_CurrentState = States::idle;
	}
	else {
		m_CurrentState = States::running;
	}
	SetDirectionVector(direction);
	
}

void Player::UpdateSpriteDirection(const Vector2f& mousePos)
{
	
	Vector2f playerPosition{ GetPosition() };
	Vector2f directionVector{ mousePos - playerPosition };
	directionVector = MyUtils::Normalized(directionVector);
	float angle{ MyUtils::Angle(directionVector) };
	bool isFlipped{};
	//update gun and hand(always)
	isFlipped = CheckFlip(angle);
	UpdateHandPosition(isFlipped);
	m_Gun->SetPosition(m_HandPosition);
	m_Gun->UpdateAngle(mousePos, GetPosition());
	m_Gun->Flip(isFlipped);
	if (m_CurrentState == States::rolling) {
		return;
	}
	//update player sprite
	int divisions{ 8 };
	float divisionAngle{ 360.f / divisions };
	int section{ abs(static_cast<int>(angle / divisionAngle)) };
	bool isFacingDown{ directionVector.y < 0.f };
	int newRowIdx{};


	if (!isFacingDown) 
	{
		switch (section) 
		{
		case 0:
		case 3:
			newRowIdx = 3;
			break;
		case 1:
		case 2:
			newRowIdx = 2;
			break;
		}
	}
	else {
		switch (section) {
		case 0:
		case 3:
			newRowIdx = 1;
			break;
		case 1:
		case 2:
			newRowIdx = 0;
			break;
		}
	}
	
	if (m_PlayerSpriteController.GetIsFlipped() != isFlipped)
	{
		m_PlayerSpriteController.SetIsFlipped(isFlipped);
	}
	
	m_PlayerSpriteController.SetRow(newRowIdx);
}

void Player::StartDodgeRoll()
{
	m_Gun->SetIsActive(false);
	Vector2f direction{ GetDirectionVector() };
	int newRowIdx{};
	bool isFlipped{};
	if (direction.x == 0.f and direction.y == 0.f) {
		return;
	}
	m_CurrentState = States::rolling;
	if (direction.y > 0.f) //moving up
	{
		if (direction.x > 0.f) {
			newRowIdx = 3;
			isFlipped = false;
		}
		else if (direction.x < 0.f) {
			newRowIdx = 3;
			isFlipped = true;
		}
		else {
			newRowIdx = 2;
		}
	}
	else {
		if (direction.x > 0.f) {
			newRowIdx = 1;
			isFlipped = false;
		}
		else if (direction.x < 0.f) {
			newRowIdx = 1;
			isFlipped = true;
		}
		else {
			newRowIdx = 0;
		}
	}
	m_PlayerSpriteController.SetRow(newRowIdx);
	m_PlayerSpriteController.SetIsFlipped(isFlipped);

}

void Player::Shoot()
{
	m_Gun->Shoot();
}


void Player::DodgeRoll(float deltaTime)
{
	if (m_DodgeTimer < 0.f) {
		m_DodgeTimer = m_DodgeTime;
		m_CurrentState = States::running;
		m_Gun->SetIsActive(true);
		return;
	}
	m_DodgeTimer -= deltaTime;

}

bool Player::CheckFlip(float angle) const
{
	if (abs(angle) > 90.f) {
		return true;
	}
	return false;
}
void Player::UpdateHandPosition(bool isFlipped)
{
	if (!isFlipped) { m_HandPosition = GetPosition() + m_HandOffset; }
	else 
	{
		m_HandPosition.x = GetPosition().x - m_HandOffset.x;
		m_HandPosition.y = GetPosition().y + m_HandOffset.y;
	}
}

void Player::OnCollisionDetected(const std::vector<CharacterBody*>& colliderlayers)
{
	return;
}
