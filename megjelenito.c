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
    bool voltAsztal;
    printf("Az alabbi elhelyezkedesben erhetok el asztalok:\n(X - foglalt)\n(szam - ferohely)\n");
    vonalKiir(6 * oszlopMax);
    for (int y = 1; y <= sorMax; y++)
    {
        for (int x = 1; x <= oszlopMax; x++)
        {
        voltAsztal = false;
            for (Asztal *mozgo = asztalok; mozgo != NULL; mozgo = mozgo->kov)
            {
                if (mozgo->sor == y && mozgo->oszlop == x) {
                    voltAsztal = true;
                    if (mozgo->elerheto == true)
                        printf("%3d  ", mozgo->ferohely);
                    else
                        printf("  X  ");
                }
            }       
            printf(!voltAsztal ? "     ":"");
            printf("|");
        }
        printf("\n");
        vonalKiir(6*oszlopMax);
    }
}
