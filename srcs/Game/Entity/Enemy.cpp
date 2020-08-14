#include "Enemy.hpp"

Enemy::Enemy(EventHandler	*tEventHandler, Window *tWindow, sf::Vector2f tPlayerPos)
:mEventHandler(tEventHandler)
{
	mWindow = tWindow;
	
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
	mVelocity += mTrajectory;
	Entity::Update();
}

