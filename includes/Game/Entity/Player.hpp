#pragma once

#include "Entity.hpp"
#include "EventHandler/EventHandler.hpp"

class Player : public Entity
{
private:
	EventHandler	*mEventHandler;
	Window			*mWindow;

	void		DetectBorderCollisions();

public:
	Player(EventHandler *tEventHandler, Window *tWindow);
	~Player();

	void		Update();
	void		HandleEvents();
};

