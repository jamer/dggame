# DG Game

This C++ library provides a simple API for creating small video games with a
complexity level appropriate for those who have just started learning
programming. It wraps and takes inspiration from the fantastic
[SFML](http://www.sfml-dev.org/) library.

## Usage

```c++
#include "DGGame.h"

int main()
{
	// Create a window with the title "My First Game", a width of 800
	// pixels, and a height of 600 pixels.
	DGWindow window("My First Game", 800, 600);

	// Create an image of a cookie.
	DGSprite cookie("Assets/cookie.png");

	// By default, a sprite position measures the distance from the
	// top-left corner of the screen to the top-left corner of the sprite.
	// Change this to be a measurement to the center of the sprite.
	cookie.useCenteredCoordinates();

	// Center the cookie on the screen.
	cookie.setPosition(400, 300);

	while (window.isOpen())
	{

		// Iterate over all the user-generated events that have
		// happened since the last frame.
		while (window.hasEvent())
		{
			DGEvent event = window.getEvent();

			// An event could be a keyboard press or a mouse click.
			if (event.type == DGKeyPressEvent)
			{
				if (event.key == DGEscapeKey)
				{
					window.close();
				}
			}
		}

		// Start drawing our frame with a clear slate.
		window.clear();

		// Draw the cookie at the last position we set for it.
		cookie.draw();

		// Upload the image we've drawn to the screen. This will pause
		// our program until at least 1/60th of a second has gone by
		// since the last frame, effectively giving us a 60 frame per
		// second visual.
		window.display();
	}
	return 0;
}
```

## History

DG Game was originally written for use in making awesome games at the
[Developers' Guild](https://developersguild.io/) computer science club at De
Anza College in Cupertino, California.
