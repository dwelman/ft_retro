#include "MovingEntity.hpp"

MovingEntity::MovingEntity(std::string const & _type, MapObject const & mo) : Entity(_type, mo)
{
	moveDir = Vector2(0,0);
	updateFreq = 0;
	updateFreqCount = 0;
}

MovingEntity::MovingEntity(MovingEntity const & m)
{
	*this = m;
}

MovingEntity::~MovingEntity()
{
}

MovingEntity & MovingEntity::operator=(MovingEntity const & m)
{
	Entity::operator=(m);
	moveDir = m.moveDir;
	updateFreq = m.updateFreq;
	updateFreqCount = m.updateFreqCount;
	return (*this);
}

Vector2 MovingEntity::GetMoveDir() const
{
	return (moveDir);
}

void MovingEntity::SetMoveDir(Vector2 newMoveDir)
{
	moveDir = newMoveDir;
}

void MovingEntity::Move()
{
	Entity::Move(moveDir);
}

MovingEntity::MovingEntity()
{
}

void 	MovingEntity::Update()
{
	if (updateFreqCount > updateFreq)
	{
		Move();
		updateFreqCount = 0;
	}
	updateFreqCount++;
}

Entity	*MovingEntity::clone() const
{
	return (new MovingEntity(*this));
}
