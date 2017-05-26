#include "Vector2.hpp"

Vector2::Vector2() : x(0), y(0)
{
}

Vector2::Vector2(int _x, int _y) : x(_x), y(_y)
{
}

Vector2::Vector2(Vector2 const & v)
{
	*this = v;
}

Vector2::~Vector2()
{
}

Vector2 & Vector2::operator=(Vector2 const & v)
{
	this->x = v.x;
	this->y = v.y;
	return (*this);
}

Vector2 & Vector2::operator+(Vector2 const & v)
{
	this->x += v.x;
	this->y += v.y;
	return (*this);
}

Vector2 & Vector2::operator-(Vector2 const & v)
{
	this->x = x - v.x;
	this->y = y - v.y;
	return (*this);
}

Vector2 & Vector2::operator*(Vector2 const & v)
{
	this->x *= v.x;
	this->y *= v.y;
	return (*this);
}

Vector2 & Vector2::operator/(Vector2 const & v)
{
	this->x = x / v.x;
	this->y = y / v.y;
	return (*this);
}

bool Vector2::operator==(Vector2 const & v) const
{
	return (this->x == v.x && this->y == v.y);
}

bool Vector2::operator!=(Vector2 const & v) const
{
	return (!(this->x == v.x && this->y == v.y));
}

int Vector2::GetX() const
{
	return (x);
}

int Vector2::GetY() const
{
	return (y);
}

std::ostream & operator<<(std::ostream &os, Vector2 const & v)
{
	os << "[" << v.GetX() << "," << v.GetY() << "]";
	return (os);
}
