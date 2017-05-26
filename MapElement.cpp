#include "MapElement.hpp"

MapElement::MapElement(char c, int _x, int _y) : Vector2(_x, _y), mapChar(c)
{
}

MapElement::MapElement(MapElement const & me)
{
	*this = me;
}

MapElement::~MapElement()
{
}

MapElement & MapElement::operator=(MapElement const & me)
{
	this->x = me.x;
	this->y = me.y;
	this->mapChar = me.mapChar;
	return (*this);
}

bool MapElement::operator==(MapElement const & me)
{
	return (this->x == me.GetX() && this->y == me.GetY());
}

MapElement & MapElement::operator+(Vector2 const & v)
{
	this->x += v.GetX();
	this->y += v.GetY();
	return (*this);
}

MapElement & MapElement::operator-(Vector2 const & v)
{
	this->x -= v.GetX();
	this->y -= v.GetY();
	return (*this);
}

char MapElement::GetMapChar()
{
	return (mapChar);
}

MapElement::MapElement()
{
}

std::ostream & operator<<(std::ostream &os, MapElement const & m)
{
	os << "[" << m.GetX() << "," << m.GetY() << "]";
	return (os);
}
