#pragma once

#include "State.hpp"
#include "ResourceManager.hpp"

#include "Background.hpp"
#include "sound.hpp"



class MenuState : public State
{
private:
	mf::Button		*mPlayBtn;
	mf::Button		*mQuitBtn;
	Background		mBackground;
	Sound			mSound;
	
public:
	MenuState(Window *tWindow);
	~MenuState();

	void		Init();
	void		HandleEvents();
	void		Update();
	void		Render();
};

