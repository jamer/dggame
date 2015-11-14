#ifndef DGWINDOW_H
#define DGWINDOW_H

#include <memory>
#include <string>
#include "DGEvent.h"

#include <SFML/Graphics.hpp>

struct DGWindowState;

class DGWindow
{
public:
	DGWindow(std::string title, int width, int height);

	bool isOpen();

	bool isKeyPressed(DGKey key);

	bool hasNewKeyPress();
	DGKey getKeyPress();

	bool hasNewMouseClick();
	DGMouseClick getMouseClick();

	void clear();
	void display();
	void close();

private:
	DGWindowState* state;
};


#endif
