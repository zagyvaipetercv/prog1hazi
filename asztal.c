#include "asztal.h"

void ujAsztalHozzaad(Asztal **asztalok, int ferohely, int sor, int oszlop){
    //Új asztal létrehozása, értékeinek megadása:
    Asztal *ujASztal = (Asztal*)malloc(sizeof(Asztal));
    ujASztal->elerheto = true;
    ujASztal->ferohely = ferohely;
    ujASztal->sor = sor;
    ujASztal->oszlop = oszlop;
    ujASztal->kov = NULL;

    //Megvizsgálja, hogy a lista első eleme lessz-e az új asztal
    if (*asztalok == NULL)
    {
        //Ha igen, akkor egyből vissza is adja az értéket.
        *asztalok = ujASztal;
        return;
    }
    
    //Ha nem, akkor végighalad a listán az utolsó elemig:
    Asztal *mozgo;
    for (mozgo = *asztalok; mozgo->kov != NULL; mozgo = mozgo->kov)
    {
        //Vizsgálja, hogy létezik-e már olyan asztal, ami a kért helyen van
        if (mozgo->sor == sor && mozgo->oszlop == oszlop)
        {
            //Ha igen, hibaüzentet küld, eldobja a már létrehozott új asztalt és kilép a függvényből
            printf("A megadott helyen mar letezik asztal.");
            free(ujASztal);
            return;
        }
    }

    //Utolsó elemhez hozzáfűzi az új asztalt
    mozgo->kov = ujASztal;
}

void asztalokFelszabaditas(Asztal *asztalok){
    Asztal *mozgo = asztalok;   //itteráló változó, felveszi a kezdő értéket
    Asztal *tmp;    //Ideiglenes pointer, minden itterácóban ez lessz felszabadítva
    //Listán végighalad a végéig:
    while(mozgo != NULL){
        tmp = mozgo;
        mozgo = mozgo->kov;
        free(tmp);
    }
}

void asztalTorlese(Asztal *asztalok, int sor, int oszlop){
    Asztal *mozgo = asztalok;   //itteráló változó, felveszi a kezdő értéket  
    Asztal *mozgoElotti;    //mozgó változót megelőző érték (szükség van rá mert nem két irányú a lista)
    //Végighalad a listán, amíg a keresett asztalt meg nem találta
    while (mozgo->oszlop != oszlop && mozgo->sor == sor)
    {
        //Vizsgálja hogy végighaladt-e listán a végéig:
        if (mozgo == NULL)
        {
            //Ha igen visszajelez a felhasználónak és kilép
            printf("Keresett asztal nem létezik");
            return;
        }
        mozgoElotti = mozgo;
        mozgo = mozgo->kov;
    }
    //Beállítja a törlendő előtti asztal "következő" értékét:
    mozgoElotti->kov = mozgo->kov;
    //Felsazabdítja a törlendő asztalt:
    free(mozgo);
}
