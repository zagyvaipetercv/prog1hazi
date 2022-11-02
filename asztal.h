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

void asztalokListaFelszabaditas(Asztal *asztalok);

void asztalTorlese(Asztal *asztalok, int sor, int oszlop);

Asztal *asztalKereses(Asztal *asztalok, int sor, int oszlop);

void asztalFoglalas(Asztal *asztalok, int sor, int oszlop);

void asztalFelszabaditas(Asztal *asztalok, int sor, int oszlop);

void maxSorokOszlopok(Asztal *asztalok, int *maxSorok, int *maxOszlopok){

#endif