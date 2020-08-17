#include "sound.hpp"


Sound::Sound(/* args */)
{

	mMusic.openFromFile("assets/audio/game-music.wav");
	mMusic.setVolume(5);
	mMusic.play();

}

Sound::~Sound()
{
}
