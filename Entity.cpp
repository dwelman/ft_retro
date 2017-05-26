#include "Entity.hpp"

Entity::Entity()
{
}

Entity::Entity(std::string const & _type, Vector2 const & _pos)
{
	this->type = _type;
	this->pos = _pos;
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
	this->pos = e.pos;
	this->type = e.type;
	return (*this);
}

Vector2  &Entity::GetPos()
{
	return (pos);
}

std::string const &Entity::GetType() const
{
	return (type);
}

bool Entity::Move(Vector2 const &delta)
{
	pos = pos + delta;
	return (true);
}
