#include "menu.h"

// TODO: Rework all (make menu to linked list)

//ujMenuFelvetele:
/*
    Visszatérítési értéke:  egy Menu pointer, ahova tárolni
                            szeretnénk az új tömböt
    Paraméterként kap:      
        -Menu *menuk:       Menu tipúsú tömb, ahol az eddigi Menu változókat tároltuk
        -int *menuMeret:    a fentebb említett tömb eddigi mérete (ptr, mert a
                            fv automatikusan megnöveli eggyel)
        -char nev[101]:     uj menüpont neve
        -int ar:            uj menupont ára

    a fv. futása során létrehoz egy új tömböt, ami tartalmazza a paraméterként megkapott 
    tömb elmeinek másolatát + 1 új elemet, ami az új tömb végére kerül
    a menüméretet növeli eggyel, illetve a kapott tömböt felszabadítja 

    VISSZATÉRÍTETT TÖMBÖT FEL KELL SZABADÍTANI! (menuTorlese(...))
*/
Menu *ujMenuFelvetele(Menu *menuk, int *menuMeret,char nev[101], char leiras[501], int ar){
    (* menuMeret)++;   //regi menumeret + 1 = uj menu meret
    Menu *ujMenuk = (Menu*)malloc((*menuMeret)*sizeof(Menu)); // uj menu létrehozása, ez lesz majd a return érték
    for (int i = 0; i < *menuMeret-1; i++) //régi elemek átmásolása
    {
        ujMenuk[i].ar = menuk[i].ar;
        strcpy_s(ujMenuk[i].nev, 101, menuk[i].nev);
        strcpy_s(ujMenuk[i].leiras, 501, menuk[i].leiras);
    }

    // uj elem inicialilizálása
    ujMenuk[* menuMeret - 1].ar = ar;
    strcpy_s(ujMenuk[*menuMeret-1].nev, 101, nev);
    strcpy_s(ujMenuk[*menuMeret - 1].leiras, 501, leiras);

    free(menuk); //régi lista törlése
    return ujMenuk; //uj lista visszatérítése
}

//menuPontTorlese:
/*
    Visszatérítési érték:   Menu, amiben a törlenő érték nem szerepel
    Paraméterként kap:
        -Menu *menuk:           régi menük tömbje, amiben szerepel még minden érték
        -int *menuMeret:        fentebb említett tömb méretének ptr.-e
        -int torlendoIndexe:    a törlendo elem indexe

    a fv. futása során létrehoz egy új dinamikus tömböt, amely tartalmazza 
    paraméterként kapott tömb törlenő elem előtti és utáni elemek másolatát

    paraméterként kapott tömb felszabadul, menuMeret változó értéke csökken eggyel 

    VISSZATÉRÍTETT TÖMBÖT FEL KELL SZABADÍTANI! (menuTorlese(...))
*/
Menu *menuPontTorlese(Menu *menuk, int *menuMeret, int torlendoIndexe){
    Menu *ujMenuk = (Menu*)malloc((*menuMeret-1)*sizeof(Menu));
    for (int i = 0; i < torlendoIndexe; i++)
    {
        ujMenuk[i].ar = menuk[i].ar;
        strcpy_s(ujMenuk[i].nev, 101, menuk[i].nev);
        strcpy_s(ujMenuk[i].leiras, 501, menuk[i].leiras);
    }
    for (int i = torlendoIndexe+1; i < *menuMeret; i++)
    {
        ujMenuk[i-1].ar = menuk[i].ar;
        strcpy_s(ujMenuk[i-1].nev, 101, menuk[i].nev);
        strcpy_s(ujMenuk[i-1].leiras, 501, menuk[i].leiras);
    }
    
    *menuMeret--;

    free(menuk);
    return ujMenuk;
}

//menuFelszabaditas:
/*
    Visszatérítési érték:   nincs
    Paraméterként kap:
        -Menu* menuk:       felszabadítandő menuk tömbje
        -int  menuMeret:    fentebb amlített tömb mérete
    
    fv. futása során felszabadítja a kapott tömböt és lenullázza menuMeret változó 
    értékét
*/
void menuFelszabaditas(Menu *menuk, int *menuMeret){
    free(menuk);
    *menuMeret = 0;
}