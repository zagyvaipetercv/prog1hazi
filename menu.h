#ifndef MENU_H
#define MENU_H

#include "debugmalloc.h"
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

//Menuk egy dinamikus tömbben helyezkednek el 
typedef struct Menu{
    char nev[101];
    char leiras[501];
    int ar;
    struct Menu *kov;
}Menu;

Menu *ujMenuFelvetele(Menu *menuk, char nev[101], char leiras[501], int ar);

Menu* menuPontKereses(Menu* menuk, int keresettIndex);

Menu *menuPontTorlese(Menu *menuk, int torlendoIndexe);

void menuModositasa(Menu* menu, char ujNev[101], char ujLeiras[501], int ujAr);

void menuFelszabaditas(Menu *menuk);

Menu* menuMasolas(Menu* masolando);

size_t menuMerete(Menu* menuk);

#endif