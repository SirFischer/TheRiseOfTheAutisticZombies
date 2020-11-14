#include "Score.hpp"

int Score::mPoints = 0;
sf::Text Score::mScoreText = sf::Text();
Score::Score()
{

}

Score::~Score()
{

}

void		Score::Init()
{
	sf::Font	*Font = ResourceManager::LoadFont("assets/fonts/PressStart2P-Regular.ttf");
	mPoints = 0;
	mScoreText.setFont(*Font);
	mScoreText.setString("Score = " + std::to_string(mPoints));
	mScoreText.setCharacterSize(30);
	mScoreText.setFillColor(sf::Color::Black);
	mScoreText.setPosition(600, 10);
}

void		Score::ScorePoints(int tPoints)
{
	mPoints += tPoints;
	mScoreText.setString("Score = " + std::to_string(mPoints));
	//printf("%d\n", Points); //For testing
}

void		Score::Render(Window *tWindow)
{
	tWindow->Draw(mScoreText);
}