//
// Created by Dean DU TOIT on 2017/05/27.
//

#pragma once
#include <string>
#include <iostream>
#include "Entity.hpp"

class IEntityFactory
{
public:
	IEntityFactory();
	virtual 		~IEntityFactory();
	virtual void 	learnEntity(Entity *) = 0;
	virtual 		Entity* createEntity(std::string const & type) = 0;
};