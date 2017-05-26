#include "GameManager.h"

GameManager::GameManager() : score(0), lives(startingLives)
{
	for (unsigned int i = 0; i < 500; i++)
	{
		entities[i] = nullptr;
	}
}

GameManager::GameManager(GameManager const & gm)
{
	*this = gm;
}

GameManager::~GameManager()
{
}

GameManager & GameManager::operator=(GameManager const & gm)
{
	this->lives = gm.lives;
	this->score = gm.score;
	return (*this);
}

int GameManager::GetScore() const
{
	return (score);
}

int GameManager::GetLives() const
{
	return (lives);
}

int GameManager::GetScreenWidth() const
{
	return (screenWidth);
}

int GameManager::GetScreenHeight() const
{
	return (screenHeight);
}
