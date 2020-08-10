#include "GameState.hpp"

GameState::GameState(Window *tWindow)
:mBackground("assets/textures/sand-02.jpg", sf::Vector2f(tWindow->GetSize()))
{
	mWindow = tWindow;
	mWindow->HideCursor();
}

GameState::~GameState()
{
	mWindow->ShowCursor();
}

void		GameState::Init()
{
	mf::GUI::ClearWidgets();
	mIsActive = true;
	mStateReturnAction = StateAction::POP;

	/**
	 * INIT STATE AND GUI
	 **/
}

void		GameState::HandleEvents()
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

void		GameState::Update()
{
	mBackground.Update();
}

void		GameState::Render()
{
	mWindow->Clear(sf::Color::Green);
	mBackground.Render(mWindow);

	//RENDER YOUR STUFF
	
	mf::GUI::Render();
	mWindow->Render();
}