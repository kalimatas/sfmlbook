#ifndef RESOURCEIDENTIFIES_HPP_
#define RESOURCEIDENTIFIES_HPP_

namespace sf {
	class Texture;
}

namespace Textures {
	enum ID {
		Eagle,
		Raptor,
	};
}

template <typename Resource, typename Identifier>
class ResourceHolder;

typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;

#endif /* RESOURCEIDENTIFIES_HPP_ */
