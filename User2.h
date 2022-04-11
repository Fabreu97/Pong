#ifndef INCLUDED_USER2_H

#include "User.h"

#define INCLUDED_USER2_H

/*
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

#endif // INCLUDED_USER2_H

