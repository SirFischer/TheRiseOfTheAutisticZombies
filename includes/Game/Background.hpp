#pragma once

#include "../System/Window.hpp"
#include "../ResourceManager/ResourceManager.hpp"

class Background
{
private:
	sf::Texture			*mTexture;
	sf::RectangleShape	mBackground;
	
public:
	Background(std::string tPath, sf::Vector2f tSize);
	~Background();

	void		SetSize(sf::Vector2f tSize){mBackground.setSize(tSize);}
	void		SetPos(sf::Vector2f tPos){mBackground.setPosition(tPos);}

	void		Update();

	void		Render(Window *tWindow);
};

