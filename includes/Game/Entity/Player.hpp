#pragma once

#include "Entity.hpp"

class Player : public Entity
{
private:
	/* data */
public:
	Player(/* args */);
	~Player();

	void		HandleEvents(sf::Event &tEvent);
};

