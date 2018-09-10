// included libraries
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


// entry point for the program
int main()
{
	// ------------------ game setup --------------------------------
	// make a variable called gameWindow of type RenderWindow
	sf::RenderWindow gameWindow;
	gameWindow.create(sf::VideoMode::getDesktopMode(), "Button Masher", 
		sf::Style::Titlebar | sf::Style::Close);

	// create button sprite
	sf::Texture buttonTexture;
	buttonTexture.loadFromFile("graphics/button.png");
	sf::Sprite buttonSprite;
	buttonSprite.setTexture(buttonTexture);
	// create sprite at centre the sprite on the screen
	buttonSprite.setPosition(
		gameWindow.getSize().x / 2 - buttonTexture.getSize().x / 2, 
		gameWindow.getSize().y / 2 - buttonTexture.getSize().y / 2
	);

	// create music
	sf::Music gameMusic;
	gameMusic.openFromFile("audio/music.ogg");
	gameMusic.play();

	// ----------------------------------------------------------------




	// game loop
	while (gameWindow.isOpen())
	{
		// Check for input
		sf::Event gameEvent;
		while (gameWindow.pollEvent(gameEvent))
		{
			// Process events

			//check if the event is the closed event
			if (gameEvent.type == sf::Event::Closed)
			{
				gameWindow.close();  // close the game window
			}
		}


		// TODO: Update game state

		// TODO: Draw Graphics

		gameWindow.clear(sf::Color::Black);

		// draw everything
		gameWindow.draw(buttonSprite);

		// display the windows contents on the screen
		gameWindow.display();

	}
	// exit point for the program
	return 0;
}