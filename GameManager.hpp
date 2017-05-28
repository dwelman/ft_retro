#pragma once

#include "Entity.hpp"
#include "EntityFactory.hpp"
#include "MovingEntity.hpp"
#include "Player.hpp"
#define MAX_X 200
#define MAX_Y 45

#define ENEMY_SCORE 100

#define NEW_LIFE_SCORE 5000

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

private:
	int				score;
	int				scoreAcc;
	int				lives;
	EntityFactory	factory;
	Vector2			movementAxis;

	Entity				*entities[500];
	int					entityCount;
	char 				**starfield;
	int					counter;
	int					starfieldCount;

	void				makeStarfield();
	void				addStarRow() const;
	static int const	startingLives;
	static int const	screenWidth;
	static int const	screenHeight;
};
