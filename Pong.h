#ifndef INCLUDED_PONG_H

#include "User1.h"
#include "User2.h"
#include "Palette.h"
#include "Ball.h"
#include "Score.h"

#define INCLUDED_PONG_H
#define INITIAL_BALL_MOVEMENT_TIME 0.09f
#define USER_REATION_TIME 0.05f
#define TIME 0.85f // perde 10% de tempo a cada colisao

class Pong : public Entity {
private:
    float elapsed_time_user;
    float elapsed_time_game;
    Palette a;
    Palette b;
    User01 one;
    User02 two;
    Ball ball;
    Score s1;
    Score s2;
    float time;

    unsigned char control1;
    unsigned char control2;

    int dx;
    int dy;

public:
    Pong();
    ~Pong();

    void game();
    void setup();
    void loop();
};


#endif // INCLUDED_PONG_H
