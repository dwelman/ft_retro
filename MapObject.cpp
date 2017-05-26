#include "MapObject.hpp"

MapObject::MapObject()
{
	elements = nullptr;
}

MapObject::MapObject(int nElements) : numberElements(nElements)
{
	elements = new MapElement[numberElements];
}

MapObject::MapObject(MapObject const & mo)
{
	*this = mo;
}

MapObject::~MapObject()
{
	delete[] elements;
}

MapObject & MapObject::operator=(MapObject const & mo)
{
	if (elements != nullptr)
	{
		delete [] elements;
	}
	this->numberElements = mo.numberElements;
	elements = new MapElement[numberElements];
	for (int i = 0; i < numberElements; i++)
	{
		elements[i] = mo.elements[i];
	}
	return (*this);
}

int MapObject::GetNumberElements() const
{
	return (numberElements);
}

MapElement * MapObject::GetElements() const
{
	return (elements);
}

void MapObject::PushElement(MapElement const & elem)
{
	static int elemCount = 0;
	if (elemCount < numberElements)
	{
		elements[elemCount] = elem;
		elemCount++;
	}
}

void MapObject::Move(Vector2 const & delta)
{
	for (int i = 0; i < numberElements; i++)
	{
		elements[i] = elements[i] + delta;
	}
}

bool MapObject::FindCollisions(MapObject const & m) const
{
	for (int i = 0; i < numberElements; i++)
	{
		for (int k = 0; k < m.GetNumberElements(); i++)
		{
			if (elements[i] == m.GetElements()[k])
			{
				return (true);
			}
		}
	}
	return (false);
}


std::ostream & operator<<(std::ostream & os, MapObject const & m)
{
	for (int i = 0; i < m.GetNumberElements(); i++)
	{
		os << m.GetElements()[i] << " ";
	}
	os << std::endl;
	return (os);
}
