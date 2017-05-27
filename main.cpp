#include "Vector2.hpp"
#include "Entity.hpp"
#include "GameManager.hpp"
#include "EntityFactory.hpp"
#include "ShootingEntity.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	EntityFactory factory;
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
	factory.learnEntity(&ship);

	Entity	*ship2 = factory.createEntity("Player");
	ship2->Move(Vector2(10, 10));
	GameManager gm;
	gm.PushEntity(ship);
	gm.PushEntity(*ship2);
	for (unsigned int i = 0; i < 10; i++)
	{
		gm.CheckCollisions();
	}
	/*bool	running = true;

	while (running)
	{

	}*/
}
