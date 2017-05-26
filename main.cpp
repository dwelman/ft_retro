#include "Vector2.hpp"
#include "Entity.hpp"
#include "GameManager.h"
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
	ship.Move(Vector2(10, 10));
	
	GameManager gm;
	gm.PushEntity(ship);
	gm.PushEntity(ship2);
	ship.Move(Vector2(-10, -10));
	gm.CheckCollisions();
	/*bool	running = true;

	while (running)
	{

	}*/
}