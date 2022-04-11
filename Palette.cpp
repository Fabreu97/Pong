#include "Palette.h"

Palette::Palette(unsigned int player, unsigned int size):
    Entity(),
    posx(player ? COLUMNS - 1 : 0),
    posy( (ROW - size)/ 2), // REVIEW
    size( size >= ROW ?  ((STANDARD_SIZE_FOR_PALETTE > ROW) ? (ROW - 1) : STANDARD_SIZE_FOR_PALETTE) : size)
{
    unsigned int i;
    for(i = 0; i < size; i++) {
        manager->turnOn(posx, posy + i);
    }
}

Palette::~Palette() {}

const unsigned int Palette::getPositionX() const {return posx;}
const unsigned int Palette::getPositionY() const {return posy;}
const unsigned int Palette::getSize() const {return size;}
void Palette::moveUP() {
    if(posy > 0) {
        manager->turnOff(posx, posy + size - 1);
        manager->turnOn(posx, --posy);
    }
}

void Palette::moveDOWN() {
    if((posy + size) < ROW) {
        manager->turnOff(posx, posy);
        manager->turnOn(posx, posy + size);
        posy++;
    }
}

void Palette::move(unsigned int control) {
    if(control == 1) {
        this->moveUP();
    } else if(control == 2) {
        this->moveDOWN();
    }
}
