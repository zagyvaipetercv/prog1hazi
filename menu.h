#ifndef MENU_H
#define MENU_H

#include <malloc.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

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

Menu* menuModositasa(Menu* menuk, int modositandoIndex, char ujNev[101], char ujLeiras[501], char* ujAr);

void menuFelszabaditas(Menu *menuk);

#endif