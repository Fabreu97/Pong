#ifndef INCLUDED_PONG_H

#include "User01.h"
#include "User02.h"

#define INCLUDED_PONG_H

class Pong : public Entity{
private:
    //float time_loop;
public:
    Pong();
    ~Pong();

    void setup();
    void loop();
};

#endif // INCLUDED_PONG_H
