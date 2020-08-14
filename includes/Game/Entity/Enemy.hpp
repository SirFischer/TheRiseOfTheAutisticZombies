#pragma once

#include "Entity.hpp"
#include "EventHandler.hpp"
#include <random>

class Enemy : public Entity
{
private:
	EventHandler	*mEventHandler;
	Window			*mWindow;

	sf::Vector2f	mTrajectory;

public:
	Enemy(EventHandler *tEventHandler, Window *tWindow, sf::Vector2f tPlayerPos);
	~Enemy();

	void		Update();
};

