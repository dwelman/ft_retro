#include "Vector2.hpp"
#include "Entity.hpp"
#include "GameManager.hpp"
#include <ncurses.h>
#include <iostream>

int screen_init(Vector2 const &screen_vals)
{
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
	nodelay(stdscr, TRUE);
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

	char **map = new char*[30];

	for (int y = 0; y < 30; y++)
	{
		map[y] = new char[30];
	}

	int maxX = 0;
	int maxY = 0;

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
	mo.PushElement(MapElement('.', 14, 26));
	mo.PushElement(MapElement('|', 15, 26));
	mo.PushElement(MapElement('.', 16, 26));
	mo.PushElement(MapElement('/', 14, 27));
	mo.PushElement(MapElement('|', 15, 27));
	mo.PushElement(MapElement('\\', 16, 27));

	Entity ship("Player", mo);

	gm.PushEntity(ship);

    int col, row, horizontal_space, vertical_space, score(0);

    vertical_space = (maxX - 4) / (30 - 1);
    horizontal_space = maxY / (30 - 1);

    row = (maxX - 4 - (30 - 1) * vertical_space) / 2;
    col = (maxY - (30 - 1) * horizontal_space) / 2;

	bool	running = true;

	while (running)
	{

		//attron(A_BOLD);
		//mvprintw(row + play_y * vertical_space, col + play_x * horizontal_space, "%c", '^');
		//attroff(A_BOLD);
	    //move(row + play_y * vertical_space, col + play_x * horizontal_space);
	      // change_refresh_time();
	    refresh();
	    switch (getch())
	    {
	        case KEY_LEFT:

	            break;

	        case KEY_RIGHT:
				break;

	        case KEY_UP:

	            break;
	        case KEY_DOWN:

	            break;
		 }
		 attron(COLOR_PAIR(3));
		 mvprintw(maxX - 1, 1, "Move with right/left. Shoot with space.");
		 mvprintw(maxX - 3, 1, "Points: %d", score);
		 attroff(COLOR_PAIR(3));

		 gm.FillMap(map);
		 for (int y = 0; y < 30; y++)
	     {
	         for (int x = 0; x < 30; x++)
	         {
	             mvprintw(row + y * vertical_space, col + x * horizontal_space,
	                  "%c", map[y][x]);
	         }
	     }
	 }
}
