#ifndef DGEVENT_H
#define DGEVENT_H

#include <SFML/Window/Event.hpp>

enum DGKey {
	DGEscapeKey = sf::Keyboard::Escape,
	DGLeftShiftKey = sf::Keyboard::LShift,
	DGUpArrowKey = sf::Keyboard::Up,
	DGDownArrowKey = sf::Keyboard::Down,
	DGLeftArrowKey = sf::Keyboard::Left,
	DGRightArrowKey = sf::Keyboard::Right,
	DGZKey = sf::Keyboard::Z
};

enum DGMouseButton
{
	DGLeftMouseButton = sf::Mouse::Left,
	DGRightMouseButton = sf::Mouse::Right
};

struct DGMouseClick
{
	int x, y;
	DGMouseButton button;
};

#endif
