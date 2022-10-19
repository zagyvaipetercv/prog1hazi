#include "megjelenito.h"


void vonalKiir(int hossz){
    for (int i = 0; i < hossz; i++)
    {
        printf("-");
    }
    printf("\n");
}

void menukListazas(Menu *menuk, int *menuMeret){
    printf("Menuk:\n");
    vonalKiir(15);
    for (int i = 0; i < *menuMeret; i++)
    {
        printf("%s\n%s\n%d-Ft\n",menuk[i].nev,menuk[i].leiras,menuk[i].ar);
        vonalKiir(10);
    }
}