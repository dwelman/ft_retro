//
// Created by Dean DU TOIT on 2017/05/27.
//

#include "IEntityFactory.hpp"
#include "Enemy.hpp"

#define MAX_LEARN 10

class EntityFactory
{
private:
	Entity			*_entities[MAX_LEARN];
	int				_ecount;

public:
	EntityFactory();
	~EntityFactory();
	EntityFactory(const EntityFactory & src);

	EntityFactory	 &operator=(const EntityFactory &src);
	void 	learnEntity(Entity *);
	Entity* createEntity(std::string const & type);
	Entity* createEntity(std::string const & type, Vector2 offset);
};
