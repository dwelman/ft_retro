#pragma once

#include "Vector2.hpp"

class MapElement : public Vector2
{
public:
	MapElement();
	MapElement(char c, int _x, int _y);
	MapElement(MapElement const &me);
	~MapElement();

	MapElement	&operator=(MapElement const &me);
	bool		operator==(MapElement const &me);
	MapElement	&operator+(Vector2 const &v);
	MapElement	&operator-(Vector2 const &v);

	char	GetMapChar();
private:
	char	mapChar;
};

std::ostream	&operator<<(std::ostream &os, MapElement const &m);