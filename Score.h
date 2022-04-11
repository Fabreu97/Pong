#ifndef INCLUDED_SCORE_H

#include "Entity.h"

#define INCLUDED_SCORE_H
#define MAXIMUM_RATING 7
#define DISTANCE_CENTER 4
#define NUMBER 10
#define LINE_NUMBER 5
#define COLUMNS_NUMBER 3
#define ZERO  { {1,1,1}, {1,0,1}, {1,0,1}, {1,0,1}, {1,1,1} }
#define ONE   { {0,0,1}, {0,0,1}, {0,0,1}, {0,0,1}, {0,0,1} }
#define TWO   { {1,1,1}, {0,0,1}, {1,1,1}, {1,0,0}, {1,1,1} }
#define THREE { {1,1,1}, {0,0,1}, {1,1,1}, {0,0,1}, {1,1,1} }
#define FOUR  { {1,0,1}, {1,0,1}, {1,1,1}, {0,0,1}, {0,0,1} }
#define FIVE  { {1,1,1}, {1,0,0}, {1,1,1}, {0,0,1}, {1,1,1} }
#define SIX   { {1,0,0}, {1,0,0}, {1,1,1}, {1,0,1}, {1,1,1} }
#define SEVEN { {1,1,1}, {0,0,1}, {0,0,1}, {0,0,1}, {0,0,1} }
#define EIGHT { {1,1,1}, {1,0,1}, {1,1,1}, {1,0,1}, {1,1,1} }
#define NINE  { {1,1,1}, {1,0,1}, {1,1,1}, {0,0,1}, {0,0,1} }

class Score : public Entity {
private:
    static unsigned char matrix[10][5][3];
    unsigned char left;
    unsigned int valor;
public:
    Score(const unsigned int left = 0, const unsigned int valor = 0);
    ~Score();

    void Point();
};
#endif // INCLUDED_SCORE_H
