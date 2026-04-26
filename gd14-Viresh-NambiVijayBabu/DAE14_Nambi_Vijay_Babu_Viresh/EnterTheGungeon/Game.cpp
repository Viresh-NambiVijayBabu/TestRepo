#include "pch.h"
#include <iostream>
#include "Game.h"
#include "CharacterBody.h"
#include "Player.h"
#include "Projectile.h"
#include "CollisionShape.h"
#include "CharacterBodyManager.h"

Game::Game( const Window& window ) 
	:BaseGame{ window }
{
	Initialize();
}

Game::~Game( )
{
	Cleanup( );
	
}

void Game::Initialize( )
{ 
	//CollisionManager::GetCollisionManager();
	m_Player = new Player{ Vector2f{100.f, 100.f}};
	//EnemyManager::GetEnemyManager()->AddEnemy(EnemyManager::Types::Bullhead, Vector2f{ 400.f, 400.f }, m_Player);
	
}

void Game::Cleanup( )
{
	delete m_Player;
}

void Game::Update( float elapsedSec )
{
	Vector2f directionVector{};
	const Uint8* pStates = SDL_GetKeyboardState(nullptr);
	directionVector.x = pStates[SDL_SCANCODE_D] - pStates[SDL_SCANCODE_A];
	directionVector.y = pStates[SDL_SCANCODE_W] - pStates[SDL_SCANCODE_S];
	//m_Player->Update(elapsedSec, directionVector.Normalized());
	//m_Player->UpdateSpriteDirection(m_MousePosition);
	//CollisionManager::GetCollisionManager()->Update(elapsedSec);
	//CharacterBodyManager::GetCharacterBodyManager()->UpdateCharacterBodies(elapsedSec);
	//debug
	//std::cout << m_Player->GetPosition() - m_MousePosition << '\n';
}

void Game::Draw( ) const
{
	ClearBackground( );
	//CharacterBodyManager::GetCharacterBodyManager()->DrawCharacterBodies();

	
	
}

void Game::ProcessKeyDownEvent( const SDL_KeyboardEvent & e )
{
	
	//std::cout << "KEYDOWN event: " << e.keysym.sym << std::endl;
}

void Game::ProcessKeyUpEvent( const SDL_KeyboardEvent& e )
{
	//std::cout << "KEYUP event: " << e.keysym.sym << std::endl;
	//switch ( e.keysym.sym )
	//{
	//case SDLK_LEFT:
	//	//std::cout << "Left arrow key released\n";
	//	break;
	//case SDLK_RIGHT:
	//	//std::cout << "`Right arrow key released\n";
	//	break;
	//case SDLK_1:
	//case SDLK_KP_1:
	//	//std::cout << "Key 1 released\n";
	//	break;
	//}
}

void Game::ProcessMouseMotionEvent( const SDL_MouseMotionEvent& e )
{
	Vector2f mousePosition{ static_cast<float>(e.x),
	static_cast<float>(e.y) };
	m_MousePosition = mousePosition;
	//std::cout << "MOUSEMOTION event: " << e.x << ", " << e.y << std::endl;
}

void Game::ProcessMouseDownEvent( const SDL_MouseButtonEvent& e )
{

	//std::cout << "MOUSEBUTTONDOWN event: ";
	switch ( e.button )
	{
	case SDL_BUTTON_LEFT:
		//m_Player->Shoot();
		break;
	case SDL_BUTTON_RIGHT:
		//m_Player->StartDodgeRoll();
		break;
	//case SDL_BUTTON_MIDDLE:
	//	std::cout << " middle button " << std::endl;
	//	break;
	}
	
}

void Game::ProcessMouseUpEvent( const SDL_MouseButtonEvent& e )
{
	//std::cout << "MOUSEBUTTONUP event: ";
	//switch ( e.button )
	//{
	//case SDL_BUTTON_LEFT:
	//	std::cout << " left button " << std::endl;
	//	break;
	//case SDL_BUTTON_RIGHT:
	//	std::cout << " right button " << std::endl;
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	std::cout << " middle button " << std::endl;
	//	break;
	//}
}

void Game::ClearBackground( ) const
{
	glClearColor( 0.0f, 0.0f, 0.3f, 1.0f );
	glClear( GL_COLOR_BUFFER_BIT );
}
