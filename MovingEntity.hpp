#pragma once

#include "Entity.hpp"

class MovingEntity : public Entity
{
public:
	MovingEntity(std::string const &_type, MapObject const & mo);
	MovingEntity(MovingEntity const &m);
	~MovingEntity();

	MovingEntity	&operator=(MovingEntity const &m);
	Vector2			GetMoveDir() const;
	void			SetMoveDir(Vector2 newMoveDir);
	void			Move();
	void 			Update();
protected:
	MovingEntity();


};
