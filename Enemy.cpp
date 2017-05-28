#include "Enemy.hpp"

Enemy::Enemy(std::string const &_type, MapObject const & mo, Vector2 *_shootPoints, int _nShootPoints, int _sf)
    : ShootingEntity(_type, mo, _shootPoints, _nShootPoints), shootFrequency(_sf)
{
    shootFrequencyCount = 0;
}

Enemy::Enemy(Enemy const &e)
{
    *this = e;
}

Enemy &Enemy::operator=(Enemy const &e)
{
    ShootingEntity::operator=(e);
    this->shootFrequency = e.shootFrequency;
    this->shootFrequencyCount = e.shootFrequencyCount;
    return (*this);
}

Enemy::~Enemy()
{

}

Enemy::Enemy()
{

}

void    Enemy::SetShootFrequency(int s)
{
    shootFrequency = s;
}

int     Enemy::GetShootFrequency()
{
    return (shootFrequency);
}

void    Enemy::Update()
{
    if (updateFreqCount > updateFreq)
	{
		Move();
		updateFreqCount = 0;
	}
    if (shootFrequencyCount >= shootFrequency)
    {
        //Shoot();
        shootFrequencyCount = 0;
    }
    updateFreqCount++;
    shootFrequencyCount++;
}

Entity * Enemy::clone() const
{
	return (new Enemy(*this));
}
