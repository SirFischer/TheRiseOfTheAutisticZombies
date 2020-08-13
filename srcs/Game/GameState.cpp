#include "GameState.hpp"

GameState::GameState(Window *tWindow)
:mBackground("assets/textures/sand-02.jpg", sf::Vector2f(tWindow->GetSize()))
,mEventHandler(tWindow)
,mPlayer(&mEventHandler)
{
	mWindow = tWindow;
	mWindow->HideCursor();
}

GameState::~GameState()
{
	mWindow->ShowCursor();
	sf::Music	*music = ResourceManager::LoadMusic("assets/audio/Blazer Rail 2.wav");
	music->stop();
}

void		GameState::LoadDefaultKeys()
{
	mEventHandler.BindKey(sf::Keyboard::W, ACTION::MOVE_FORWARD);
	mEventHandler.BindKey(sf::Keyboard::S, ACTION::MOVE_BACKWARD);
	mEventHandler.BindKey(sf::Keyboard::D, ACTION::MOVE_RIGHT);
	mEventHandler.BindKey(sf::Keyboard::A, ACTION::MOVE_LEFT);
}


void		GameState::Init()
{
	mf::GUI::ClearWidgets();
	mIsActive = true;
	mStateReturnAction = StateAction::POP;
	mWindow->GrabCursor();
	LoadDefaultKeys();
	/**
	 * INIT STATE AND GUI
	 **/

	sf::Music	*music = ResourceManager::LoadMusic("assets/audio/Blazer Rail 2.wav");
	music->play();
}

void		GameState::HandleEvents()
{
	sf::Event event;
	while (mWindow->HandleEvent(event))
	{
		mf::GUI::HandleEvent(event);
		mEventHandler.HandleEvents(event);
		
		if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
		{
			mIsActive = false;
		}
	}
	mPlayer.HandleEvents();
}

void		GameState::Update()
{
	mBackground.Update();
	mPlayer.Update();
}

void		GameState::Render()
{
	mWindow->Clear(sf::Color::Green);
	mBackground.Render(mWindow);
	mPlayer.Render(mWindow);
	//RENDER YOUR STUFF
	
	mf::GUI::Render();
	mWindow->Render();
}	