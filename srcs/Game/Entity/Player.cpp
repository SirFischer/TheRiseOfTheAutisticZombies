#include "Player.hpp"

Player::Player(EventHandler	*tEventHandler)
:mEventHandler(tEventHandler)
{
}

Player::~Player()
{
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
}