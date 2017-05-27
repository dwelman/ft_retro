#pragma once
#include <iostream>
#include <time.h>
#include <unistd.h>

#ifndef INT32_MAX
# define INT32_MAX        2147483647i32
#endif // !INT32_MAX

#define CYCLEL_MS 

class GameClock
{
	clock_t _clock;
	clock_t	_fps;
	clock_t	_interval;
	clock_t	_cycleStart; 

public:
	GameClock();
	GameClock(clock_t fps);
	~GameClock();
	GameClock(const GameClock &cpy);

	GameClock		&operator=(const GameClock &cpy);
	void	setFps(const clock_t fps);
	void	startCycle();
	void	clockStart();
	int		getSeconds() const;
	int		getInterval() const;
	int		getSleepTime() const;
};

