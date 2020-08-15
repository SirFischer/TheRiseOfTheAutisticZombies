#include "EventHandler.hpp"

EventHandler::EventHandler(Window *tWindow)
{
	mWindow = tWindow;
}

EventHandler::~EventHandler()
{
	
}

void	EventHandler::HandleEvents(sf::Event &tEvent)
{

	mTextInputString = "";

	switch (tEvent.type)
	{
	case tEvent.TextEntered:
		mTextInputString += tEvent.text.unicode;
		break;
	case sf::Event::KeyPressed:
		if (mKeyMap.find(tEvent.key.code) != mKeyMap.end())
		{
			mKeyStateMap[tEvent.key.code] = true;
			mActionMap[mKeyMap[tEvent.key.code]] = true;
		}
		break;
	
	case sf::Event::KeyReleased:
		if (mKeyMap.find(tEvent.key.code) != mKeyMap.end())
		{
			mKeyStateMap[tEvent.key.code] = false;
			mActionMap[mKeyMap[tEvent.key.code]] = false;
		}
		break;

	case sf::Event::MouseButtonPressed:
		if (mMouseMap.find(tEvent.mouseButton.button) != mMouseMap.end())
		{
			//mKeyStateMap[tEvent.key.code] = true;
			mActionMap[mMouseMap[tEvent.mouseButton.button]] = true;
		}
		break;
	
	case sf::Event::MouseButtonReleased:
		if (mMouseMap.find(tEvent.mouseButton.button) != mMouseMap.end())
		{
			//mKeyStateMap[tEvent.key.code] = true;
			mActionMap[mMouseMap[tEvent.mouseButton.button]] = false;
		}
		break;
	
	default:
		break;
	}

	mMousePosOffset = sf::Mouse::getPosition() - mLastMousePos;
	if (mCursorIsGrabbed)
		mWindow->SetRelMousePos(sf::Vector2i(mWindow->GetSize().x / 2, mWindow->GetSize().y / 2));
	mLastMousePos = sf::Mouse::getPosition();
}

bool		EventHandler::GetKeyState(int key)
{
	return (mKeyStateMap[key]);
}


bool		EventHandler::GetActionState(ACTION action)
{
	return (mActionMap[action]);
}

void		EventHandler::BindKey(int key, ACTION action)
{
	mKeyMap[key] = action;
}

void		EventHandler::BindMouseKey(int key, ACTION action)
{
	mMouseMap[key] = action;
}

void		EventHandler::UnbindAllKeys()
{
	mKeyMap.clear();
}

void		EventHandler::ToggleAction(ACTION action, bool state)
{
	mActionMap[action] = state;
}
