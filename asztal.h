#ifndef ASZTAL_H
#define ASZTAL_H
#include "debugmalloc.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct Asztal{
    bool elerheto;
    int ferohely;
    int sor;
    int oszlop;
    struct Asztal *kov;
}Asztal;

Asztal *ujAsztalHozzaad(Asztal *asztalok, int ferohely, int sor, int oszlop);

void asztalokListaFelszabaditas(Asztal *asztalok);

Asztal *asztalTorlese(Asztal *asztalok, int sor, int oszlop);

Asztal *asztalKereses(Asztal *asztalok, int sor, int oszlop);

Asztal *asztalFoglalas(Asztal *asztalok, int sor, int oszlop);

Asztal *asztalFelszabaditas(Asztal *asztalok, int sor, int oszlop);

void maxSorokOszlopok(Asztal *asztalok, int *maxSorok, int *maxOszlopok);

#endif