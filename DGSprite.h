#ifndef DGSPRITE_H
#define DGSPRITE_H

#include <memory>
#include <string>

class sf::Sprite;

class DGSprite
{
	DGSprite(std::string path);

	void draw();

	void useCenteredCoordinates();
	void setPosition(float x, float y);

private:
	std::unique_ptr<sf::Sprite> sfmlSprite;
};

#endif
