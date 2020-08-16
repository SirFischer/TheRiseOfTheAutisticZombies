#include "Bullet.hpp"

Bullet::Bullet(float speed, float rotation, sf::Vector2f tPos)
{
	mPos = tPos;
	mPos.x += (cos(rotation - 0.03) * 50.0);
	mPos.y += (sin(rotation - 0.03) * 50.0);
	(void)speed;
	mAcceleration.x = speed;
	mAcceleration.y = speed;
	mRotation = rotation;
	sf::Texture	*tex = ResourceManager::LoadTexture("assets/textures/bullet4.png");
	mSprite.setOrigin(0, 0);
	mSprite.setTextureRect(sf::IntRect(0, 0, 1000, 1000));
	mSprite.setTexture(*tex);
	mSprite.setScale(0.03, 0.03);
}

Bullet::~Bullet()
{
	
}

void		Bullet::Update()
{
	sf::Vector2f	tmp = mAcceleration;
	tmp.x *= cos(mRotation);
	tmp.y *= sin(mRotation);
	mVelocity += tmp;
	Entity::Update();
}

