#include "MenuState.hpp"

MenuState::MenuState(Window *tWindow)
:mBackground ("assets/textures/Menu_Background.jpg", sf::Vector2f(tWindow->GetSize()))
{
	mWindow = tWindow;
}

MenuState::~MenuState()
{
}

void		MenuState::Init()
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
	mPlayBtn = mf::Button::Create(sf::Color(0xaaaaaaff), sf::Color(0x666666ff));
	mPlayBtn->SetPositionPercentage(true)->SetPosition(45, 40);
	mPlayBtn->SetOutlineColor(sf::Color::Black)->SetOutlineThickness(1.f);
	StateAction	*actionReturn = &mStateReturnAction;
	bool		*active = &mIsActive;
	mPlayBtn->SetClickEvent([actionReturn, active] {
		*actionReturn = StateAction::GAME;
		*active = false;
	});

	//Play button color/text
	mPlayBtn->SetTextFont(*ResourceManager::LoadFont("assets/fonts/PressStart2P-Regular.ttf"));
	mPlayBtn->SetTextColor(sf::Color::Black);
	mPlayBtn->SetTextPosition(sf::Vector2f(20, 10));
	mPlayBtn->SetSize(170, 50);
	mPlayBtn->SetText("Play!");

	//Exit Button
	mQuitBtn = mf::Button::Create(sf::Color::Red, sf::Color(0xaa0000ff));
	mQuitBtn->SetPositionPercentage(true)->SetPosition(45, 50);
	mQuitBtn->SetSize(170, 50);
	mQuitBtn->SetOutlineColor(sf::Color::Black)->SetOutlineThickness(1.f);
	mQuitBtn->SetClickEvent([actionReturn, active] {
		*actionReturn = StateAction::POP;
		*active = false;
	});

	//Exit button color/text
	mQuitBtn->SetTextFont(*ResourceManager::LoadFont("assets/fonts/PressStart2P-Regular.ttf"));
	mQuitBtn->SetTextColor(sf::Color::Black);
	mQuitBtn->SetTextPosition(sf::Vector2f(20, 10));
	mQuitBtn->SetText("Exit!");

	mf::GUI::AddWidget(mPlayBtn);
	mf::GUI::AddWidget(mQuitBtn);
	
}

void		MenuState::HandleEvents()
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

void		MenuState::Update()
{
	
}

void		MenuState::Render()
{
	mWindow->Clear(sf::Color::Black);
	mBackground.Render(mWindow);
	mf::GUI::Render();
	mWindow->Render();

}