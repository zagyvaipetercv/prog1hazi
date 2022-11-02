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

void asztalokListazas(Asztal *asztalok){
    int sorMax, oszlopMax;
    maxSorokOszlopok(asztalok, &sorMax, &oszlopMax);
    for (int sor = 0; sor < sorMax; sor++)
    {
        for (int oszlop = 0; oszlop < oszlopMax; oszlop++)
        {
            for (Asztal *mozgo = asztalok; mozgo != NULL; mozgo = mozgo->kov){
                if (mozgo->sor == sor && mozgo->oszlop == oszlop)
                {
                    if(mozgo->elerheto == true)
                        printf("%d", mozgo->ferohely);
                    else
                        printf("X");
                }
                printf(" ");
            }
        printf("\n");
        }
    }
}
