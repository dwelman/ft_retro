#include "GameManager.hpp"

GameManager::GameManager() : score(0), lives(startingLives), entityCount(500)
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

void GameManager::PushEntity(Entity const & e)
{
	for (int i = 0; i < entityCount; i++)
	{
		if (entities[i] == nullptr)
		{
			entities[i] = new Entity(e);
			return ;
		}
	}
}

void GameManager::HandleMovement()
{
	//DEAN: Made a MovingEntity class and interface, not sure what the best way to implement it would be
}
