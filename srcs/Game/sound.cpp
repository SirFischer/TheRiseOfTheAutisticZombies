#include "sound.hpp"


Sound::Sound(/* args */)
{

	mMusic.openFromFile("assets/audio/asmr-keyboard-clicks.wav");
	mMusic.setVolume(20);
	mMusic.play();

}

Sound::~Sound()
{
}
