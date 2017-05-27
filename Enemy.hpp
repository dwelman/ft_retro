#pragma once

#include "ShootingEntity.hpp"

class Enemy : public ShootingEntity
{
public:
    Enemy(std::string const &_type, MapObject const & mo, Vector2 *_shootPoints, int _nShootPoints, int _sf);
    Enemy(Enemy const &e);

    Enemy &operator=(Enemy const &e);

    void    SetShootFrequency(int s);
    int     GetShootFrequency();
    void    Update();
	Entity		*clone() const;

    ~Enemy();
private:
    Enemy();

    int shootFrequency;
    int shootFrequencyCount;
};
