#pragma once

#include "SFML\Graphics.hpp"
#include "GameWindow.h"

class Game
{
public:

	Game();

	GameWindow* GetWindow();

	void HandleInput();
	void Update();
	void Render();

private:

	void MoveMushroom();

	GameWindow m_GameWindow;

	sf::Texture m_MushroomTexture;
	sf::Sprite m_Mushroom;

	sf::Vector2i m_MushroomIncrement;
};