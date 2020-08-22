#include "GameState.hpp"

GameState::GameState(Window *tWindow)
:mBackground("assets/textures/sand-02.jpg", sf::Vector2f(tWindow->GetSize()))
,mEventHandler(tWindow)
,mPlayer(&mEventHandler, tWindow, &mBullets)

{
	mWindow = tWindow;
	mWindow->HideCursor();
	srand(time(0));
}

GameState::~GameState()
{
	mWindow->ShowCursor();
	sf::Music	*music = ResourceManager::LoadMusic("assets/audio/Blazer Rail 2.wav");
	music->setVolume(10);
	music->stop();
	for (auto &i : mEntities)
	{
			delete i;
	}
}

void		GameState::LoadDefaultKeys()
{
	mEventHandler.BindKey(sf::Keyboard::W, ACTION::MOVE_FORWARD);
	mEventHandler.BindKey(sf::Keyboard::S, ACTION::MOVE_BACKWARD);
	mEventHandler.BindKey(sf::Keyboard::D, ACTION::MOVE_RIGHT);
	mEventHandler.BindKey(sf::Keyboard::A, ACTION::MOVE_LEFT);
	mEventHandler.BindMouseKey(sf::Mouse::Left, ACTION::SHOOT);
}


void		GameState::Init()
{
	mf::GUI::ClearWidgets();
	mIsActive = true;
	mStateReturnAction = StateAction::POP;
	mWindow->GrabCursor();
	Score::Init();
	LoadDefaultKeys();
	/**
	 * INIT STATE AND GUI
	 **/

	sf::Music	*music = ResourceManager::LoadMusic("assets/audio/Blazer Rail 2.wav");
	music->play();

	/**
	 * Init target
	 **/
	sf::Texture	*texture = ResourceManager::LoadTexture("assets/textures/target.png");
	mTarget.setTexture(*texture);
	mTarget.setOrigin(mTarget.getGlobalBounds().width / 2.0, mTarget.getGlobalBounds().height / 2.0);
	mTarget.setScale(0.12, 0.12);	
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
	Spawn();
	mBackground.Update();
	mPlayer.Update();
	mTarget.setPosition(sf::Vector2f(mWindow->GetRelMousePos()));
	HandleBulletLogic();
		
	for (auto &i : mEntities)
	{
		i->Update();
		sf::Vector2f	pos = i->GetPos();
		pos -= mPlayer.GetPos();
		double playerDistance = sqrt((pos.x * pos.x) + (pos.y * pos.y));
		if (playerDistance < 400)
			((Enemy *)i)->SetTrajectory(mPlayer.GetPos());
		if (playerDistance < 25)
		{
			mStateReturnAction = StateAction::SCORE;
			mIsActive = false;
		}
	}
	Despawn();
}

void		GameState::Render()
{
	mWindow->Clear(sf::Color::Green);
	mBackground.Render(mWindow);
	for (auto &i : mBullets)
		i->Render(mWindow);
	for (auto &i : mEntities)
		i->Render(mWindow);	
	mPlayer.Render(mWindow);
	Score::Render(mWindow);
	
	//RENDER YOUR STUFF
	mWindow->Draw(mTarget);
	mf::GUI::Render();
	mWindow->Render();
}



void		GameState::Spawn()
{
	if (mSpawnerClock.getElapsedTime().asSeconds() >= mSpawnInterval)
	{
		if (mSpawnInterval > 0.4)
			mSpawnInterval /= 1.008;
		mSpawnerClock.restart();
		mEntities.push_back(new Enemy(&mEventHandler, mWindow, mPlayer.GetPos()));
	}
}

void		GameState::Despawn()
{
	for (auto &i : mEntities)
	{
		sf::Vector2f	pos = i->GetPos();
		pos -= mPlayer.GetPos();
		if (sqrt((pos.x * pos.x) + (pos.y * pos.y)) > mWindow->GetSize().x + mWindow->GetSize().y)
		{
			mEntities.remove(i);
			delete i;
			break;
		}
	}
	for (auto &i : mBullets)
	{
		sf::Vector2f	pos = i->GetPos();
		pos -= mPlayer.GetPos();
		if (sqrt((pos.x * pos.x) + (pos.y * pos.y)) > mWindow->GetSize().x + mWindow->GetSize().y)
		{
			mBullets.remove(i);
			break;
		}
	}
}

void			GameState::HandleBulletLogic()
{
	for (auto &i : mBullets)
	{
		i->Update();
		for (auto &j : mEntities)
		{
			sf::Vector2f	pos = j->GetPos();
			pos -= i->GetPos();
			if (sqrt((pos.x * pos.x) + (pos.y * pos.y)) < 30)
			{
				j->TakeDamage(i->GetAttackDamage());
				((Enemy *)j)->SetTrajectory(mPlayer.GetPos());
				if (j->GetHP() <= 0)
				{
					Score::ScorePoints(15);
					mEntities.remove(j);
					delete j;
				}
				mBullets.remove(i);
				HandleBulletLogic();
				return ;
			}
		}
	}
}