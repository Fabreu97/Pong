#ifndef INCLUDED_USER01_H
#define INCLUDED_USER01_H
#include "User.h"

/*
 *
 * The "getInformation" method is related to the keyboard input chosen by the user
 * return 0 - nothing
 * return 1 - UP
 * return 2 - DOWN
 */

class User01 : public User{
public:
    User01();
    ~User01();

    const unsigned char getInformation();
};

#endif // INCLUDED_USER01_H
