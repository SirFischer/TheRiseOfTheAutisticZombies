#pragma once

#include "State.hpp"

#include "Background.hpp"

class GameState : public State
{
private:
	Background		mBackground;
	
public:
	GameState(Window *tWindow);
	~GameState();

	void		Init();
	void		HandleEvents();
	void		Update();
	void		Render();
};

