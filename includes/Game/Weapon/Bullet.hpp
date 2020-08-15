#pragma once

#include <Window.hpp>
#include "Entity.hpp"

class Bullet : public Entity
{
private:
	float		mAttackDamage = 35;

public:
	Bullet(float speed, float rotation, sf::Vector2f tPos);
	~Bullet();

	void		Update();

	float		GetAttackDamage(){return (mAttackDamage);}
};
