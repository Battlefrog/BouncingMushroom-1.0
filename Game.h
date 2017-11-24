#pragma once

#include "SFML\Graphics.hpp"
#include "GameWindow.h"

class Game
{
public:

	Game();

	sf::Time GetElasped()
	{
		return m_ElaspedGameTime;
	}

	GameWindow* GetWindow();

	void RestartClock()
	{
		m_ElaspedGameTime = m_GameClock.restart();
	}

	void HandleInput();
	void Update();
	void Render();
	

private:

	void MoveMushroom();

	GameWindow m_GameWindow;

	sf::Texture m_MushroomTexture;
	sf::Sprite m_Mushroom;

	sf::Vector2i m_MushroomIncrement;

	sf::Clock m_GameClock;
	sf::Time m_ElaspedGameTime;
};