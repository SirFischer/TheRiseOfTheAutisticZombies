#pragma once

#include "Entity.hpp"
#include "EventHandler.hpp"

class Player : public Entity
{
private:
	EventHandler	*mEventHandler;
public:
	Player(EventHandler *tEventHandler);
	~Player();

	void		Update();
	void		HandleEvents();
};

