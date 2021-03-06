#include "include/Game.hpp"
#include "include/StringHelpers.hpp"
#include "include/ResourceHolder.hpp"
#include "include/ResourceIdentifies.hpp"
#include <iostream>

// 60 frames per second
const sf::Time Game::TimePerFrame = sf::seconds(1.f / 60.0f);

Game::Game()
	: mWindow(sf::VideoMode(640, 480), "SFML Book application", sf::Style::Close),
	 mFont(),
	 mStatisticsText(),
	 mStatisticsUpdateTime(),
	 mStatisticsNumFrames(0),
	 mWorld(mWindow)
{
	//mWindow.setVerticalSyncEnabled(true);

	// Statistics text
	mFont.loadFromFile("src/Media/Sansation.ttf");
	mStatisticsText.setFont(mFont);
	mStatisticsText.setPosition(5.f ,5.f);
	mStatisticsText.setCharacterSize(10);
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while (mWindow.isOpen()) {
		sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;
		while (timeSinceLastUpdate > TimePerFrame) {
			timeSinceLastUpdate -= TimePerFrame;
			processEvents();
			update(TimePerFrame);
		}

		updateStatistics(elapsedTime);
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (mWindow.pollEvent(event)) {
		switch (event.type) {
		case sf::Event::KeyPressed:
			handlePlayerInput(event.key.code, true);
			break;
		case sf::Event::KeyReleased:
			handlePlayerInput(event.key.code, false);
			break;
		case sf::Event::Closed:
			mWindow.close();
			break;
		}
	}
}

void Game::update(sf::Time deltaTime) {
	mWorld.update(deltaTime);
}

void Game::render() {
	mWindow.clear();
	mWorld.draw();

	mWindow.setView(mWindow.getDefaultView());
	mWindow.draw(mStatisticsText);
	mWindow.display();
}

void Game::updateStatistics(sf::Time elapsedTime) {
	mStatisticsUpdateTime += elapsedTime;
	mStatisticsNumFrames++;

	if (mStatisticsUpdateTime >= sf::seconds(1.f)) {
		mStatisticsText.setString(
			"Frames / Second = " + toString(mStatisticsNumFrames) + "\n" +
			"Time / Update = " + toString(mStatisticsUpdateTime.asMicroseconds() / mStatisticsNumFrames) + "us"
		);

		mStatisticsUpdateTime -= sf::seconds(1.f);
		mStatisticsNumFrames = 0;
	}
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed) {

}
