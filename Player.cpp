#include "Player.hpp"

Player::Player(std::string const &_type, MapObject const & mo, Vector2 *_shootPoints, int _nShootPoints)
    : ShootingEntity(_type, mo, _shootPoints, _nShootPoints)
{
    shootFreq = 100;
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
    Move();
}

void Player::MovePlayer(Vector2 const &delta)
{
    mapObj.Move(delta);
}

Entity * Player::clone() const
{
	return (new Player(*this));
}

void		Player::Move()
{
    ShootingEntity::Move();
}