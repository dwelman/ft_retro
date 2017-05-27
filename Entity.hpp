#pragma once

#include <string>
#include "MapObject.hpp"

class Entity
{
public:
	Entity(std::string const &_type, MapObject const & mo);
	Entity(Entity const &e);
	virtual ~Entity();

	Entity	&operator=(Entity const &e);

	std::string	const &GetType() const;
	MapObject	const &GetMapObject() const;
	virtual void 		Move();
	virtual void		Move(Vector2 const &delta);
	virtual	Entity		*clone();
	virtual void 		Update();
protected:
	Entity();
	MapObject	mapObj;
	std::string	type;
};
