#ifndef DGEVENT_H
#define DGEVENT_H

#include <SFML/Window/Event.hpp>

enum DGEventType {
	DGKeyPressEvent = sf::Event::EventType::KeyPressed
};

enum DGKey {
	DGEscapeKey = sf::Keyboard::Key::Escape
};

class DGEvent
{
public:
	DGEventType type;
	DGKey key;
};

#endif
