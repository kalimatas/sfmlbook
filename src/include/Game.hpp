#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

class Game{
public:
	Game();
	void run();

private:
	void processEvents();
	void update();
	void render();
	void handlePlayerInput(sf::Keyboard::Key, bool);

private:
	sf::RenderWindow mWindow;
	sf::CircleShape mPlayer;

	bool mIsMovingLeft;
	bool mIsMovingDown;
	bool mIsMovingRight;
	bool mIsMovingUp;
};

#endif /* GAME_H */
