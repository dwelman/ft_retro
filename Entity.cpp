#include "Entity.hpp"

Entity::Entity()
{
}

Entity::Entity(std::string const & _type, MapObject const & mo)
{
	this->type = _type;
	this->mapObj = mo;
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
	this->mapObj = e.mapObj;
	this->type = e.type;
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

}

void Entity::Update()
{
	
}

void Entity::Move(Vector2 const &delta)
{
	mapObj.Move(delta);
}

Entity		*Entity::clone()
{
	return (new Entity(*this));
}
