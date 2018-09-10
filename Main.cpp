// included libraries
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>


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
	//gameMusic.play();

	// create font
	sf::Font gameFont;
	gameFont.loadFromFile("fonts/mainFont.ttf");
	
	// create Title
	sf::Text titleText, madeByTest, scoreText;
	titleText.setFont(gameFont);
	titleText.setString("BuTtOn MaShEr");
	titleText.setCharacterSize(100);
	titleText.setFillColor(sf::Color::Yellow);
	titleText.setStyle(sf::Text::Bold | sf::Text::Italic);

	titleText.setPosition(
		gameWindow.getSize().x / 2 - titleText.getLocalBounds().width /2,
		30
	);

	madeByTest.setFont(gameFont);
	madeByTest.setString("made by Daniel Wallace");
	madeByTest.setPosition(
		gameWindow.getSize().x / 2 - madeByTest.getLocalBounds().width / 2,
		130
	);
	
	// score
	int score = 0;
	scoreText.setFont(gameFont);
	scoreText.setString("Score: " + std::to_string(score));
	scoreText.setCharacterSize(20);
	scoreText.setFillColor(sf::Color::Yellow);
	scoreText.setPosition(
		gameWindow.getSize().x / 2 - scoreText.getLocalBounds().width / 2,
		1000
	);
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


		// Update game state
		score = score + 1;
		scoreText.setString("Score: " + std::to_string(score));

		// TODO: Draw Graphics

		gameWindow.clear(sf::Color::Black);

		// draw everything
		gameWindow.draw(buttonSprite);
		gameWindow.draw(titleText);
		gameWindow.draw(madeByTest);
		gameWindow.draw(scoreText);

		// display the windows contents on the screen
		gameWindow.display();

	}
	// exit point for the program
	return 0;
}