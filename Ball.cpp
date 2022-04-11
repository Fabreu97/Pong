#include "Ball.h"

Ball::Ball():
    Entity(),
    flag(0),
    posx((COLUMNS - 1)/2),
    posy((ROW - 1)/2)
{
    manager->turnOn(posx, posy);
}

Ball::~Ball() {}

const unsigned int Ball::getPositionX() const {return posx;}
const unsigned int Ball::getPositionY() const {return posy;}

void Ball::move(const int dx, const int dy) {
    if( (posy + dy) >= 0 && (posy + dy) < ROW ) {
        if( (posx + dx) > 0 && (posx + dx + 1) < COLUMNS) {
            if(!flag) {
                manager->turnOff(posx, posy);
            }
            posx += dx;
            posy += dy;
            if(!manager->isOn(posy, posx)) {
                manager->turnOn(posx, posy);
                flag = 0;
            } else {
                flag = 1;
            }
        }
    }
}

void Ball::setPosition(const unsigned int posx, const unsigned int posy) {
    manager->turnOff(this->posx, this->posy);
    this->posx = posx;
    this->posy = posy;
    manager->turnOn(posx, posy);
}
