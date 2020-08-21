#include "Core.hpp"
#include <SFML/Audio.hpp>

void	Init()
{
	Score::Init();
}

int main( void )
{

	Window		window;

	StateManager	stateManager(&window);
	Init();
	stateManager.Run();

	return (0);
}