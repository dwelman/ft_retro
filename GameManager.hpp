#pragma once

#include "Entity.hpp"
#include "EntityFactory.hpp"
#include "MovingEntity.hpp"
#include "Player.hpp"
#include <ncurses.h>
#define MAX_X 60
#define MAX_Y 50

#define ENEMY_SCORE 100
#define BIG_ENEMY_SCORE 200
#define HUGE_ENEMY_SCORE 400

#define NEW_LIFE_SCORE 2500

class GameManager
{
public:
	GameManager();
	GameManager(GameManager const &gm);
	~GameManager();

	GameManager	&operator=(GameManager const &gm);

	int		GetScore() const;
	int		GetLives() const;
	void	IncreaseScore(int inc);
	void 	FillMap(char **map) const;
	int		GetScreenWidth() const;
	int		GetScreenHeight() const;
	void	CheckCollisions();
	int		PushEntity(Entity const &e);
	void	Update();
	void	SetMovementAxis(std::string const &axis, int val);
	void 	ResetMovementAxis();
	Entity	*GetPlayer();
	int		GetEntityCount();
	void	SpawnNewEntity(std::string const &type, int x, int y);


private:
	int				score;
	int				scoreAcc;
	int				lives;
	EntityFactory	factory;
	Vector2			movementAxis;

	Entity				*entities[500];
	int					entityCount;
	char 				**starfield;
	int					starFieldCounter;
	int					starfieldCount;

	int					enemyCounter;
	int					enemyCount;

	void				makeStarfield();
	void				addStarRow() const;
	static int const	startingLives;
	static int const	screenWidth;
	static int const	screenHeight;
};
