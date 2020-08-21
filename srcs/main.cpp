#include "Core.hpp"
#include <SFML/Audio.hpp>

int main( void )
{

	Window		window;

	StateManager	stateManager(&window);
	stateManager.Run();

	return (0);
}