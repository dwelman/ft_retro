#pragma once

#include <string>
#include "Vector2.hpp"

class Entity
{
public:
	Entity(std::string const &_type, Vector2 const &_pos);
	Entity(Entity const &e);
	~Entity();

	Entity	&operator=(Entity const &e);

	Vector2		&GetPos();
	std::string	const &GetType() const;
	bool		Move(Vector2 const &delta);
protected:
	Entity();
	Vector2		pos;
	std::string	type;
};