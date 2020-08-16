#pragma once

#include "Entity.hpp"
#include "EventHandler.hpp"
#include "Weapon.hpp"

class Player : public Entity
{
private:
	EventHandler	*mEventHandler;
	Window			*mWindow;
	Weapon			mWeapon;

	void		DetectBorderCollisions();

public:
	Player(EventHandler *tEventHandler, Window *tWindow, std::list<std::unique_ptr<Bullet>> *mBulletList);
	~Player();

	void		Update();
	void		HandleEvents();
	void		Render(Window *tWindow);
};

