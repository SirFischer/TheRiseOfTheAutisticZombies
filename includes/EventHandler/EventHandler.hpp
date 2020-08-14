#pragma once

#include "System/Window.hpp"
#include "Actions.hpp"

class EventHandler
{
private:
	Window								*mWindow;
	std::map<int, bool>	mKeyStateMap;
	std::map<int, ACTION>				mKeyMap;
	std::map<ACTION, bool>				mActionMap;
	std::map<ACTION, bool>				mSubActionMap;
	std::string							mTextInputString;

	bool								mCursorIsGrabbed = false;
	sf::Vector2i						mLastMousePos;
	sf::Vector2i						mMousePosOffset;

public:
	EventHandler(Window *tWindow);
	~EventHandler();

	void			HandleEvents(sf::Event &tEvent);

	bool			GetKeyState(int key);
	bool			GetActionState(ACTION action);
	bool			GetSubActionState(ACTION action);
	void			BindKey(int key, ACTION action);
	void			ToggleAction(ACTION action, bool state);
	void			UnbindAllKeys();

	std::string		GetStringEntered() { return (mTextInputString);}
	sf::Vector2i	GetMousePos() {return (sf::Mouse::getPosition());}
	sf::Vector2i	GetRelMousePos() {return (mWindow->GetRelMousePos());}
	sf::Vector2i	GetMousePosOffset() {return (mMousePosOffset);}

	void			SetCursorLock(bool tLock) {mCursorIsGrabbed = tLock;}
};