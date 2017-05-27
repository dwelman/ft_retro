#pragma once

#include "MovingEntity.hpp"

class ShootingEntity : public Entity
{
public:
    ShootingEntity(std::string const &_type, MapObject const & mo, Vector2 *_shootPoints, int _nShootPoints);
    ShootingEntity(ShootingEntity const &se);
    ~ShootingEntity();

    ShootingEntity &operator=(ShootingEntity const &se);
    virtual void    Shoot();
	EntityOrder		GetEntityOrder();
	Entity			*clone() const;
	void			Move();
	void			Move(Vector2 const &delta);
protected:
    ShootingEntity();
    Vector2 *shootPoints;
    int     nShootPoints;
    Entity  *projectile;
    Vector2 *projectilePos;
    int     nProjectiles;
};
