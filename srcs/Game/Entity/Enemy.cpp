#include "Enemy.hpp"

Enemy::Enemy(EventHandler	*tEventHandler, Window *tWindow, sf::Vector2f tPlayerPos)
:mEventHandler(tEventHandler)
{
	mWindow = tWindow;
	mAcceleration = sf::Vector2f(0.5, 0.5);
	
	//POS
	int pos = ((rand() % 360) / 180.0) * M_PI;
	mPos = sf::Vector2f(cos(pos) * mWindow->GetSize().x, sin(pos) * mWindow->GetSize().x);
	mPos.x += mWindow->GetSize().x / 2.0;
	mPos.y += mWindow->GetSize().y / 2.0;
	
	//TRAJ
	//int traj = (((rand() % 20) - 10) / 180.0) * M_PI;
	tPlayerPos -= mPos;
	double dist = sqrt((tPlayerPos.x * tPlayerPos.x) + (tPlayerPos.y * tPlayerPos.y));
	tPlayerPos.x /= dist;
	tPlayerPos.y /= dist;
	mTrajectory.x = tPlayerPos.x;// + (tPlayerPos.x * cos(traj));
	mTrajectory.y = tPlayerPos.y;// + (tPlayerPos.y * sin(traj));
}

Enemy::~Enemy()
{
}

void		Enemy::Update()
{
	mRotation = std::atan2(-mVelocity.y, -mVelocity.x) + M_PI;
	mVelocity += sf::Vector2f(mTrajectory.x * mAcceleration.x, mTrajectory.y * mAcceleration.y);
	Entity::Update();
}

void		Enemy::SetTrajectory(sf::Vector2f tPlayerPos)
{
	tPlayerPos -= mPos;
	double dist = sqrt((tPlayerPos.x * tPlayerPos.x) + (tPlayerPos.y * tPlayerPos.y));
	tPlayerPos.x /= dist;
	tPlayerPos.y /= dist;
	mTrajectory.x = tPlayerPos.x;
	mTrajectory.y = tPlayerPos.y;
}


