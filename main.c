#include "menu.h"
#include "asztal.h"
#include "megjelenito.h"


int main(int argc, char const *argv[])
{
    //Menük tömbjének létrhezozása, deklarálása
    int menuMeret = 0;
    Menu *menuk = (Menu*)malloc(menuMeret*sizeof(Menu));
    Asztal *asztalok = NULL;

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


    menuFelszabaditas(menuk, &menuMeret);

    return 0;
}

/*
    Készíts programot, amely egy étteremben az egyes asztalokhoz tartozó megrendeléseket jegyzi meg. Legyen lehetőség:

    Az asztalok megadására: hány fős, hol helyezkedik el az éttermen belül.
    Az étterem menüjének rögzítésére.
    Új asztal nyitására vendégek érkezése esetén.
    Rendelések felvételére a menü alapján.
    Számla „nyomtatására” (képernyőre).
    Foglaltsági térkép megjelenítésére, figyelembe véve az asztalok elhelyezkedését (grafikus vagy egyszerű konzolos felületen).
    Az adatokat mentse a program fájlba is, hiszen azokat nem felejtheti el egy újraindítás miatt!
*/