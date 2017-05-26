#include "Vector2.hpp"
#include "Entity.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	
	Entity	ship("Ship", Vector2(0, 0));
	
	for (unsigned int i = 0; i < 20; i++)
	{
		ship.Move(Vector2(1, 0));
		std::cout << ship.GetPos() << std::endl;
	}
	/*bool	running = true;

	while (running)
	{

	}*/
}