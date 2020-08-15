#include "Weapon.hpp"

Weapon::Weapon(std::list<std::unique_ptr<Bullet>> *tBulletList)
{
	mBulletList = tBulletList;
}

Weapon::~Weapon()
{
}

void		Weapon::Update(sf::Vector2f tPos, float tRotation)
{
	mPos = tPos;
	mRotation = tRotation;
}


void		Weapon::Fire()
{
	if (mFireRateClock.getElapsedTime().asSeconds() > (1.f / mFireRate))
	{
		mFireRateClock.restart();
		mBulletList->push_back(std::unique_ptr<Bullet>(new Bullet(mBulletSpeed, mRotation, mPos)));
	}
}