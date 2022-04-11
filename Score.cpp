#include "Score.h"

unsigned char Score::matrix[10][5][3] = {
{ {1,1,1}, {1,0,1}, {1,0,1}, {1,0,1}, {1,1,1} },
{ {0,0,1}, {0,0,1}, {0,0,1}, {0,0,1}, {0,0,1} },
{ {1,1,1}, {0,0,1}, {1,1,1}, {1,0,0}, {1,1,1} },
{ {1,1,1}, {0,0,1}, {1,1,1}, {0,0,1}, {1,1,1} },
{ {1,0,1}, {1,0,1}, {1,1,1}, {0,0,1}, {0,0,1} },
{ {1,1,1}, {1,0,0}, {1,1,1}, {0,0,1}, {1,1,1} },
{ {1,0,0}, {1,0,0}, {1,1,1}, {1,0,1}, {1,1,1} },
{ {1,1,1}, {0,0,1}, {0,0,1}, {0,0,1}, {0,0,1} },
{ {1,1,1}, {1,0,1}, {1,1,1}, {1,0,1}, {1,1,1} },
{ {1,1,1}, {1,0,1}, {1,1,1}, {0,0,1}, {0,0,1} }
};

Score::Score(const unsigned int left, const unsigned int valor) :
    Entity(),
    left(left),
    valor(valor)
    {
        unsigned int i,j;
        int d = DISTANCE_CENTER;
        d *= left ? (-1) : 1;
        for(i = 0; i < LINE_NUMBER; i++) {
            for(j = 0; j < COLUMNS_NUMBER; j++) {
                if(matrix[valor][i][j]) {
                    manager->turnOn(COLUMNS/2 + d + j, 1 + i);
                } else {
                    manager->turnOff(COLUMNS/2 + d + j, 1 + i);
                }
            }
        }
    }

Score::~Score() {

}

void Score::Point() {
    unsigned int i,j;

    this->valor = valor == MAXIMUM_RATING ? valor : valor + 1;
    int d = DISTANCE_CENTER;
    d *= left ? (-1) : 1;
    for(i = 0; i < LINE_NUMBER; i++) {
        for(j = 0; j < COLUMNS_NUMBER; j++) {
            if(matrix[valor][i][j]) {
                manager->turnOn(COLUMNS/2 + d + j, 1 + i);
            } else {
                manager->turnOff(COLUMNS/2 + d + j, 1 + i);
            }
        }
    }
}
