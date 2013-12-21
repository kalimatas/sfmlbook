#ifndef AIRCRAFT_HPP_
#define AIRCRAFT_HPP_

#include "Entity.hpp"

class Aircraft : public Entity
{
public:
	enum Type {
		Eagle,
		Raptor
	};

	explicit Aircraft(Type type);

private:
	Type mType;
};

#endif /* AIRCRAFT_HPP_ */
