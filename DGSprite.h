#ifndef DGSPRITE_H
#define DGSPRITE_H

#include <memory>
#include <string>

#include <SFML/Graphics.hpp>

class DGSprite
{
	DGSprite(std::string path, float x, float y);

	void draw();

	void setPosition(float x, float y);
	void move(float x, float y);

	float getXPosition();
	float getYPosition();

	bool overlapsWith(DGSprite& otherSprite);

private:
	sf::Sprite* sfmlSprite;
};

#endif
