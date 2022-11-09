#include "debugmalloc.h"
#include "menu.h"
#include "asztal.h"
#include "megjelenito.h"


void asztlaokListazasMain(Asztal* kezdo) {
    for (Asztal *mozgo = kezdo; mozgo != NULL; mozgo = mozgo->kov)
    {
        printf("%p\n", mozgo);
    }
}

int main(int argc, char const *argv[]){
    Asztal *asztalok = NULL;
    Menu* menuk = NULL;

    menuk = ujMenuFelvetele(menuk, "Rizseshus krumplival", "Rizseshus, Sultkrumpli", 1590);
    menuk = ujMenuFelvetele(menuk, "Paprikaskrumpli", "paprika krumplival", 4570);
    menuk = ujMenuFelvetele(menuk, "Krumplis teszta", "Teszta krumplival", 5120);
    menuk = ujMenuFelvetele(menuk, "Babgulyas", "Bab gulyassal", 3120);


    asztalok = ujAsztalHozzaad(asztalok, 1, 1, 1);

    asztalok = asztalTorlese(asztalok, 1, 1);

    asztalokListazas(asztalok);
    //menukListazas(menuk);

    /*
    int felhasznaloInput;
    while(scanf("%d", &felhasznaloInput) != EOF){
        switch (felhasznaloInput)
        {
        case 1://Uj asztal
            
            break;
        case 2://Asztal foglalas
            
            break;
        case 3://Asztal torles
            
            break;            
        case 4://Uj menu hozzaadas
            
            break;
        case 5://Menu torlese
            
            break;
        case 6://Menu modositas
            
            break;
        case 7://Rendeles felvetele
            
            break;
        case 8://Rendeles torlese
            
            break;
        case 9://Szamlazas
            
            break;
        case 0:
            
            break;
        default:
            printf("Ervenytelen beviteli ertek\nKerlek valassz a fenti ertekek kozul (0-9)");
            break;
        }
    }
    */

    asztalokListaFelszabaditas(asztalok);
    menuFelszabaditas(menuk);

    return 0;
}