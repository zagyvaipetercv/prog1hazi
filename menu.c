#include "menu.h"

Menu *ujMenuFelvetele(Menu *menuk, char nev[101], char leiras[501], int ar){
	Menu* ujMenu = (Menu*)malloc(sizeof(Menu));
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
    Menu* mozgo = menuk;
    for (int i = 1; i < keresettIndex; i++)
    {
        if (mozgo == NULL) {
            return NULL;
        }
        mozgo = mozgo->kov;
    }
    return mozgo;
}

Menu *menuPontTorlese(Menu *menuk, int torlendoIndexe){
    if (torlendoIndexe < 1)
    {
        printf("Megadott elem indexsze tul kicsi (<0)\n");
        return menuk;
    }
    else if (torlendoIndexe == 1)
    {
        Menu* tmp = menuk->kov;
        free(menuk);
        return tmp;
    }
    else
    {
        Menu* torlendo = menuPontKereses(menuk, torlendoIndexe);
        if (torlendo != NULL)
        {
            Menu* torlendoElotti = menuPontKereses(menuk, torlendoIndexe - 1);
            torlendoElotti->kov = torlendo->kov;
            free(torlendo);
        }
        else
            printf("Megadott elem indexsze tul nagy\n");
        return menuk;
    }
}

Menu* menuModositasa(Menu* menuk, int modositandoIndex, char ujNev[101], char ujLeiras[501], int ujAr) {
    Menu* modositando = menuPontKereses(menuk, modositandoIndex);
    if (modositando != NULL)
    {
        strcpy_s(modositando->nev, 101, ujNev);
        strcpy_s(modositando->leiras, 501, ujLeiras);
        modositando->ar = ujAr;
    }
    return menuk;
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