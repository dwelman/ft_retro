#include "GameManager.hpp"

int const GameManager::startingLives = 3;
int const GameManager::screenWidth = 30;
int const GameManager::screenHeight = 30;

GameManager::GameManager() : score(0), lives(startingLives), entityCount(500)
{
	for (unsigned int i = 0; i < 500; i++)
	{
		entities[i] = nullptr;
	}
	player = nullptr;
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

void GameManager::SetPlayer(int id)
{
	if (id >= 0 && id < 500)
	{
		if (entities[id] != nullptr)
		{
			player = entities[id];
		}
	}
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

	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 30; j++)
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
				map[y][x] = entities[i]->GetMapObject().GetElements()[k].GetMapChar();
			}
		}
	}
}

void GameManager::HandleMovement()
{
	Entity	*temp;
	for (int i = 0; i < entityCount; i++)
	{
		if (entities[i] != nullptr)
		{
			temp = entities[i];
			temp->Move();
		}
	}
}
