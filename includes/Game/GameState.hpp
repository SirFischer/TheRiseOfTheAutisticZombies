#pragma once

#include "State.hpp"

#include "Background.hpp"
#include "Player.hpp"
#include "EventHandler.hpp"

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

