#pragma once

#include <iostream>

#include <SFML/Audio.hpp>

class Sound
{
private:
sf::Music mMusic;


public:
    Sound(/* args */);
    ~Sound();

	void	Play();
};

