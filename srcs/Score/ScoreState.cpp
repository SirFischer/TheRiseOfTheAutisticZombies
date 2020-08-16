#include "ScoreState.hpp"

ScoreState::ScoreState(Window *tWindow)
:mBackground ("assets/textures/sand-02.jpg", sf::Vector2f(tWindow->GetSize()))
{
	mWindow = tWindow;
}

ScoreState::~ScoreState()
{
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
	mf::GUI::Render();
	mWindow->Render();

}