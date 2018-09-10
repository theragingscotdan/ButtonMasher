// included libraries
#include <SFML/Graphics.hpp>


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

	}
	// exit point for the program
	return 0;
}