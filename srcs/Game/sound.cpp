#include "sound.hpp"


Sound::Sound(/* args */)
{

	mMusic.openFromFile("assets/audio/game-music.wav");
	mMusic.setVolume(10);
	mMusic.play();
	mMusic.setVolume(10);

}

Sound::~Sound()
{
}
