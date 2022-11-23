#include "menu.h"
#include "asztal.h"
#include "megjelenito.h"
#include "fajlkezelo.h"

int inputbolSzam() {
    char str[10];
    fgets(str, 10, stdin);
    return atoi(str);
}

int menuHivas() {
    printf("\n");
    printf("1. Asztal letrehozasa\n");
    printf("2. Asztal foglalas\n");
    printf("3. Asztal torlese\n");
    printf("4. Uj menu hozzadas\n");
    printf("5. Menu torlese\n");
    printf("6. Menu modositasa\n");
    printf("7. Rendeles fevetele\n");
    printf("8. Rendeles torlese\n");
    printf("9. Szamlazas\n");
    printf("0. Kilepes\n");

    return inputbolSzam();
}

int main(int argc, char const *argv[]){
    Asztal *asztalok = NULL;
    asztalok = asztalokBetoltese(asztalok);
    
    Menu* menuk = NULL;
    menuk = menukBetoltese(menuk);
    
    Rendeles* rendelesek = NULL;
    rendelesek = rendelesekBetoltese(rendelesek);

    int input = menuHivas();
    while(input != 0) {
        switch (input)
        {
        case 1: {
            printf("UJ ASZTAL LETREHOZASA:\n");
            int ferohely, sor, oszlop;
            printf("Hany fo fer el az asztalnal? ");
            ferohely = inputbolSzam();
            printf("Hanyadik sorban helyezkedik el az asztal? ");
            sor = inputbolSzam();
            printf("Hanyadik oszlopban helyezkedik el az asztal? ");
            oszlop = inputbolSzam();
            asztalok = ujAsztalHozzaad(asztalok, ferohely, sor, oszlop, true);
            break;
        }
        case 2://Asztal foglalas
            printf("ASZTAL FOGLALASA:\n");
            asztalokListazas(asztalok);

            if (asztalok != NULL) {
                int sor, oszlop;
                printf("Meliyk sor? ");
                sor = inputbolSzam();
                printf("Melik oszlop? ");
                oszlop = inputbolSzam();
                Asztal* asztal = asztalKereses(asztalok, sor, oszlop);
                if (asztal != NULL) {
                    if (asztal->elerheto)
                        asztalok = asztalFoglalas(asztalok, sor, oszlop);
                    else
                        asztalok = asztalFelszabaditas(asztalok, sor, oszlop);
                }
            }

            break;
        case 3://Asztal torles
            printf("ASZTAL TORLESE:\n");
            asztalokListazas(asztalok);

            if (asztalok != NULL)
            {
                int sor, oszlop;
                printf("Melyik sor? ");
                sor = inputbolSzam();
                printf("Melyik oszlop? ");
                oszlop = inputbolSzam();
                asztalok = asztalTorlese(asztalok, sor, oszlop);
            }

            break;            
        case 4://Uj menu hozzaadas
        {
            printf("UJ MENU LETREHOZASA:\n");

            char nev[101];
            char leiras[501];
            int ar;
            printf("Uj menu neve: ");
            fgets(nev, 101, stdin);
            printf("Leiras: ");
            fgets(leiras, 101, stdin);
            printf("Ar: (Forint): ");
            ar = inputbolSzam();
            menuk = ujMenuFelvetele(menuk, nev, leiras, ar);

            break;
        }

        case 5://Menu torlese
            printf("MENU TORLESE:\n");
            menukListazas(menuk);

            if (menuk != NULL)
            {
                printf("Melyik menu torlendo? (1-%d)\n", (int)menuMerete(menuk));
                printf("0: kilepes a torlesbol\n");
                int index = inputbolSzam();
                menuk = menuPontTorlese(menuk, index);
            }

            break;
        case 6://Menu modositas
            printf("MENU MODOSITASA:\n");
            menukListazas(menuk);
            
            if (menuk != NULL)
            {
                printf("Melyik menu modositando? (1-%d)\n", (int)menuMerete(menuk));
                printf("0: kilepes a modositasbol\n");
                int index = inputbolSzam();
                if (index == 0)
                    printf("Kilepes a modositasbol\n");
                else
                {
                    Menu* menu = menuPontKereses(menuk, index);
                    printf("%s valtoztatasa:\n", menu->nev);
                    printf("Ha valamelyik attributum nem valtozna, azt ures sor begepelesevel lehet jelezni\n");
                    char ujNev[101], ujLeiras[501];
                    printf("Menu uj neve:\n");
                    fgets(ujNev, 101, stdin);
                    printf("Menu uj leirasa:\n");
                    fgets(ujLeiras, 501, stdin);
                    printf("Menu uj ara:\n");
                    int ujAr = inputbolSzam();
                    menuModositasa(menu, ujNev, ujLeiras, ujAr);
                }
            }

            break;
        case 7://Rendeles felvetele
            printf("RENDELES FELVETELE:\n");
            menukListazas(menuk);
            if (menuk != NULL) {
                char rendelo[101];
                printf("Megrendelt menu szama:\n");
                int index = inputbolSzam();
                Menu* menu = menuPontKereses(menuk, index);
                if (menu != NULL)
                {
                    printf("Megrendelo neve:\n");
                    fgets(rendelo, 101, stdin);
                    rendelesek = ujRendelesHozzad(rendelesek, rendelo, menu);
                }
                else
                    printf("Megadott menu nem letezik\n");
            }

            break;
        case 8://Rendeles torlese
            printf("RENDELES TORLESES\n");
            if (rendelesek != NULL)
            {
                megrendelokListazasa(rendelesek);
                printf("Kinek a rendelese torlendo? (1-%d)\n", (int)rendelokSzama(rendelesek));
                printf("0: kilepeshez\n");
                int index = inputbolSzam();
                if (index != 0)
                {
                    Rendeles* rendelo = rendeloKereses(rendelesek, index);
                    printf("%s altal rendlet ", rendelo->renedloNeve);
                    menukListazas(rendelo->megrendeltMenuk);
                    printf("Melyik menu torlendo? (1-%d)\n", (int)menuMerete(rendelo->megrendeltMenuk));
                    printf("0: Kilepes torlesbol\n");
                    int torlendoMenuIndexe = inputbolSzam();
                    if (torlendoMenuIndexe != 0) {
                        rendelesek = rendelesTorlese(rendelesek, index, torlendoMenuIndexe);
                    }
                    else
                        printf("Torlesbol kilepes\n");
                }
                else
                    printf("Torlesbol kilepes\n");
            }
            else
                printf("Nincsenek meg rendelesek\n");

            break;
        case 9://Szamlazas
            if (rendelesek != NULL)
            {
                megrendelokListazasa(rendelesek);
                printf("Kinek a rendelese szamlazando? (1-%d)\n", (int)rendelokSzama(rendelesek));
                printf("0: Kilepes szamlazasbol\n");
                int index = inputbolSzam();
                if (index != 0)
                {
                    Rendeles* rendelo = rendeloKereses(rendelesek, index);
                    if (rendelo != NULL)
                    {
                        szamlaKiirasa(rendelo);
                        printf("Szamlazott rendeles torlendo? (1 = igen, 0 = nem)\n");
                        int valasz = inputbolSzam();
                        while (valasz != 1 && valasz != 0) {
                            printf("Helytelen bevitel\n");
                            printf("Valasz lehet:\n");
                            printf("1: ha rendeles torlendo\n");
                            printf("0: ha rendeles nem torlendo\n");
                            valasz = inputbolSzam();
                        }
                        if (valasz == 1)
                        {
                            for (size_t i = menuMerete(rendelo->megrendeltMenuk); i > 0; i--)
                            {
                                rendelesek = rendelesTorlese(rendelesek, index, i);
                            }
                        }
                    }
                }
            }
            else
                printf("Meg nincsenek rendelesek\n");

            break;
        default:
            printf("Ervenytelen beviteli ertek\n");
            printf("Kerlek valassz az kovetkezo ertekek kozul (0-9)\n");
            break;
        }
        input = menuHivas();
    }

    asztalokMentese(asztalok);
    menukMentese(menuk);
    rendeleskMentese(rendelesek);

    rendelesekFelszabaditasa(rendelesek);
    asztalokListaFelszabaditas(asztalok);
    menuFelszabaditas(menuk);

    return 0;
}