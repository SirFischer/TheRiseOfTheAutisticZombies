#pragma once

#include "StateManager/State.hpp"
#include "ResourceManager/ResourceManager.hpp"

#include "Game/Background.hpp"

#include "Game/sound.hpp"



class MenuState : public State
{
private:
	mf::Button		*mPlayBtn;
	mf::Button		*mQuitBtn;
	Background		mBackground;
	//Sound			mSound;

public:
	MenuState(Window *tWindow);
	~MenuState();

	void		Init();
	void		HandleEvents();
	void		Update();
	void		Render();
};

