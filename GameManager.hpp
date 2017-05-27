#pragma once

#include "Entity.hpp"
#include "EntityFactory.hpp"
#include "MovingEntity.hpp"
#include "Player.hpp"
#define MAX_X 30
#define MAX_Y 30

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
	void	Update();
	//void    SetPlayer(int id);
	void	SetMovementAxis(std::string const &axis, int val);
private:
	int				score;
	int				lives;
	EntityFactory	factory;
	Vector2			movementAxis;

	Entity	*entities[500];
//	Entity	*player;
	int		entityCount;

	static int const	startingLives;
	static int const	screenWidth;
	static int const	screenHeight;
};
