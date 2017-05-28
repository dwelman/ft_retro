#include "Vector2.hpp"
#include "Entity.hpp"
#include "GameManager.hpp"

#include "GameClock.hpp"
#include <iostream>

inline int screen_init(Vector2 const &screen_vals)
{
	initscr();
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(6, COLOR_CYAN, COLOR_BLACK);
	init_pair(7, COLOR_WHITE, COLOR_BLACK);
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

void	setColor(char c)
{
	switch (c)
	{
		case '.':
			attron(COLOR_PAIR(7));
			break;
		case '*':
			attron(COLOR_PAIR(6));
			break;
		case 'o':
			attron(COLOR_PAIR(1));
			break;
		default:
			attron(COLOR_PAIR(3));
	}
}

void	unsetColor(char c)
{
	switch (c)
	{
		case '.':
			attroff(COLOR_PAIR(7));
			break;
		case '*':
			attroff(COLOR_PAIR(6));
			break;
		case 'o':
			attroff(COLOR_PAIR(1));
			break;
		default:
			attron(COLOR_PAIR(3));
	}
}

inline void	flushin(int lim)
{
	for (int i = 0; i < lim; i++)
		getch();
}

int	main(int argc, char **argv)
{
	GameClock 		clock(20);
	const int 		inlim  = 2;
	int 			sleep = 0;
	int 			maxX = 0;
	int 			maxY = 0;
	int 			col, row, horizontal_space, vertical_space;
	(void)argc;
	(void)argv;

	char **map = new char*[MAX_Y];

	for (int y = 0; y < MAX_Y; y++)
	{
		map[y] = new char[MAX_X];
	}

	GameManager gm;
	std::cout << "MaxX" << maxX << " MaxY " << maxY << std::endl;
	Vector2 screen(maxY, maxX);
	if (screen_init(screen) == 1)
	{
		std::cout << "Please Enlarge The Terminal Window." << std::endl;
		std::cout << "current screen size x =  " << maxX << " y = " << maxY << std::endl;
	}
	getmaxyx(stdscr, maxY, maxX);
	std::cout << screen.GetX() << " " << screen.GetY() << std::endl;
    vertical_space = (maxX - 4) / (MAX_Y + 20 - 1);
    horizontal_space = maxY / (MAX_X + 20 - 1);
    row = (maxX - 4 - (MAX_X + 20 - 1) * vertical_space) / 2;
    col = (maxY - (MAX_Y + 20 - 1) * horizontal_space) / 2;

	wborder(stdscr, 0, 0,0 ,0 ,0 ,0 ,0 ,0);
	bool	running = true;
	int steps = 0;
	bool pause = false;
	while (running)
	{
		clock.startCycle();
		switch (getch())
	    {
	        case KEY_LEFT:
				gm.SetMovementAxis("h", -1);
	            break;
	        case KEY_RIGHT:
				gm.SetMovementAxis("h", 1);
				break;
	        case KEY_UP:
				gm.SetMovementAxis("v", -1);
				fpurge(stdin);
	            break;
	        case KEY_DOWN:
				gm.SetMovementAxis("v", 1);
				break;
			case ' ':
				gm.GetPlayer()->Shoot();
				break;
			case 27:
				return (0);
		 }
		flushin(inlim);
		attron(COLOR_PAIR(3));
		mvprintw(maxY - 4 , maxX / 2 + 15, "Lives: %d", gm.GetLives());
		mvprintw(maxY - 2, 1, "Move with right/left. Shoot with space.");
		mvprintw(maxY - 3, 1, "Clock: %d", clock.getSeconds());
		mvprintw(maxY - 4, 1, "Points: %d", gm.GetScore());
		attroff(COLOR_PAIR(3));
		if (!pause)
		{
			gm.Update();
			gm.CheckCollisions();
			gm.FillMap(map);
			for (int y = 0; y < MAX_Y; y++) {
				for (int x = 0; x < MAX_X; x++) {
					setColor(map[y][x]);
					mvprintw(y, x * 2,
							 "%c", map[y][x]);
					unsetColor(map[y][x]);
				}
			}
			sleep = clock.getSleepTime() * 1000;
			if (sleep > 0)
				usleep(sleep);
			steps++;
		}
		getmaxyx(stdscr, maxY, maxX);
	  	if (maxX < MAX_X * 2 || maxY < MAX_Y)
		{
			wclear(stdscr);
			mvprintw(0, 0, "%s", "Please Enlarge The Terminal Window.");
			pause = true;
		}
		else
	   	{
			if (pause)
			{
				wclear(stdscr);
				pause = false;
			}
	   	}
		refresh();
	}
}
