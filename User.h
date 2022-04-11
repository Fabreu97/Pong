#ifndef INCLUDED_USER_H

#include "Entity.h"

#define INCLUDED_USER_H

#define INCLUDED_USER02_H
#define NOTHING 0
#define UP 1
#define DOWN 2

/*
 * The "getInformation" method is related to the keyboard input chosen by the user
 * return 0 - nothing
 * return 1 - UP
 * return 2 - DOWN
 */

class User : public Entity {
public:
    User();
    virtual ~User();
    virtual const unsigned char getInformation() = 0;
};

#endif // INCLUDED_USER_H
