#include "Pong.h"

Pong::Pong():
    Entity(),
    elapsed_time_user(0.00f),
    elapsed_time_game(0.00f),
    a(0),
    b(1),
    one(),
    two(),
    ball(),
    s1(1,0),
    s2(0,0),
    time(1.0f),
    control1(0),
    control2(0),
    dx(-1),
    dy(1)
    {

    }
Pong::~Pong() {}

void Pong::game() {
    elapsed_time_game += manager->getDelta();
    elapsed_time_user += manager->getDelta();
    unsigned char memory1 = one.getInformation();
    unsigned char memory2 = two.getInformation();
    control1 = memory1 ? memory1 : control1;
    control2 = memory2 ? memory2 : control2;
    if(elapsed_time_user > USER_REATION_TIME) {
        a.move(control1);
        b.move(control2);
        elapsed_time_user -= USER_REATION_TIME;
        control1 = 0;
        control2 = 0;
    }
    if(elapsed_time_game > (INITIAL_BALL_MOVEMENT_TIME * time)) {
        /*Vereficar colisao e redimensionar */
        int bposx = ball.getPositionX();
        int bposy = ball.getPositionY();
        int p1posy = a.getPositionY();
        int p2posy = b.getPositionY();
        int size = a.getSize();
        if(!(bposx + dx)) {
            dx *= (-1);
            if( (bposy >= p1posy) && (bposy < (p1posy + size)) ) {
                time *= TIME;
            } else if ( ((bposy + 1) == p1posy) && dy > 0){
                dy *= (-1);
            } else if(bposy == (p1posy + size) && dy < 0) {
                dy *= (-1);
            } else {
                ball.setPosition(COLUMNS/2, ROW/2);
                time = 1.0f;
                s2.Point();
            }
        } else if ((bposx + dx) == (COLUMNS - 1)) {
            dx *= (-1);
            if( (bposy >= p2posy) && (bposy < (p2posy + size)) ) {
                time *= TIME;
            } else if ( ((bposy + 1) == p2posy) && dy > 0){
                dy *= (-1);
            } else if(bposy == (p2posy + size) && dy < 0) {
                dy *= (-1);
            } else {
                ball.setPosition(COLUMNS/2, ROW/2);
                time = 1.0f;
                s1.Point();
            }
        }
        if((bposy + dy) < 0 || (bposy + dy) == ROW) { // colisao vertical
            dy *= (-1);
        }
        ball.move(dx,dy);
        elapsed_time_game = 0.000f;
    }
}
void Pong::setup() {}

void Pong::loop() {
    while(manager->isOpen()) { // Enquanto a janela estiver aberta o loop continua
        //manager->data(); // dados
        //printf("%.4f\n", manager->getDelta()); // printa no cmd o tempo de cada loop
        manager->setDeltaTime(); // ajusta o tempo de cada loop
        manager->checkEvent(); // verefica se a janela foi fechada ou redimensionada e feha ou redimensiona.

        game();

        manager->Clear(); // limpa a tela
        manager->Draw(); // desenha na tela("atualiza")
        manager->display(); // mostra a tela
    }
}
