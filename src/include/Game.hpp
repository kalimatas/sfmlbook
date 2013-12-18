#ifndef GAME_HPP_
#define GAME_HPP_

#include <SFML/Graphics.hpp>

class Game{
public:
	Game();
	void run();

private:
	void processEvents();
	void update(sf::Time);
	void render();
	void handlePlayerInput(sf::Keyboard::Key, bool);
	void updateStatistics(sf::Time);

private:
	static const float PlayerSpeed;
	static const sf::Time TimePerFrame;

	sf::RenderWindow mWindow;
	sf::Sprite mPlayer;
	sf::Font mFont;
	sf::Text mStatisticsText;
	sf::Time mStatisticsUpdateTime;

	std::size_t mStatisticsNumFrames;

	bool mIsMovingLeft;
	bool mIsMovingDown;
	bool mIsMovingRight;
	bool mIsMovingUp;
};

#endif /* GAME_HPP_ */
