#pragma once

#include <iostream>

class Vector2
{
public:
	Vector2();
	Vector2(int _x, int _y);
	Vector2(Vector2 const &v);
	~Vector2();

	Vector2	&operator=(Vector2 const &v);
	Vector2	&operator+(Vector2 const &v);
	Vector2	&operator-(Vector2 const &v);
	Vector2	&operator*(Vector2 const &v);
	Vector2	&operator/(Vector2 const &v);
	bool	operator==(Vector2 const &v) const;
	bool	operator!=(Vector2 const &v) const;

	int		GetX() const;
	int		GetY() const;
private:
	int		x;
	int		y;
};

std::ostream	&operator<<(std::ostream &os, Vector2 const &v);