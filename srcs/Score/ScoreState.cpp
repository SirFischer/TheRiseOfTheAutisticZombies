#include "ScoreState.hpp"

ScoreState::ScoreState(Window *tWindow)
:mBackground ("assets/textures/sand-02.jpg", sf::Vector2f(tWindow->GetSize()))
{
	mWindow = tWindow;
}

ScoreState::~ScoreState()
{
}

void		ScoreState::InitHighscore()
{

	mHighScoreText.setFont(*ResourceManager::LoadFont("assets/fonts/Roboto-Regular.ttf"));
	mHighScoreText.setString("Highscore: 0");
	mHighScoreText.setPosition((mWindow->GetSize().x / 2) - 220, (mWindow->GetSize().y / 2) - 100);
	mHighScoreText.setCharacterSize(50);
	std::fstream	stream;
	std::string		scorestring;
	stream.open("assets/highscore/highscore.score", std::fstream::in);
	stream >> scorestring;
	stream.close();
	int score = std::stoi(scorestring);
	if (Score::GetScore() > score)
	{
		mHighScoreText.setString("New Highscore: " + std::to_string(Score::GetScore()) + "!");
		stream.open("assets/highscore/highscore.score", std::fstream::out);
		stream << std::to_string(Score::GetScore()) << std::endl;
		stream.close();
	}
	else
	{
		mHighScoreText.setString("Highscore: " + std::to_string(score) + "\n You scored: " + std::to_string(Score::GetScore()));
	}
	
}

void		ScoreState::Init()
{
	mf::GUI::ClearWidgets();
	mIsActive = true;
	mStateReturnAction = StateAction::POP;
	mWindow->ShowCursor();
	mWindow->ReleaseCursor();

	/**
	 * INIT STATE AND GUI
	 **/

	//play Button
	StateAction	*actionReturn = &mStateReturnAction;
	bool		*active = &mIsActive;

	//Exit Button
	mBackBtn = mf::Button::Create(sf::Color::Cyan, sf::Color::Yellow);
	mBackBtn->SetPositionPercentage(true)->SetPosition(45, 75);
	mBackBtn->SetClickEvent([actionReturn, active] {
		*actionReturn = StateAction::POP;
		*active = false;
	});

	//Exit button color/text
	mBackBtn->SetTextFont(*ResourceManager::LoadFont("assets/fonts/Roboto-Regular.ttf"));
	mBackBtn->SetTextColor(sf::Color::Black);
	mBackBtn->SetTextPosition(sf::Vector2f(20, 5));
	mBackBtn->SetText("Back");

	mf::GUI::AddWidget(mBackBtn);

	InitHighscore();
	
}

void		ScoreState::HandleEvents()
{
	sf::Event event;
	while (mWindow->HandleEvent(event))
	{
		mf::GUI::HandleEvent(event);
		if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
		{
			mIsActive = false;
		}
	}
}

void		ScoreState::Update()
{
	
}

void		ScoreState::Render()
{
	mWindow->Clear(sf::Color::Black);
	mBackground.Render(mWindow);
	mWindow->Draw(mHighScoreText);
	mf::GUI::Render();
	mWindow->Render();

}