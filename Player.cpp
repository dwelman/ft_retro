#include "Player.hpp"

Player::Player(std::string const &_type, MapObject const & mo, Vector2 *_shootPoints, int _nShootPoints)
    : ShootingEntity(_type, mo, _shootPoints, _nShootPoints)
{

}

Player::Player(Player const &e)
{
    *this = e;
}

Player &Player::operator=(Player const &e)
{
    ShootingEntity::operator=(e);
    return (*this);
}

Player::~Player()
{

}

Player::Player()
{

}

void    Player::Update()
{
    
}
