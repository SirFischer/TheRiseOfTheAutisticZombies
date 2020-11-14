#pragma once

#include "State.hpp"
#include "ResourceManager.hpp"

#include "Background.hpp"
#include "Score.hpp"

#include <fstream>




class ScoreState : public State
{
private:
	mf::Button		*mBackBtn;
	Background		mBackground;
	
	sf::Text		mHighScoreText;

	void		InitHighscore();

public:
	ScoreState(Window *tWindow);
	~ScoreState();

	void		Init();
	void		HandleEvents();
	void		Update();
	void		Render();
};

