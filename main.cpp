#include "Vector2.hpp"
#include "Entity.hpp"
#include "GameManager.hpp"
#include <ncurses.h>
#include <iostream>

int screen_init(Vector2 const &screen_vals)
{
	int maxX(0);
	int maxY(0);
	initscr();
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(6, COLOR_CYAN, COLOR_BLACK);
	raw();
	noecho();
	keypad(stdscr, TRUE);
	if ((screen_vals.GetX() < 30 + 4) || (screen_vals.GetY() < 30))
    {
		clear();
		endwin();
		std::cout << "This screen has rows " << screen_vals.GetX() << " and " << screen_vals.GetX() <<  "columns. resize window" << std::endl;
		return 1;
	}
	return 0;
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	int maxX(0);
	int maxY(0);

	GameManager gm;
	getmaxyx(stdscr, maxX, maxY);


	Vector2 screen(maxX, maxY);
	if (screen_init(screen) == 1)
	{
		std::cout << "Please Enlarge The Terminal Window." << std::endl;
		std::cout << "current screen size x =  " << maxX << " y = " << maxY << std::endl;
	}

	std::cout << screen.GetX() << " " << screen.GetY() << std::endl;

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
