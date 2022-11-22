#include "menu.h"
#include "asztal.h"
#include "megjelenito.h"
#include "fajlkezelo.h"

void menuHivas() {
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
}

 

int main(int argc, char const *argv[]){
    Asztal *asztalok = NULL;
    asztalok = asztalokBetoltese(asztalok);
    
    Menu* menuk = NULL;
    menuk = menukBetoltese(menuk);
    
    Rendeles* rendelesek = NULL;
    rendelesek = rendelesekBetoltese(rendelesek);


    int input = 0;
    menuHivas(input);
    scanf("%d", &input); 
    while(input != 0){
        switch (input)
        {
        case 1: {
            int ferohely, sor, oszlop;
            printf("Hany fo fer el az asztalnal? ");
            scanf_s("%d", &ferohely);
            printf("Hanyadik sorban helyezkedik el az asztal? ");
            scanf_s("%d", &sor);
            printf("Hanyadik oszlopban helyezkedik el az asztal? ");
            scanf_s("%d", &oszlop);
            asztalok = ujAsztalHozzaad(asztalok, ferohely, sor, oszlop, true);

            printf("\n");
            menuHivas(input);
            scanf("%d", &input);
            break;
        }
        case 2://Asztal foglalas
        {
            int sor, oszlop;
            printf("Meliyk sor? \n");
            scanf("%d", &sor);
            printf("Melik oszlop? \n");
            scanf("%d", &oszlop);
            asztalok = asztalFoglalas(asztalok, sor, oszlop);

            printf("\n");
            menuHivas();
            scanf("%d", &input);
            break;
        }
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
        default:
            printf("Ervenytelen beviteli ertek\nKerlek valassz a fenti ertekek kozul (0-9)\n\n");
            menuHivas();
            scanf("%d", &input);
            break;
        }
    }



    rendelesekFelszabaditasa(rendelesek);
    asztalokListaFelszabaditas(asztalok);
    menuFelszabaditas(menuk);

    return 0;
}