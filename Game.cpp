#include "Game.h"

Game::Game()
{
	m_MushroomTexture.loadFromFile("Mushroom.png");
	m_Mushroom.setTexture(m_MushroomTexture);
	m_MushroomIncrement = sf::Vector2i(4, 4);
}

GameWindow * Game::GetWindow()
{
	return &m_GameWindow;
}

void Game::HandleInput()
{
}

void Game::Update()
{
	m_GameWindow.Update();
	MoveMushroom();
}

void Game::Render()
{
	m_GameWindow.BeginDraw();
	m_GameWindow.Draw(m_Mushroom);
	m_GameWindow.EndDraw();
}

void Game::MoveMushroom()
{
	sf::Vector2u GameWindowSize = m_GameWindow.GetGameWindowSize();
	sf::Vector2u MushroomTextureSize = m_MushroomTexture.getSize();

	if ((m_Mushroom.getPosition().x > GameWindowSize.x - MushroomTextureSize.x && m_MushroomIncrement.x > 0) ||
		(m_Mushroom.getPosition().x < 0 && m_MushroomIncrement.x < 0))
	{
		m_MushroomIncrement.x = -m_MushroomIncrement.x;
	}

	if ((m_Mushroom.getPosition().y > GameWindowSize.y - MushroomTextureSize.y && m_MushroomIncrement.y > 0) ||
		(m_Mushroom.getPosition().y < 0 && m_MushroomIncrement.y < 0))
	{
		m_MushroomIncrement.y = -m_MushroomIncrement.y;
	}

	m_Mushroom.setPosition(m_Mushroom.getPosition().x + m_MushroomIncrement.x, m_Mushroom.getPosition().y + m_MushroomIncrement.y);
}
