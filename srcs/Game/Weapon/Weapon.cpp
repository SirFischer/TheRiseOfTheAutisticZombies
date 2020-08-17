#include "Weapon.hpp"

Weapon::Weapon(std::list<std::unique_ptr<Bullet>> *tBulletList)
{
	mBulletList = tBulletList;
	sf::Texture	*muzzleTex = ResourceManager::LoadTexture("assets/textures/muzzle.png");
	mMuzzle.setTexture(*muzzleTex);
	mMuzzle.setScale(0.2, 0.2);

	sf::SoundBuffer	*sbuff = ResourceManager::LoadSoundBuffer("assets/audio/gun_shot.wav");
	mSound.setBuffer(*sbuff);
	mSound.setVolume(80);
}

Weapon::~Weapon()
{
}

void		Weapon::Update(sf::Vector2f tPos, float tRotation)
{
	mPos = tPos;
	mRotation = tRotation;
	mMuzzleCounter--;
	tPos.x += (cos(mRotation - 0.28) * 132.0);
	tPos.y += (sin(mRotation - 0.28) * 132.0);
	mMuzzle.setOrigin(0, 10);
	mMuzzle.setRotation(((mRotation / M_PI) * 180.f) + 90);
	mMuzzle.setPosition(tPos);
}


void		Weapon::Fire()
{
	if (mFireRateClock.getElapsedTime().asSeconds() > (1.f / mFireRate))
	{
		mFireRateClock.restart();
		mBulletList->push_back(std::unique_ptr<Bullet>(new Bullet(mBulletSpeed, mRotation, mPos)));
		mMuzzleCounter = 4;
		mSound.play();
	}
}

void		Weapon::Render(Window *tWindow)
{
	if (mMuzzleCounter > 0)
		tWindow->Draw(mMuzzle);
}