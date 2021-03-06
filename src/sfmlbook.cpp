#include <cstdlib>
#include <stdexcept>
#include <iostream>
#include "include/Game.hpp"

int main() {
	try {
		Game game;
		game.run();
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
