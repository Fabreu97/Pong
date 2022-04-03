#include "Pong.h"

Pong::Pong():
    Entity()/*,
    time_loop(0.000f)*/
    {

    }
Pong::~Pong() {}

void Pong::setup() {

}

void Pong::loop() {
    float elapsed_time = 0.0f;
    while(manager->isOpen()) { // Enquanto a janela estiver aberta o loop continua
        //manager->data(); // dados
        //printf("%.4f\n", manager->getDelta()); // printa no cmd o tempo de cada loop
        manager->setDeltaTime(); // ajusta o tempo de cada loop
        elapsed_time += manager->getDelta(); // somatorio(elapsed_time) de tempo que é increcentada o tempo de cada loop.
        manager->checkEvent(); // verefica se a janela foi fechada ou redimensionada e feha ou redimensiona.

        /*
         * faz a led na posicao (0,0) piscar.
         */
        if(elapsed_time >= 0.5) { // se o tempo decorrido for superior a 0.5s
            elapsed_time -= 0.5; //"zera o tempo"
            if(manager->isOn(0,0)) { //vereficar se a led está ligada
                manager->turnOff(0,0); // desliga a led(0,0)
            } else { //se não estiver ligada
                manager->turnOn(0,0); // ligo a led(0,0)
            }
        }

        manager->Clear(); // limpa a tela
        manager->Draw(); // desenha na tela("atualiza")
        manager->display(); // mostra a tela
    }
}
