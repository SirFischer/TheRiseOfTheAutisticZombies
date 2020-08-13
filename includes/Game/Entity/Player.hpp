#pragma once

#include "Entity.hpp"
#include "EventHandler.hpp"

class Player : public Entity
{
private:
	EventHandler	*mEventHandler;
	Window			*mWindow;
	
public:
	Player(EventHandler *tEventHandler, Window *tWindow);
	~Player();

	void		Update();
	void		HandleEvents();
};

