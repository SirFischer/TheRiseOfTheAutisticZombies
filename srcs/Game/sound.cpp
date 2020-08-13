#include "sound.hpp"


Sound::Sound(/* args */)
{

	mBuffer.loadFromFile("assets/audio/asmr-keyboard-clicks.wav");
	mSound.setBuffer(mBuffer);
	mSound.setVolume(100);
	

}

Sound::~Sound()
{
}

void	Sound::Play()
{
	if (mSound.getStatus() != sf::Sound::Playing)
		mSound.play();
}