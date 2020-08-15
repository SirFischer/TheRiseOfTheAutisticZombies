#pragma once

#include "State.hpp"

#include "Background.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "EventHandler.hpp"

#define SPAWN_INTERVAL 0.75

class GameState : public State
{
private:
	Background				mBackground;
	EventHandler			mEventHandler;
	Player					mPlayer;

	sf::Sprite				mTarget;

	void					LoadDefaultKeys();

	//Spawner
	sf::Clock							mSpawnerClock;
	std::list<Entity *>					mEntities;
	std::list<std::unique_ptr<Bullet>>	mBullets;
	void					Spawn();
	void					Despawn();

public:
	GameState(Window *tWindow);
	~GameState();

	void					Init();
	void					HandleEvents();
	void					Update();
	void					Render();
};

