#include "Entity.hpp"

Entity::Entity()
{
}

Entity::Entity(std::string const & _type, MapObject const & mo)
{
	this->type = _type;
	this->mapObj = mo;
	this->updateFreqCount = 0;
	updateFreq = 0;
}

Entity::Entity(Entity const & e)
{
	*this = e;
}

Entity::~Entity()
{
}

Entity & Entity::operator=(Entity const & e)
{
	updateFreq = e.updateFreq;
	updateFreqCount = 0;
	this->mapObj = e.mapObj;
	this->type = e.type;
	moveDir = e.moveDir;
	return (*this);
}

std::string const &Entity::GetType() const
{
	return (type);
}

MapObject const & Entity::GetMapObject() const
{
	return (mapObj);
}

EntityOrder	Entity::GetEntityOrder()
{
	EntityOrder ret;

	ret.amount = 0;
	return (ret);
}

void Entity::Move()
{
	mapObj.Move(moveDir);
}

void Entity::MoveDirect(Vector2 const &delta)
{
	mapObj.Move(delta);
}

void Entity::Update()
{
	if (updateFreqCount > updateFreq)
	{
		Move();
		updateFreqCount = 0;
	}
	updateFreqCount++;
}

void Entity::Move(Vector2 const &delta)
{
	mapObj.Move(delta);
}

void Entity::SetMoveDir(Vector2 newMoveDir)
{
	moveDir = newMoveDir;
}

void 		Entity::SetUpdateFreq(int freq)
{
	updateFreq = freq;
}

void 		Entity::Shoot()
{
}
