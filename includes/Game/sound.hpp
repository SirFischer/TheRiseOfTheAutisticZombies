#pragma once

#include <iostream>

#include <SFML/Audio.hpp>

class Sound
{
private:
sf::Music mMusic;

sf::SoundBuffer	mBuffer;
sf::Sound		mSound;

public:
    Sound(/* args */);
    ~Sound();

	void	Play();
};

