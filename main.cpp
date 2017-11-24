#include <SFML\Graphics.hpp>

void main(int argc, char** argv[])
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "Bouncing Mushroom!");
	window.setFramerateLimit(144); // 144 hz monitor support

	sf::Texture texture;
	texture.loadFromFile("Mushroom.png");

	sf::Sprite mushroom(texture);
	sf::Vector2u size = texture.getSize();

	float mushroomSpeed = 3.0f;

	sf::Vector2f speed(mushroomSpeed, mushroomSpeed);

	mushroom.setOrigin(size.x / 2.0f, size.y / 2.0f);
	mushroom.setPosition(texture.getSize().x * 2.0f, texture.getSize().y * 2.0f);

	// Game loop
	while (window.isOpen())
	{
		// Event handling
		sf::Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
				case sf::Event::Closed:
					window.close();
					break;

				case sf::Event::KeyPressed:
					case sf::Keyboard::Escape:
						window.close();
						break;

				default:
					// We don't care about anything else
					break;
			}
		}

		// Updating
		if ((mushroom.getPosition().x + (size.x / 2) >
			window.getSize().x && speed.x > 0) ||
			(mushroom.getPosition().x - (size.x / 2) < 0 &&
				speed.x < 0))
		{
			speed.x = -speed.x;
		}

		if ((mushroom.getPosition().y + (size.y / 2) >
			window.getSize().y && speed.y > 0) ||
			(mushroom.getPosition().y - (size.y / 2) < 0 &&
				speed.y < 0))
		{
			speed.y = -speed.y;
		}

		mushroom.setPosition(mushroom.getPosition() + speed);

		// Drawing
		window.clear(sf::Color(192, 192, 192, 255));
		window.draw(mushroom);
		window.display();
	}
}