#ifndef WORLD_HPP_
#define WORLD_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "ResourceHolder.hpp"
#include "ResourceIdentifies.hpp"
#include "SceneNode.hpp"
#include "Aircraft.hpp"

#include <array>

class World: private sf::NonCopyable
{
public:
	explicit World(sf::RenderWindow&);
	void update(sf::Time);
	void draw();

private:
	void loadTextures();
	void buildScene();

private:
	enum Layer {
		Background,
		Air,
		LayerCount,
	};

private:
	sf::RenderWindow& mWindow;
	sf::View mWorldView;
	TextureHolder mTextures;
	SceneNode mSceneGraph;
	std::array<SceneNode*, LayerCount> mSceneLayers;

	sf::FloatRect mWorldBounds;
	sf::Vector2f mSpawnPosition;
	float mScrollSpeed;
	Aircraft* mPlayerAircraft;
};

#endif /* WORLD_HPP_ */
