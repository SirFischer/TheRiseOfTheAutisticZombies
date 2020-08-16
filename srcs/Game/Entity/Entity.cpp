#include "Entity.hpp"

Entity::Entity(/* args */)
{
	mTexture.loadFromFile("assets/textures/survivor-idle_rifle_0.png");
	mSprite.setTexture(mTexture);
	mSprite.setPosition(mPos);
	mSprite.setScale(0.3, 0.3);
	mSprite.setOrigin(mSprite.getGlobalBounds().height, mSprite.getGlobalBounds().width);
}

void		Entity::HandleState()
{
	
}

void		Entity::Update()
{
	mPos += mVelocity;
	mVelocity *= mDragCoefficient;
	if (std::abs(mVelocity.x) < 0.05)
		mVelocity.x = 0;
	if (std::abs(mVelocity.y) < 0.05)
		mVelocity.y = 0;
	mSprite.setPosition(mPos);
	mSprite.setRotation(((mRotation / M_PI) * 180.f));
	HandleState();
}

void		Entity::HandleEvents()
{
	
}

void		Entity::Render(Window *tWindow)
{
	tWindow->Draw(mSprite);
}

void		Entity::TakeDamage(float tAttackDamage)
{
	mHP -= tAttackDamage;
	mVelocity = sf::Vector2f(mVelocity.x * 0.1, mVelocity.y * 0.1);
}
