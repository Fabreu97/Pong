#ifndef INCLUDED_ENTITY_H

#include "GraphicsManager.h"

class Entity {
protected:
    static GraphicsManager* manager;

public:
    Entity();
    ~Entity();
};

#define INCLUDED_ENTITY_H
#endif // INCLUDED_ENTITY_H
