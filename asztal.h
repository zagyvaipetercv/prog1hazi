#ifndef ASZTAL_H
#define ASZTAL_H
#include <stdbool.h>
#include <malloc.h>
#include <stdio.h>

typedef struct Asztal{
    bool elerheto;
    int ferohely;
    int sor;
    int oszlop;
    Asztal *kov;
}Asztal;

void ujAsztalHozzaad(Asztal **asztalok, int ferohely, int sor, int oszlop);

void asztalokFelszabaditas(Asztal *asztalok);

void asztalTorlese(Asztal *asztalok, int sor, int oszlop);

#endif