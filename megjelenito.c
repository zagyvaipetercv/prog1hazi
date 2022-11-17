#include "megjelenito.h"


void vonalKiir(int hossz){
    for (int i = 0; i < hossz; i++)
    {
        printf("-");
    }
    printf("\n");
}

void menukListazas(Menu *menuk){
    printf("Menuk:\n");
    vonalKiir(15);
    int index = 1;
    for (Menu* mozgo = menuk; mozgo != NULL; mozgo = mozgo->kov) {
        printf("%d.)\n", index);
        printf("%s\n", mozgo->nev);
        printf("%s\n", mozgo->leiras);
        printf("%.2d.-Ft\n", mozgo->ar);
        vonalKiir(15);
        index++;
    }
}

void asztalokListazas(Asztal *asztalok){
    if (asztalok == NULL)
    {
        printf("Nincs meg assztal\n");
        return;
    }

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

void megrendelokListazasa(Rendeles* rendelesek) {
    int index = 1;
    for (Rendeles* rendeles = rendelesek; rendeles != NULL; rendeles = rendeles->kov)
    {
        printf("%d. %s\n", index, rendeles->renedloNeve);
        index++;
    }
}

void szamlaKiirasa(Rendeles* rendelo) {
    if (rendelo == NULL)
    {
        printf("Nincs ilyen rendelo\n");
    }
    else
    {
        printf("%s\n", rendelo);
        vonalKiir(strlen(rendelo));
        printf("Megrendelt ");
        menukListazas(rendelo->megrendeltMenuk);
        printf("Vegosszeg: %d.-Ft\n", rendelesOsszege(rendelo));
    }
}