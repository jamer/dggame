#include <iostream>
#include <stdlib.h>

#include "DGWindow.h"

DGWindow *globalWindow = NULL;

struct DGWindowState
{
	std::unique_ptr<sf::RenderWindow> sfmlWindow;
	std::vector<DGKey> keyPresses;
	std::vector<DGMouseClick> mouseClicks;
};

DGWindow::DGWindow(std::string title, int width, int height)
	: state(new DGWindowState)
{
	if (globalWindow) {
		std::cerr << "You are trying to create a second DGWindow object!" << std::endl;
		exit(1);
	}
	globalWindow = this;
	state->sfmlWindow = new sf::RenderWindow(sf::VideoMode(width, height), title);
	state->sfmlWindow->setVerticalSyncEnabled(true);
}

bool DGWindow::isOpen()
{
	return state->sfmlWindow->isOpen();
}

bool DGWindow::isKeyDown(DGKey key)
{
	return false;
}

bool DGWindow::hasNewKeyPress()
{
	return false;
}
DGKey DGWindow::getKeyPress()
{
	return DGEscapeKey;
}

bool DGWindow::hasNewMouseClick()
{
	return false;
}
DGMouseClick DGWindow::getMouseClick()
{
	return { 0, 0, DGLeftMouseButton };
}

void DGWindow::clear()
{
	state->sfmlWindow->clear();
}
void DGWindow::display()
{
	state->sfmlWindow->display();

	state->keyPresses.clear();
	state->mouseClicks.clear();

	sf::Event event;
	while (window.pollEvent(event))
	{
		switch (event.type) {
		case sf::Event::Closed:
			close();
			break;
		case sf::Event::KeyPressed:
			keyPresses.push_back(event.key.code);
			break;
		case sf::Event::MouseButtonPressed:
			mouseClicks.push_back({ event.mouse.x, event.mouse.y, event.mouse.button });
			break;
		}
	}
}
void DGWindow::close()
{
	state->sfmlWindow->close();
}
