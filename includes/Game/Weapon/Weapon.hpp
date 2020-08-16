#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include <memory>

#include "Bullet.hpp"

class Weapon
{
private:
	float						mFireRate = 7;
	float						mBulletSpeed = 2.5;

	sf::Vector2f				mPos;
	float						mRotation = 0;

	sf::Clock					mFireRateClock;

	std::list<std::unique_ptr<Bullet>> *mBulletList;

	sf::Sprite					mMuzzle;
	int							mMuzzleCounter = 0;

public:
	Weapon(std::list<std::unique_ptr<Bullet>>	*tBulletList);
	~Weapon();

	void		Update(sf::Vector2f tPos, float tRotation);
	void		Fire();
	void		Render(Window *tWindow);
};
