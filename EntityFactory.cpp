//
// Created by Dean DU TOIT on 2017/05/27.
//

#include "EntityFactory.hpp"
#include "MovingEntity.hpp"
#include "Player.hpp"

void 	InitFactory(EntityFactory *factory)
{
	{
		//Make Player
		MapObject mo(6);
		mo.PushElement(MapElement('|', 0, 0));
		mo.PushElement(MapElement('^', 1, 0));
		mo.PushElement(MapElement('|', 2, 0));
		mo.PushElement(MapElement('\\', 0, 1));
		mo.PushElement(MapElement('_', 1, 1));
		mo.PushElement(MapElement('/', 2, 1));
		Vector2	sp[2] =	{Vector2(0, -1),Vector2(2, -1)};
		Entity *player = new Player("player", mo, &sp[0], 2);
		player->SetUpdateFreq(1);
		factory->learnEntity(player);
	}
	//Player Projectile
	{
		MapObject mo(1);
		mo.PushElement(MapElement('*', 0, 0));
		MovingEntity *projectile = new MovingEntity("p_projectile", mo);
		projectile->SetMoveDir(Vector2(0, -1));
		factory->learnEntity(projectile);
		delete projectile;
	}
	{
		MapObject mo(1);
		mo.PushElement(MapElement('o', 0, 0));
		MovingEntity	*projectile = new MovingEntity("e_projectile", mo);
		projectile->SetMoveDir(Vector2(0, 1));
		factory->learnEntity(projectile);
		delete projectile;
	}
    {
		//Make Big
		MapObject mo(6);
		mo.PushElement(MapElement('/', 0, 0));
		mo.PushElement(MapElement('-', 1, 0));
		mo.PushElement(MapElement('\\', 2, 0));
		mo.PushElement(MapElement('|', 0, 1));
		mo.PushElement(MapElement('V', 1, 1));
		mo.PushElement(MapElement('|', 2, 1));
		Vector2	sp[2] =	{Vector2(0, 2),Vector2(2, 2)};
		Entity *player = new Enemy("big_enemy", mo, &sp[0], 2, 50);
		player->SetUpdateFreq(1);
		factory->learnEntity(player);
	}
	{
		//Make Big
		MapObject mo(10);
		mo.PushElement(MapElement('/', 0, 0));
		mo.PushElement(MapElement('-', 1, 0));
		mo.PushElement(MapElement('|', 2, 0));
		mo.PushElement(MapElement('-', 3, 0));
		mo.PushElement(MapElement('\\', 4, 0));
		mo.PushElement(MapElement('|', 0, 1));
		mo.PushElement(MapElement('V', 2, 1));
		mo.PushElement(MapElement('|', 4, 1));
		mo.PushElement(MapElement('^', 0, 2));
		mo.PushElement(MapElement('^', 4, 2));
		Vector2	sp[5] =	{Vector2(0, 3), Vector2(1, 3),Vector2(2, 3), Vector2(3, 3), Vector2(4, 3)};
		Entity *player = new Enemy("huge_enemy", mo, &sp[0], 5, 60);
		player->SetUpdateFreq(1);
		factory->learnEntity(player);
	}
	{
		//Make Enemy
		MapObject mo(3);
		mo.PushElement(MapElement('\\', 0, 0));
		mo.PushElement(MapElement('V', 1, 0));
		mo.PushElement(MapElement('/', 2, 0));
		Vector2	sp[1] =	{Vector2(1, 1)};
		Entity *player = new Enemy("enemy", mo, &sp[0], 1, 40);
		player->SetUpdateFreq(1);
		factory->learnEntity(player);
	}
}

EntityFactory::EntityFactory() : _ecount(0)
{
	for (int i = 0; i < MAX_LEARN; i++)
		_entities[i] = nullptr;
	InitFactory(this);
}

EntityFactory::~EntityFactory()
{
	for (int i = 0; i < _ecount; i++)
	{
		delete _entities[i];
	}
}

EntityFactory::EntityFactory(const EntityFactory & src)
{
	*this = src;
}

EntityFactory	 &EntityFactory::operator=(const EntityFactory &src)
{
	if (_ecount > 0)
	{
		for (int i = 0; i < _ecount; i++)
			delete _entities[i];
	}
	_ecount = 0;
	for (int i = 0; i < src._ecount; i++)
	{
		learnEntity(src._entities[i]->clone());
	}
	return *this;
}

void 	EntityFactory::learnEntity(Entity *src)
{
	if (_ecount < MAX_LEARN)
	{
		_entities[_ecount] = src->clone();
		_ecount++;
	}
}

Entity* EntityFactory::createEntity(std::string const & type)
{
	for (int i = 0; i < MAX_LEARN; i++)
	{
		if (_entities[i]->GetType() == type)
		{
			return (_entities[i]->clone());
		}
	}
	return nullptr;
}

Entity* EntityFactory::createEntity(std::string const & type, Vector2 offset)
{
	for (int i = 0; i < MAX_LEARN; i++)
	{
		if (_entities[i]->GetType() == type)
		{
			Entity	*newEnt = _entities[i]->clone();
			newEnt->Move(offset);
			return (newEnt);
		}
	}
	return nullptr;
}
