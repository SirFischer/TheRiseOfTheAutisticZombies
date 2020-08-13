#include "Player.hpp"

Player::Player(EventHandler	*tEventHandler, Window *tWindow)
:mEventHandler(tEventHandler)
{
	mWindow = tWindow;
}

Player::~Player()
{
}

void		Player::Update()
{
	Entity::Update();
	if (mPos.x < 0)
	{
		mPos.x = 0;
		mVelocity.x = 0;
	}
	if (mPos.x > mWindow->GetSize().x)
	{
		mPos.x = mWindow->GetSize().x;
		mVelocity.x = 0;
	}
	if (mPos.y < 0)
	{
		mPos.y = 0;
		mVelocity.y = 0;
	}
	if (mPos.y > mWindow->GetSize().y)
	{
		mPos.y = mWindow->GetSize().y;
		mVelocity.y = 0;
	}
}

void		Player::HandleEvents()
{
	if (mEventHandler->GetActionState(ACTION::MOVE_FORWARD))
		mVelocity.y -= mAcceleration.y;
	if (mEventHandler->GetActionState(ACTION::MOVE_RIGHT))
		mVelocity.x += mAcceleration.x;
	if (mEventHandler->GetActionState(ACTION::MOVE_LEFT))
		mVelocity.x -= mAcceleration.x;
	if (mEventHandler->GetActionState(ACTION::MOVE_BACKWARD))
		mVelocity.y += mAcceleration.y;
	sf::Vector2f mMousePos = sf::Vector2f(mEventHandler->GetRelMousePos());
	mMousePos = (mPos - mMousePos);
	mRotation = std::atan2(mMousePos.y, mMousePos.x) + M_PI;
}