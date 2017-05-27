//
// Created by Dean DU TOIT on 2017/05/27.
//

#include "EntityFactory.hpp"
#include "MovingEntity.hpp"

void 	InitFactory(EntityFactory *factory)
{
	{
		//Make Player
		MapObject mo(6);
		mo.PushElement(MapElement('.', 0, 0));
		mo.PushElement(MapElement('|', 1, 0));
		mo.PushElement(MapElement('.', 2, 0));
		mo.PushElement(MapElement('/', 0, 1));
		mo.PushElement(MapElement('|', 1, 1));
		mo.PushElement(MapElement('\\', 2, 1));
		Entity ship("Player", mo);
		factory->learnEntity(&ship);
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
		mo.PushElement(MapElement('*', 0, 0));
		MovingEntity	*projectile = new MovingEntity("e_projectile", mo);
		projectile->SetMoveDir(Vector2(0, 1));
		factory->learnEntity(projectile);
		delete projectile;
	}
}

EntityFactory::EntityFactory() : _ecount(0)
{
	for (int i = 0; i < MAX_LEARN; i++)
		_entities[i] = nullptr;
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