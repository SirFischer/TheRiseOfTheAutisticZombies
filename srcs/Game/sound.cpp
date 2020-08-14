#include "Game/sound.hpp"


Sound::Sound(/* args */)
{

	mMusic.openFromFile("assets/audio/game-music.wav");
	mMusic.setVolume(20);
	mMusic.play();

}

Sound::~Sound()
{
}
