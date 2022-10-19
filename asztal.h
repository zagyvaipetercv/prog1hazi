#ifndef ASZTAL_H
#define ASZTAL_H
#include <stdbool.h>

typedef struct Pont{
    int x,y;
}Pont;

typedef struct Asztal{
    int id;
    Pont hely;
    bool foglalt;
}Asztal;

#endif