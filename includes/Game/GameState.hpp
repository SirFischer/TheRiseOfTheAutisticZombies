#pragma once

#include "StateManager/State.hpp"

#include "Background.hpp"
#include "Entity/Player.hpp"
#include "EventHandler/EventHandler.hpp"

class GameState : public State
{
private:
	Background		mBackground;
	EventHandler	mEventHandler;
	Player			mPlayer;

	sf::Sprite		mTarget;

	void			LoadDefaultKeys();
	
public:
	GameState(Window *tWindow);
	~GameState();

	void			Init();
	void			HandleEvents();
	void			Update();
	void			Render();
};

