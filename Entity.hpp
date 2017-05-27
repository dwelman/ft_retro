#pragma once

#include <string>
#include "MapObject.hpp"
#include "Vector2.hpp"


#define ENTITY_ORDER_MAX 3
struct EntityOrder
{
	int 		amount;
	std::string	type[ENTITY_ORDER_MAX];
	Vector2		pos[ENTITY_ORDER_MAX];
};

class Entity
{
public:
	Entity(std::string const &_type, MapObject const & mo);
	Entity(Entity const &e);
	virtual ~Entity();

	Entity	&operator=(Entity const &e);

	std::string	const 	&GetType() const;
	MapObject	const 	&GetMapObject() const;
	Vector2				GetMoveDir() const;
	void				SetMoveDir(Vector2 newMoveDir);
	virtual EntityOrder	GetEntityOrder();
	virtual void 		Move();
	virtual void		Move(Vector2 const &delta);
	virtual void		MoveDirect(Vector2 const &delta);
	virtual	Entity		*clone();
	virtual void 		Update();
protected:
	Entity();
	MapObject	mapObj;
	std::string	type;
	Vector2	moveDir;
};
