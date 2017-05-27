#pragma once

#include "MapElement.hpp"

class MapObject
{
public:
	MapObject();
	MapObject(int nElements);
	MapObject(MapObject const &mo);
	~MapObject();

	MapObject	&operator=(MapObject const &mo);
	int			GetNumberElements() const;
	MapElement	*GetElements() const;
	void		PushElement(MapElement const &elem);
	void		Move(Vector2 const &delta);
	bool		FindCollisions(MapObject const &m) const;
	bool		CheckOutOfMapBounds(int xLowerBound, int yLowerBound, int xUpperBound, int yUpperBound) const;
private:

	int			numberElements;
	MapElement	*elements;
	int 		elemCount;
};

std::ostream	&operator<<(std::ostream &os, MapObject const &m);