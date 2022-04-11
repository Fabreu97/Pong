#ifndef INCLUDED_BALL_H

#include "Entity.h"

#define INCLUDED_BALL_H

class Ball : public Entity {
private:
    bool flag;
    int posx;
    int posy;

public:
    Ball();
    ~Ball();

    const unsigned int getPositionX() const;
    const unsigned int getPositionY() const;

    void move(const int dx, const int dy);
    void setPosition(const unsigned int posx, const unsigned int posy);
};


#endif // INCLUDED_BALL_H
