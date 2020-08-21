#pragma once

#include "State.hpp"
#include "ResourceManager.hpp"

#include "Background.hpp"




class ScoreState : public State
{
private:
	mf::Button		*mBackBtn;
	Background		mBackground;
	//Sound			mSound;

public:
	ScoreState(Window *tWindow);
	~ScoreState();

	void		Init();
	void		HandleEvents();
	void		Update();
	void		Render();
};

