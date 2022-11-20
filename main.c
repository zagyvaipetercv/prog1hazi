#include "menu.h"
#include "asztal.h"
#include "megjelenito.h"
#include "fajlkezelo.h"

int main(int argc, char const *argv[]){
    Asztal *asztalok = NULL;
    asztalok = asztalokBetoltese(asztalok);
    
    Menu* menuk = NULL;
    menuk = menukBetoltese(menuk);
    
    Rendeles* rendelesek = NULL;

    rendelesek = ujRendelesHozzad(rendelesek, "Kolczer Karoly", menuPontKereses(menuk, 1));
    rendelesek = ujRendelesHozzad(rendelesek, "Kolczer Karoly", menuPontKereses(menuk, 2));
    rendelesek = ujRendelesHozzad(rendelesek, "Zsak Bela", menuPontKereses(menuk, 3));

    rendeleskMentese(rendelesek);

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