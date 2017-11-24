#pragma once

#include <string>
#include <SFML\Graphics.hpp>

class GameWindow 
{
public:

	GameWindow();
	GameWindow(const std::string &GameWindowTitle, const sf::Vector2u &GameWindowSize);
	~GameWindow();

	sf::Vector2u GetGameWindowSize()
	{
		return m_GameWindowSize;
	}

	void Draw(sf::Drawable &Drawable)
	{
		m_GameWindow.draw(Drawable);
	}

	void BeginDraw()
	{
		m_GameWindow.clear(sf::Color(192, 192, 192, 255));
	}

	void EndDraw() 
	{
		m_GameWindow.display();
	}

	void Update();
	void ToggleFullscreen();

	bool IsDone()
	{
		return m_IsDone;
	}
	bool IsFullscreen()
	{
		return m_IsFullscreen;
	}

private:

	void Setup(const std::string &GameWindowTitle, const sf::Vector2u &GameWindowSize);
	void Destroy();
	void Create();
	
	std::string m_GameWindowTitle;

	sf::RenderWindow m_GameWindow;
	sf::Vector2u m_GameWindowSize;

	bool m_IsDone;
	bool m_IsFullscreen;
};