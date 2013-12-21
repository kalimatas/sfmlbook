#ifndef AIRCRAFT_HPP_
#define AIRCRAFT_HPP_

#include "Entity.hpp"
#include <SFML/Graphics.hpp>

class Aircraft : public Entity
{
public:
	enum Type {
		Eagle,
		Raptor
	};

	explicit Aircraft(Type type);
	virtual void drawCurrent(sf::RenderTarget&, sf::RenderStates) const;

private:
	Type mType;
	sf::Sprite mSprite;
};

#endif /* AIRCRAFT_HPP_ */
