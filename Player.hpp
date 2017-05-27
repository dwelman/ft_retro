#pragma once

#include "ShootingEntity.hpp"

class Player : public ShootingEntity
{
public:
    Player(std::string const &_type, MapObject const & mo, Vector2 *_shootPoints, int _nShootPoints);
    Player(Player const &e);

    Player &operator=(Player const &e);

    void    	Update();
	void		MovePlayer(Vector2 const &delta);

	~Player();
private:
    Player();
};
