#include "menu.h"

Menu *ujMenuFelvetele(Menu *menuk, char nev[101], char leiras[501], int ar){
	Menu* ujMenu = (Menu*)malloc(sizeof(Menu));
    if (ujMenu == NULL)
    {
        printf("Nem sikerult uj menut letrehozni\n");
        return menuk;
    }
	strcpy_s(ujMenu->nev, 101, nev);
	strcpy_s(ujMenu->leiras, 501, leiras);
	ujMenu->ar = ar;
	ujMenu->kov = NULL;

    bool marLetezik = false;

    //Megvizsgálja, hogy a lista első eleme lessz-e az új menu
    if (menuk == NULL)
    {
        //Ha igen, akkor egyből vissza is adja az értéket.
        return ujMenu;
    }

    //Vizsgálja, hogy létezik-e már a létrehozandó új menu:
    for (Menu* mozgo = menuk; mozgo != NULL; mozgo = mozgo->kov)
    {
        if (strcmp(mozgo->nev,nev) == 0)
        {
            //Ha igen, hibaüzentet küld, felszabadítja a menut és a "marLetezik" változót igazra állítja:
            printf("Mar letezik ilyen menu\n");
            free(ujMenu);
            marLetezik = true;
        }
    }

    if (!marLetezik)
    {
        //Ha még nem létező menut akarunk létrehozni, akkor a lista elejére tűzzük és visszaadjuk
        ujMenu->kov = menuk;
        return ujMenu;
    }
    else
    {
        //Ha már létezőt, akkor pedig az eredeti listát adjuk vissza
        return menuk;
    }
}

Menu* menuPontKereses(Menu* menuk, int keresettIndex) {
    if (keresettIndex < 1) {
        return NULL;
    }
    Menu* mozgo = menuk;
    for (int i = 1; i < keresettIndex; i++) //Végighalad a mneüpontokon, a keresett indexig
    {
        if (mozgo == NULL) { //Ha az index nagyobb lett volna, mint ahány tagja van a listának, visszadob egy NULL-t
            return NULL;
        }
        mozgo = mozgo->kov; //nozgó változtatása
    }
    return mozgo; //Amikor ljutottunk az indexedik elemhez visszadobjuk a ptr-ét
}

Menu *menuPontTorlese(Menu *menuk, int torlendoIndexe){
    if (torlendoIndexe < 1) //Ellenőrzi, hogy létező elemet töröljön
    {
        //Ha nem létezik, hibaüzenetet küld és visszadobja a menuk listáját
        printf("Megadott elem indexsze tul kicsi (indexnek nagyobb vagy egyenlőnek kell lennie 1-gyel.)\n");
        return menuk;
    }
    else if (torlendoIndexe == 1)
    {
        //Ha ez első elemet akarjuk törölni, akkor...
        Menu* tmp = menuk->kov; //Létrehoz egy ptr-t a második elemmel
        free(menuk); //első elemet felszabadítja
        return tmp;  //Visszaadja a második elemet
    }
    else
    {
        Menu* torlendo = menuPontKereses(menuk, torlendoIndexe); //megkeresi a törlendő elemet
        if (torlendo != NULL) //Vizsgálja, hogy tagja-e a listának
        {
            Menu* torlendoElotti = menuPontKereses(menuk, torlendoIndexe - 1); //Ha nem megkeresi a tölrendő elötti tagot
            torlendoElotti->kov = torlendo->kov; //torlendo elötti elem következő elemének beállítása
            free(torlendo); //törlendő törlése
        }
        else
            printf("Megadott elem indexsze tul nagy\n"); //Ha nem hibaüzenetet dob
        return menuk; //Visszadja az új menü törölt elemes menük listáját
    }
}

Menu* menuModositasa(Menu* menuk, int modositandoIndex, char ujNev[101], char ujLeiras[501], char ujAr) {
    if (modositandoIndex < 1) //Vizsgálja a megadott indexet, hogy elég nagy-e
        //Ha nem hibaüzenetet küld
        printf("A megadott elem indexe túl kicsi (indexnek nagyobb vagy egyenlőnek kell lennie 1-gyel.)");
    else
    {
        Menu* modositando = menuPontKereses(menuk, modositandoIndex); //megkeresi a módosítandó menüpontot
        if (modositando != NULL) //Vizsgálja, hogy létezik-e
        {
            //Ha igen, akkor..
            if (ujNev != "")
                strcpy_s(modositando->nev, 101, ujNev); //Átmásolja az új nevet;
            if (ujLeiras != "")
                strcpy_s(modositando->leiras, 501, ujLeiras); //Átmásolja az új leírást
            if (ujAr != "")
                modositando->ar = atoi(ujAr); //Beállítja az új árat
        }
        else
            printf("A módosítandó elem nem található\n");
    }
    return menuk; //Visszaadja a módósított menük listáját
}

void menuFelszabaditas(Menu *menuk){
    Menu* tmp;
    Menu* mozgo = menuk;
    while (mozgo != NULL)
    {
        tmp = mozgo;
        mozgo = mozgo->kov;
        free(tmp);
    }
}

Menu* menuMasolas(Menu* masolando) {
    Menu* ujMenu = (Menu*)malloc(sizeof(Menu));
    if (ujMenu == NULL)
        return NULL;
    ujMenu->kov = NULL;
    strcpy(ujMenu->leiras, masolando->leiras);
    strcpy(ujMenu->nev, masolando->nev);
    ujMenu->ar = masolando->ar;
    return ujMenu;
}

size_t menuMerete(Menu* menuk) {
    size_t meret = 0;
    for (Menu* mozgo = menuk; mozgo != NULL; mozgo = mozgo->kov)
        meret++;
    return meret;
}