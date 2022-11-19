#include "menu.h"
#include "asztal.h"
#include "megjelenito.h"
#include "fajlkezelo.h"

int main(int argc, char const *argv[]){
    Asztal *asztalok = NULL;
    Menu* menuk = NULL;
    Rendeles* rendelesek = NULL;
    FILE* fp;

    /*
    asztalok = ujAsztalHozzaad(asztalok, 4, 1, 1, true);
    asztalok = ujAsztalHozzaad(asztalok, 4, 1, 2, true);
    asztalok = ujAsztalHozzaad(asztalok, 4, 1, 3, true);
    asztalok = ujAsztalHozzaad(asztalok, 4, 2, 1, true);
    asztalok = ujAsztalHozzaad(asztalok, 4, 2, 2, true);
    asztalok = ujAsztalHozzaad(asztalok, 4, 2, 3, true);
    asztalok = ujAsztalHozzaad(asztalok, 4, 3, 1, true);
    asztalokMentese(asztalok, &fp); 
    */

    asztalok = asztalokBetoltese(asztalok);

    asztalokListazas(asztalok);
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