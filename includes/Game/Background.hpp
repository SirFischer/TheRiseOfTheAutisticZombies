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

	void		Update();

	void		Render(Window *tWindow);
};

