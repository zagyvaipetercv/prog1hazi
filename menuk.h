#ifndef MENUK_H
#define MENUK_H

#include <malloc.h>
#include <string.h>
#include <stdio.h>

//Menuk egy dinamikus tömbben helyezkednek el 
typedef struct Menu{
    char nev[101];
    char leiras[501];
    int ar;
}Menu;

Menu *ujMenuFelvetele(Menu *menuk, int *menuMeret, char nev[101], char leiras[501], int ar);

Menu *menuPontTorlese(Menu *menuk, int *menuMeret, int torlendoIndexe);

void menuFelszabaditas(Menu *menuk, int *menuMeret);

#endif