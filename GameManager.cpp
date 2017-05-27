#include "GameManager.hpp"



int const GameManager::startingLives = 3;
int const GameManager::screenWidth = MAX_X;
int const GameManager::screenHeight = MAX_Y;

GameManager::GameManager() : score(0), lives(startingLives), entityCount(500)
{
	for (unsigned int i = 0; i < 500; i++)
	{
		entities[i] = nullptr;
	}
	Entity *temp = factory.createEntity("player", Vector2(screenWidth / 2, screenHeight -5 ));
	PushEntity(*temp);
	delete temp;

	//std::cout << "GameManager " << std::endl;

	/*MapObject mo(1);

	mo.PushElement(MapElement('*', 0, 0));
	std::cout << "elem " << mo.GetElements()[0].GetMapChar() << std::endl;
	MovingEntity *projectile = new MovingEntity("p_projectile", mo);
	projectile->SetMoveDir(Vector2(0, -1));
*/
	//temp = factory.createEntity("p_projectile", Vector2(screenWidth / 2 , screenHeight -5 ));
	//PushEntity(*temp);
	SetMovementAxis("v", -1);
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
				std::cout << "OFF MAP!" << std::endl;
			}
			for (int k = 0; k < entityCount; k++)
			{
				if (i != k && entities[k] != nullptr)
				{
					if (temp->GetMapObject().FindCollisions(entities[k]->GetMapObject()))
					{
						delete entities[i];
						entities[i] = nullptr;
						delete entities[k];
						entities[k] = nullptr;
						std::cout << "COLLISION!" << std::endl;
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
			entities[i] = new Entity(e);
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
			map[i][j] = ' ';
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
	entities[0]->MoveDirect(movementAxis);
	for (int i = 0; i < entityCount; i++)
	{
		if (entities[i] != nullptr)
		{
			entities[i]->Update();
		}
	}
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