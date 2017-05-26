#include "Vector2.hpp"
#include "Entity.hpp"
#include "GameManager.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	
	MapObject mo(6);
	mo.PushElement(MapElement('.', 0, 0));
	mo.PushElement(MapElement('|', 1, 0));
	mo.PushElement(MapElement('.', 2, 0));
	mo.PushElement(MapElement('/', 0, 1));
	mo.PushElement(MapElement('|', 1, 1));
	mo.PushElement(MapElement('\\', 2, 1));

	Entity ship("Player", mo);
	Entity ship2(ship);

	GameManager gm;
	gm.PushEntity(ship);
	gm.PushEntity(ship2);
	for (unsigned int i = 0; i < 10; i++)
	{
		gm.CheckCollisions();
	}
	/*bool	running = true;

	while (running)
	{

	}*/
}