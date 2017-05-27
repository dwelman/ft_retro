#include "GameClock.hpp"

GameClock::GameClock()
{
	_clock = clock();
}

GameClock::GameClock(clock_t fps)
{
	_clock = clock();
	setFps(fps);
}

GameClock::~GameClock()
{
}

GameClock::GameClock(const GameClock &cpy)
{
	*this = cpy;
}

GameClock & GameClock::operator=(const GameClock & cpy)
{
	_clock = cpy._clock;
	_fps = cpy._fps;
	_interval = cpy._interval;
	_cycleStart = cpy._cycleStart;
	return *this;
}

void GameClock::setFps(const clock_t fps)
{
	_fps = fps;
	_interval = ((float)1 / fps) * 1000;
}

void GameClock::startCycle()
{
	_cycleStart = clock();
}

void GameClock::clockStart()
{
	_clock = clock();
}

int GameClock::getInterval() const
{
	return _interval;
}

int GameClock::getSleepTime() const
{
	int cycletime = (clock() - _cycleStart);
	return (_interval - cycletime);
}

int GameClock::getSeconds() const
{
	return (int)((clock() - _clock) / CLOCKS_PER_SEC) % INT32_MAX;
}
