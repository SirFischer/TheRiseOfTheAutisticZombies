#pragma once

#include "ResourceManager.hpp"
#include "Window.hpp"

class Score
{
private:
	static int				mPoints;

	static sf::Text			mScoreText;

	Score();
	~Score();
public:

	static	void		Init();
	static	void		ScorePoints(int tPoints);
	static	void		Update();
	static	void		Render(Window *tWindow);
};