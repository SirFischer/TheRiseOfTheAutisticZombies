#include "Background.hpp"


Background::Background(std::string tPath, sf::Vector2f tSize)
{
	mTexture = ResourceManager::LoadTexture(tPath);
	mBackground.setTexture(mTexture);
	mBackground.setSize(tSize);
	mBackground.setPosition(0, 0);
}

Background::~Background()
{
}

void		Background::Update()
{
	//UPDATE BACKGROUND?? (SMOKE, LIGHT, ETC...)
}

void		Background::Render(Window *tWindow)
{
	tWindow->Draw(mBackground);
}