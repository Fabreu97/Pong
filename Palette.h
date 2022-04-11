#ifndef INCLUDED_PALETTE_H

#include "Entity.h"

#define INCLUDED_PALETTE_H
#define STANDARD_SIZE_FOR_PALETTE 4
#define PLAYER01 0
#define PLAYER02 1
/*
 * Player 01 - 0
 * Player 02 - 1
 */

class Palette : public Entity
{
private:
    int posx;
    int posy;
    unsigned int size;

public:
    Palette(unsigned int player, unsigned int size = STANDARD_SIZE_FOR_PALETTE);
    ~Palette();

    const unsigned int getPositionX() const;
    const unsigned int getPositionY() const;
    const unsigned int getSize() const;

    void moveUP();
    void moveDOWN();
    void move(unsigned int control);
};

#endif // INCLUDED_PALETTE_H
