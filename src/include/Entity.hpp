#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include <SFML/Graphics.hpp>

class Entity
{
public:
	void setVelocity(sf::Vector2f);
	void setVelocity(float, float);

	sf::Vector2f getVelocity() const;

private:
	sf::Vector2f mVelocity;
};

#endif /* ENTITY_HPP_s */
