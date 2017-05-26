#pragma once

#include "Entity.hpp"

class GameManager
{
public:
	GameManager();
	GameManager(GameManager const &gm);
	~GameManager();

	GameManager	&operator=(GameManager const &gm);

	int		GetScore() const;
	int		GetLives() const;
	int		GetScreenWidth() const;
	int		GetScreenHeight() const;
private:
	int		score;
	int		lives;

	Entity	*entities[500];
	Entity	*player;
	int		entityCount;

	int const	startingLives = 3;
	int const	screenWidth = 500;
	int const	screenHeight	= 500;
};