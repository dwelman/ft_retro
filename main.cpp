#include "Vector2.hpp"
#include "Entity.hpp"
#include "GameManager.hpp"
#include <ncurses.h>
#include "GameClock.hpp"
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
	curs_set(FALSE);
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
	GameClock clock(1);
	(void)argc;
	(void)argv;

	char **map = new char*[MAX_Y];

	for (int y = 0; y < MAX_Y; y++)
	{
		map[y] = new char[MAX_X];
	}

	int maxX = 0;
	int maxY = 0;

	GameManager gm;
	std::cout << "MaxX" << maxX << " MaxY " << maxY << std::endl;

	Vector2 screen(maxX, maxY);
  	int 		sleep = 0;

	if (screen_init(screen) == 1)
	{
		std::cout << "Please Enlarge The Terminal Window." << std::endl;
		std::cout << "current screen size x =  " << maxX << " y = " << maxY << std::endl;
	}
	getmaxyx(stdscr, maxX, maxY);

	std::cout << screen.GetX() << " " << screen.GetY() << std::endl;

    int col, row, horizontal_space, vertical_space;

    vertical_space = (maxX - 4) / (MAX_X - 1);
    horizontal_space = maxY / (MAX_Y - 1);

    row = (maxX - 4 - (MAX_X - 1) * vertical_space) / 2;
    col = (maxY - (MAX_Y - 1) * horizontal_space) / 2;

	bool	running = true;
	int steps = 0;
	while (running)
	{
		clock.startCycle();
		//attron(A_BOLD);
		//mvprintw(row + play_y * vertical_space, col + play_x * horizontal_space, "%c", '^');
		//attroff(A_BOLD);
	    move(row + 27 * vertical_space, col + 15 * horizontal_space);
	      // change_refresh_time();
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
			case 27:
				return (0);
		 }
		attron(COLOR_PAIR(3));
		mvprintw(maxX - 1, 1, "Move with right/left. Shoot with space.");
		mvprintw(maxX - 2, 1, "Clock: %d", clock.getSeconds());
		mvprintw(maxX - 3, 1, "Points: %d", 0);
		attroff(COLOR_PAIR(3));
		if (steps > 600)
		{
			gm.Update();
			steps = 0;
		}
		gm.CheckCollisions();
		gm.FillMap(map);
		for (int y = 0; y < MAX_Y; y++)
	    {
	        for (int x = 0; x < MAX_X; x++)
	        {
				attron(COLOR_PAIR(3));
				mvprintw(row + y * vertical_space, col + x * horizontal_space,
	                 "%c", map[y][x]);
				attroff(COLOR_PAIR(3));
	        }
	    }
		refresh();
		sleep = clock.getSleepTime() / 1000;
		if (sleep > 0)
			usleep(sleep);
		steps++;
	}

}
