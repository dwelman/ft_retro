#include "GameManager.hpp"
#include <unistd.h>
#include <string>

int const GameManager::startingLives = 3;
int const GameManager::screenWidth = MAX_X;
int const GameManager::screenHeight = MAX_Y;

void 	GameManager::addStarRow() const
{
	for (int y = MAX_Y - 1; y > 0; y--)
	{
		for (int x = 0; x < MAX_X; x++)
		{
			starfield[y][x] = starfield[y - 1][x];
		}
	}
	for (int x = 0; x < MAX_X; x++)
	{
		//srand (time(NULL));
		if (rand() % 100 > 95)
		{
			if (x > 0)
			{
				if (starfield[0][x - 1] != '.')
				{
					starfield[0][x] = '.';
				}
			}
			else
			{
				starfield[0][x] = '.';
			}
		}
		else
		{
			starfield[0][x] = ' ';
		}
	}
}

void 	GameManager::makeStarfield()
{
	if (starfield == nullptr)
	{
		starfield = new char*[MAX_Y];
		for (int y = 0; y < MAX_Y; y++)
		{
			starfield[y] = new char[MAX_X];
		}
	}
	for (int y = 0; y < MAX_Y; y++)
	{
		addStarRow();
	}
}

GameManager::GameManager() :  score(0), scoreAcc(0), lives(startingLives), entityCount(500)
{
	for (unsigned int i = 0; i < 500; i++)
	{
		entities[i] = nullptr;
	}
	Entity *temp = factory.createEntity("player", Vector2(screenWidth / 2, screenHeight -5 ));
	PushEntity(*temp);
	delete temp;

	temp = factory.createEntity("enemy", Vector2(screenWidth / 2 + 10, 10 ));
	PushEntity(*temp);
	delete temp;

	temp = factory.createEntity("big_enemy", Vector2(screenWidth / 2, 10 ));
	PushEntity(*temp);
	delete temp;

	temp = factory.createEntity("huge_enemy", Vector2(screenWidth / 2 - 10, 10 ));
	PushEntity(*temp);
	delete temp;
	starfield = nullptr;

	makeStarfield();
	starfieldCount = 5;
	//std::cout << "GameManager " << std::endl;

	/*MapObject mo(1);

	mo.PushElement(MapElement('*', 0, 0));
	std::cout << "elem " << mo.GetElements()[0].GetMapChar() << std::endl;
	MovingEntity *projectile = new MovingEntity("p_projectile", mo);
	projectile->SetMoveDir(Vector2(0, -1));
*/
	//temp = factory.createEntity("p_projectile", Vector2(screenWidth / 2 , screenHeight -5 ));
	//PushEntity(*temp);
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

/*void GameManager::SetPlayer(int id)
{
	if (id >= 0 && id < 500)
	{
		if (entities[id] != nullptr)
		{
			player = entities[id];
		}
	}
}*/

int GameManager::GetScore() const
{
	return (score);
}

int GameManager::GetLives() const
{
	return (lives);
}

void GameManager::IncreaseScore(int inc)
{
	score += inc;
	scoreAcc += inc;
}

int GameManager::GetScreenWidth() const
{
	return (screenWidth);
}

int GameManager::GetScreenHeight() const
{
	return (screenHeight);
}

void GameManager::CheckCollisions()
{
	Entity	*temp;
	for (int i = 0; i < entityCount; i++)
	{
		if (entities[i] != nullptr)
		{
			temp = entities[i];
			if (temp->GetMapObject().CheckOutOfMapBounds(0, 0, screenWidth, screenHeight))
			{
				delete entities[i];
				entities[i] = nullptr;
			}
			for (int k = 0; k < entityCount; k++)
			{
				if (i != k && entities[k] != nullptr)
				{
					if (temp->GetMapObject().FindCollisions(entities[k]->GetMapObject()))
					{
						if (entities[i]->GetType() == "player")
						{
							delete entities[k];
							entities[k] = nullptr;
							lives--;
							if (lives == 0)
							{
								//Call game over
								exit(0);
							}
						}
						else
						{
							if (entities[i]->GetType() == "p_projectile" || entities[k]->GetType() == "p_projectile")
							{
								if (entities[i]->GetType() == "enemy" || entities[k]->GetType() == "enemy")
								{
									score += ENEMY_SCORE;
									scoreAcc += ENEMY_SCORE;
								}
							}
							delete entities[i];
							entities[i] = nullptr;
							delete entities[k];
							entities[k] = nullptr;
						}
						break;
					}
				}
			}
		}
	}
}

int GameManager::PushEntity(Entity const & e)
{
	for (int i = 0; i < entityCount; i++)
	{
		if (entities[i] == nullptr)
		{
			entities[i] = e.clone();
			return (i);
		}
	}
	return (-1);
}

void 	GameManager::FillMap(char **map) const
{
	int	x = 0;
	int	y = 0;

	for (int i = 0; i < MAX_Y; i++)
	{
		for (int j = 0; j < MAX_X; j++)
		{
			if (i == 0 || j == 0 || i == MAX_Y - 1 || j == MAX_X - 1)
			{
				map[i][j] = '/';
			}
			else
			{
				map[i][j] = starfield[i][j];
			}
		}
	}

	for (int i = 0; i < 500; i++)
	{
		if (entities[i] != nullptr)
		{
			for (int k = 0; k < entities[i]->GetMapObject().GetNumberElements(); k++)
			{
				x = entities[i]->GetMapObject().GetElements()[k].GetX();
				y = entities[i]->GetMapObject().GetElements()[k].GetY();
				if (x >= 0 && x < MAX_X && y >= 0 && y < MAX_Y)
				{
					map[y][x] = entities[i]->GetMapObject().GetElements()[k].GetMapChar();

				}
			}
		}
	}
}

void GameManager::Update()
{
	EntityOrder	eo;
	Entity 		*temp;
	static std::string spawns[3] = {"enemy", "big_enemy", "massive_enemy"};

	counter++;
	if (counter > starfieldCount)
	{
		addStarRow();
		counter = 0;
	}
	if (entities[0] != nullptr)
	{
		//entities[0]->MoveDirect(movementAxis);
		//GetPlayer()->Move(movementAxis);
		GetPlayer()->SetMoveDir(movementAxis);
	}
	else
	{
		exit(0);
	}
	for (int i = 0; i < entityCount; i++)
	{
		if (entities[i] != nullptr)
		{
			entities[i]->Update();
			eo = entities[i]->GetEntityOrder();
			if (eo.amount > 0)
			{
				for (int k = 0; k < eo.amount; k++)
				{
					temp = factory.createEntity(eo.type[k], eo.pos[k]);
					PushEntity(*temp);
					delete temp;
				}
			}
		}
	}
	if (scoreAcc > NEW_LIFE_SCORE)
	{
		scoreAcc = 0;
		lives++;
	}
	ResetMovementAxis();
}

void	GameManager::SetMovementAxis(std::string const &axis, int val)
{
	if (axis == "v")
	{
		movementAxis.SetY(movementAxis.GetY() + val);
	}
	else
	{
		movementAxis.SetX(movementAxis.GetX() + val);
	}
}

void 	GameManager::ResetMovementAxis()
{
	movementAxis.SetY(0);
	movementAxis.SetX(0);
}

Entity	*GameManager::GetPlayer()
{
	return entities[0];
}

int		GameManager::GetEntityCount()
{
	return entityCount;
}
