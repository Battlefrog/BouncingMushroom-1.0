#include "GameWindow.h"

GameWindow::GameWindow()
{
	Setup("BouncingMushroom-1.0", sf::Vector2u{ 640, 480 });
}

GameWindow::GameWindow(const std::string &GameWindowTitle, const sf::Vector2u &GameWindowSize)
{
	Setup(GameWindowTitle, GameWindowSize);
}

GameWindow::~GameWindow()
{
	Destroy();
}

void GameWindow::Update()
{
	sf::Event event;

	while (m_GameWindow.pollEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::Closed:
				m_IsDone = true;
				break;

			case sf::Event::KeyPressed:
				case sf::Keyboard::F5:
					ToggleFullscreen();
					break;

			default:
				break;
		}
	}
}

void GameWindow::ToggleFullscreen()
{
	m_IsFullscreen = !m_IsFullscreen;
	Destroy();
	Create();
}

void GameWindow::Setup(const std::string & GameWindowTitle, const sf::Vector2u & GameWindowSize)
{
	m_GameWindowTitle = GameWindowTitle;
	m_GameWindowSize = GameWindowSize;
	m_IsFullscreen = false;
	m_IsDone = false;
	
	Create();
}

void GameWindow::Destroy()
{
	m_GameWindow.close();
}

void GameWindow::Create()
{
	auto style = (m_IsFullscreen ? sf::Style::Fullscreen : sf::Style::Default);
	m_GameWindow.create(sf::VideoMode(m_GameWindowSize.x, m_GameWindowSize.y), m_GameWindowTitle, style);
}
