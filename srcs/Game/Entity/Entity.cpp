#include "Entity.hpp"

Entity::Entity(/* args */)
{
	mTexture.loadFromFile("assets/textures/survivor-idle_rifle_0.png");
	mSprite.setTexture(mTexture);
	mSprite.setPosition(mPos);
}

Entity::~Entity()
{
}

void		Entity::Update()
{
	mPos += mVelocity;
	mVelocity *= mDragCoefficient;
	if (std::abs(mVelocity.x) < 0.01)
		mVelocity.x = 0;
	if (std::abs(mVelocity.y) < 0.01)
		mVelocity.x = 0;
	mSprite.setPosition(mPos);
}

void		Entity::HandleEvents(sf::Event &tEvent)
{
	(void)tEvent;
}

void		Entity::Render(Window *tWindow)
{
	tWindow->Draw(mSprite);
}