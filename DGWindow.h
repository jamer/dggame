#ifndef DGWINDOW_H
#define DGWINDOW_H

#include <memory>
#include <string>
#include "DGEvent.h"

class sf::RenderWindow;

class DGWindow
{
public:
	DGWindow(std::string title, int width, int height);

	bool isOpen();
	bool hasEvent();
	DGEvent getEvent();

	void clear();
	void display();
	void close();

private:
	std::unique_ptr<sf::RenderWindow> sfmlWindow;
};

#endif
