#pragma once

#include "MovingEntity.hpp"

class ShootingEntity : public MovingEntity
{
public:
    ShootingEntity(std::string const &_type, MapObject const & mo, Vector2 *_shootPoints, int _nShootPoints);
    ShootingEntity(ShootingEntity const &se);
    ~ShootingEntity();

    ShootingEntity &operator=(ShootingEntity const &se);
    virtual void    Shoot();
	EntityOrder		GetEntityOrder();
protected:
    ShootingEntity();
    Vector2 *shootPoints;
    int     nShootPoints;
    Entity  *projectile;
    Vector2 *projectilePos;
    int     nProjectiles;
};
