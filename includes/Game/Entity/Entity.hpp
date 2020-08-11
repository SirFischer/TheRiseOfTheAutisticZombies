#pragma once

#include "Window.hpp"

class Entity
{
protected:
	sf::Vector2f	mPos;
	sf::Vector2f	mVelocity = sf::Vector2f(0, 0);
	float			mDragCoefficient = 0.98;

	sf::Texture		mTexture;
	sf::Sprite		mSprite;

public:
	Entity(/* args */);
	~Entity();

	void		Update();
	void		HandleEvents(sf::Event &tEvent);
	void		Render(Window *tWindow);
};

