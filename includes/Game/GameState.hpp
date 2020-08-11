#pragma once

#include "State.hpp"

#include "Background.hpp"
#include "Player.hpp"

class GameState : public State
{
private:
	Background		mBackground;

	Player			mPlayer;
	
public:
	GameState(Window *tWindow);
	~GameState();

	void		Init();
	void		HandleEvents();
	void		Update();
	void		Render();
};

