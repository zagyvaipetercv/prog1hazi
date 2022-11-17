#include "menu.h"
#include "asztal.h"
#include "megjelenito.h"


int main(int argc, char const *argv[]){
    Asztal *asztalok = NULL;
    Menu* menuk = NULL;
    Rendeles* rendelesek = NULL;

    menuk = ujMenuFelvetele(menuk, "Rizseshus krumplival", "Rizseshus, Sultkrumpli", 1590);
    menuk = ujMenuFelvetele(menuk, "Paprikaskrumpli", "paprika krumplival", 4570);
    menuk = ujMenuFelvetele(menuk, "Krumplis teszta", "Teszta krumplival", 5120);
    menuk = ujMenuFelvetele(menuk, "Babgulyas", "Bab gulyassal", 3120);


    menukListazas(menuk);

    rendelesek = ujRendelesHozzad(rendelesek, "Kolczer Karoly", menuPontKereses(menuk, 1));
    rendelesek = ujRendelesHozzad(rendelesek, "Kolczer Karoly", menuPontKereses(menuk, 2));
    rendelesek = ujRendelesHozzad(rendelesek, "Moso Misi", menuPontKereses(menuk, 3));
    rendelesek = ujRendelesHozzad(rendelesek, "Moso Misi", menuPontKereses(menuk, 5));

    megrendelokListazasa(rendelesek);

    szamlaKiirasa(rendeloKereses(rendelesek, 1));
    szamlaKiirasa(rendeloKereses(rendelesek, 2));

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

    rendelesekFelszabaditasa(rendelesek);
    asztalokListaFelszabaditas(asztalok);
    menuFelszabaditas(menuk);

    return 0;
}