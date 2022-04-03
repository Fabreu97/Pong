#ifndef INCLUDED_USER_H

#include "Entity.h"

#define INCLUDED_USER_H

class User : public Entity {
public:
    User();
    virtual ~User();

    virtual const unsigned char getInformation() = 0;
};

#endif // INCLUDED_USER_H
