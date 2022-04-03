#ifndef INCLUDED_USER02_H
#define INCLUDED_USER02_H
#include "User.h"

/*
 *
 * The "getInformation" method is related to the keyboard input chosen by the user
 * return 0 - nothing
 * return 1 - UP
 * return 2 - DOWN
 */

class User02 : public User{
public:
    User02();
    ~User02();

    const unsigned char getInformation();
};

#endif // INCLUDED_USER01_H

