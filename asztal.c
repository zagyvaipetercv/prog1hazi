    #include "asztal.h"

Asztal* ujAsztalHozzaad(Asztal *asztalok, int ferohely, int sor, int oszlop, bool elerheto){

    //Új asztal létrehozása, értékeinek megadása:
    Asztal *ujAsztal = (Asztal*)malloc(sizeof(Asztal));
    if (ujAsztal == NULL)
    {
        printf("Nem sikerult uj asztalt letrehozni\n");
        return asztalok;
    }
    ujAsztal->elerheto = true;
    ujAsztal->ferohely = ferohely;
    ujAsztal->sor = sor;
    ujAsztal->oszlop = oszlop;
    ujAsztal->kov = NULL;

    bool marLetezik = false;

    //Megvizsgálja, hogy a lista első eleme lessz-e az új asztal
    if (asztalok == NULL)
    {
        //Ha igen, akkor egyből vissza is adja az értéket.
        printf("Uj asztal sikeresen letrehozva\n");
        return ujAsztal;
    }

    //Vizsgálja, hogy létezik-e már a létrehozandó új asztal:
    for (Asztal *mozgo = asztalok; mozgo != NULL; mozgo = mozgo->kov)
    {
        if (mozgo->sor == sor && mozgo->oszlop == oszlop)
        {
            //Ha igen, hibaüzentet küld, felszabadítja az asztalt és a "marLetezik" változót igazra állítja:
            printf("Mar letezik ez az asztal\n");
            free(ujAsztal);
            marLetezik = true;
        }
    }

    if (!marLetezik)
    {
        //Ha még nem létező asztalt akarunk létrehozni, akkor a lista elejére tűzzük és visszaadjuk
        ujAsztal->kov = asztalok;
        printf("Uj asztal sikeresen letrehozva\n");
        return ujAsztal;
    }
    else
    {
        //Ha már létezőt, akkor pedig az eredeti listát adjuk vissza
        return asztalok;
    }

}

void asztalokListaFelszabaditas(Asztal *asztalok){
    Asztal *mozgo = asztalok;   //itteráló változó, felveszi a kezdő értéket
    Asztal *tmp;    //Ideiglenes pointer, minden itterácóban ez lessz felszabadítva
    //Listán végighalad a végéig:
    while(mozgo != NULL){
        tmp = mozgo;
        mozgo = mozgo->kov;
        free(tmp);
    }
}

Asztal *asztalKereses(Asztal *asztalok, int sor, int oszlop){
    //Végighalad a teljes listán:
    Asztal* mozgo = asztalok;
    for (mozgo = asztalok; mozgo != NULL; mozgo = mozgo->kov)
    {
        //Ha megtalálja a keresett asztalt, akkor visszaadja:
        if (mozgo->sor == sor && mozgo->oszlop == oszlop)
        {
            return mozgo;
        }
    }
    //Ha nem volt meg a keresett asztal, akkor értesíti a felhasználót és NULL-t ad vissza:
    printf("A keresett asztal nem letezik\n");
    return NULL;     
}

Asztal *asztalTorlese(Asztal *asztalok, int sor, int oszlop){
    Asztal *mozgo = asztalok;   //itteráló változó, felveszi a kezdő értéket  

    Asztal* torlendo = asztalKereses(asztalok, sor, oszlop); //Megkeresi a törlendő elemet
    //Ha ez az elem létezett, akkor...
    if (torlendo != NULL)
    {
        Asztal* torlendoElotti = NULL;  //Felvesz egy törlendő előtti elemet (kezdetben ismeretlen, ezért NULL)
        //Megkeresi a törlendő elem előtti listaelemet:
        for (Asztal* mozgo = asztalok; mozgo != torlendo; mozgo = mozgo->kov)
        {
            if (mozgo->kov == torlendo)
                torlendoElotti = mozgo;
        }

        if (torlendoElotti != NULL) { //Ha tölrendő előtti elem létezik (nem első elemet akarunk törölni)
            torlendoElotti->kov = torlendo->kov; //Törlendő előtti beállítása
            free(torlendo); //törlendő törlése
            printf("Asztal sikeresen torolve\n");
        }
        else
        { //Ha első elemet akarjuk törölni
            Asztal* tmp = asztalok->kov; //Második elemre mutasson egy pointer
            free(asztalok); //Első elemet felszabadítjuk
            printf("Asztal sikeresen torolve\n");
            return tmp; //Visszaadjuk a második elemet
        }
    }

    return asztalok;
}

Asztal *asztalFoglalas(Asztal *asztalok, int sor, int oszlop){
    //Megkeresi a kért asztalt:
    Asztal *keresett = asztalKereses(asztalok, sor, oszlop);
    if (keresett != NULL) //Vizsgálja, hogy az asztal létezett-e (hibaüzenetet már küldött a keresés, ha nem)
    {
        if (keresett->elerheto == false) //Megvizsgálja hogy foglalt asztalt akarunk-e foglalni
            printf("A(z) (%d-sor) (%d-oszlop) asztal mar foglalt\n", keresett->sor, keresett->oszlop); //Ha igen, akkor hibaüzenetet küld
        else { //Ha nem, akkor lefoglalja
            keresett->elerheto = false;
            printf("Asztal sikeresen lefoglalva\n");
        }
    }
    return asztalok;
}

Asztal *asztalFelszabaditas(Asztal *asztalok, int sor, int oszlop){
    //Megkeresi az asztlat:
    Asztal *keresett = asztalKereses(asztalok, sor, oszlop);
    if (keresett != NULL) //Vizsgálja, hogy az asztal létezett-e (hibaüzenetet már küldött a keresés, ha nem)
    {
        keresett->elerheto = true;
    }

    printf("Asztal sikeresen felszabaditva\n");
    return asztalok;
}

void maxSorokOszlopok(Asztal *asztalok, int *maxSorok, int *maxOszlopok){ 
    //sorok és oszlopok maximális száma kezdetben az első asztal értéke: 
    if (asztalok == NULL)
    {
        return;
    }

    int sorMax = asztalok->sor;        
    int oszlopMax = asztalok->oszlop;

    //Végighaladunk a teljes listán és ha találunk nagyobb oszlop vagy sor számot, akkor azt megváltoztatjuk:
    for (Asztal *mozgo = asztalok; mozgo != NULL; mozgo = mozgo->kov)
    {
        if (sorMax < mozgo->sor)
            sorMax = mozgo->sor;
        if (oszlopMax < mozgo->oszlop)
            oszlopMax = mozgo->oszlop;             
    }

    //Visszaadjuk a max. sor és oszlop számokat    
    *maxSorok = sorMax;
    *maxOszlopok = oszlopMax;
}

size_t asztalokMeret(Asztal* asztalok) {
    int meret = 0;
    Asztal* mozgo = asztalok;
    while (mozgo != NULL)
    {
        meret++;
        mozgo = mozgo->kov;
    }
    return meret;
}