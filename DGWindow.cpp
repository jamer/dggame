#include <assert.h>
#include <iostream>
#include <stdlib.h>
#include <vector>

#include "DGWindow.h"

DGWindow *globalWindow = NULL;

struct DGWindowState
{
	sf::RenderWindow* sfmlWindow;
	std::vector<DGKey> keyPresses;
	std::vector<DGMouseClick> mouseClicks;
};

DGWindow::DGWindow(std::string title, int width, int height)
	: state(new DGWindowState)
{
	assert(globalWindow == nullptr);
	globalWindow = this;
	state->sfmlWindow = new sf::RenderWindow(sf::VideoMode(width, height), title);
	state->sfmlWindow->setVerticalSyncEnabled(true);
}

bool DGWindow::isOpen()
{
	return state->sfmlWindow->isOpen();
}

bool DGWindow::isKeyPressed(DGKey key)
{
	sf::Keyboard::Key sfmlKey = static_cast<sf::Keyboard::Key>(key);
	return sf::Keyboard::isKeyPressed(sfmlKey);
}

bool DGWindow::hasNewKeyPress()
{
	return state->keyPresses.size() > 0;
}

DGKey DGWindow::getKeyPress()
{
	assert(hasNewKeyPress());
	DGKey key = state->keyPresses.front();
	state->keyPresses.erase(state->keyPresses.cbegin());
	return key;
}

bool DGWindow::hasNewMouseClick()
{
	return state->mouseClicks.size() > 0;
}

DGMouseClick DGWindow::getMouseClick()
{
	assert(hasNewMouseClick());
	DGMouseClick click = state->mouseClicks.front();
	state->mouseClicks.erase(state->mouseClicks.cbegin());
	return click;
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
	DGKey key;
	DGMouseClick click;
	while (state->sfmlWindow->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			close();
			break;
		case sf::Event::KeyPressed:
			key = static_cast<DGKey>(event.key.code);
			state->keyPresses.push_back(key);
			break;
		case sf::Event::MouseButtonPressed:
			click.x = event.mouseButton.x;
			click.y = event.mouseButton.y;
			click.button = static_cast<DGMouseButton>(event.mouseButton.button);
			if (click.button == DGLeftMouseButton ||
			    click.button == DGRightMouseButton)
			{
				state->mouseClicks.push_back(click);
			}
			break;
		default:
			break;
		}
	}
}

void DGWindow::close()
{
	state->sfmlWindow->close();
}
