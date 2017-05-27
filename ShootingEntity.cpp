#include "ShootingEntity.hpp"

ShootingEntity::ShootingEntity(std::string const &_type, MapObject const & mo, Vector2 *_shootPoints, int _nShootPoints) :
    MovingEntity(_type, mo), nShootPoints(_nShootPoints)
{
    shootPoints = new Vector2[nShootPoints];
    for (int i  = 0; i < nShootPoints; i++)
    {
        shootPoints[i] = _shootPoints[i];
    }
    projectilePos = nullptr;
    nProjectiles = 0;
}

ShootingEntity::ShootingEntity(ShootingEntity const &se)
{
    *this = se;
}

ShootingEntity::~ShootingEntity()
{
    if (shootPoints != nullptr)
    {
        delete [] shootPoints;
    }
    if (projectilePos != nullptr)
    {
        delete [] projectilePos;
    }
    projectile = nullptr;
}

ShootingEntity &ShootingEntity::operator=(ShootingEntity const &se)
{
    MovingEntity::operator=(se);
    if (shootPoints != nullptr)
    {
        delete [] shootPoints;
    }
    nShootPoints = se.nShootPoints;
    shootPoints = new Vector2[nShootPoints];
    for (int i  = 0; i < nShootPoints; i++)
    {
        shootPoints[i] = se.shootPoints[i];
    }
    if (projectilePos != nullptr)
    {
        delete [] projectilePos;
    }
    this->nProjectiles = se.nProjectiles;
    this->projectilePos = new Vector2[this->nProjectiles];
    for (int i  = 0; i < nProjectiles; i++)
    {
        projectilePos[i] = se.projectilePos[i];
    }
    projectile = se.projectile;
    return (*this);
}

void    ShootingEntity::Shoot()
{
    if (projectilePos != nullptr)
    {
        delete [] projectilePos;
    }
    projectilePos = new Vector2[nShootPoints];
    nProjectiles = nShootPoints;
    for (int i = 0; i < nShootPoints; i++)
    {
        projectilePos[i] = shootPoints[i];
    }
}

ShootingEntity::ShootingEntity()
{

}
