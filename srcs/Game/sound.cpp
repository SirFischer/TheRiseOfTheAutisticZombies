#include "sound.hpp"


Sound::Sound(/* args */)
{

(mMusic.openFromFile("assets/audio/asmr-keyboard-clicks.wav"));

mMusic.play();

}

Sound::~Sound()
{
}