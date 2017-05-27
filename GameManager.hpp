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
	void 	FillMap(char **map) const;
	int		GetScreenWidth() const;
	int		GetScreenHeight() const;
	void	CheckCollisions();
	int		PushEntity(Entity const &e);
	void	HandleMovement();
	void    SetPlayer(int id);
private:
	int		score;
	int		lives;

	Entity	*entities[500];
	Entity	*player;
	int		entityCount;

	static int const	startingLives;
	static int const	screenWidth;
	static int const	screenHeight;
};
