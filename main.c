#include "menuk.h"
#include "megjelenito.h"

int main(int argc, char const *argv[])
{
    int menuMeret = 0;
    Menu *menuk = (Menu*)malloc(menuMeret*sizeof(Menu));

    menuk = ujMenuFelvetele(menuk, &menuMeret,"Gombok","Tradicionalisan gomboc alaku es egyeb gomboc alaku etelek",2000);
    menuk = ujMenuFelvetele(menuk, &menuMeret,"Haromszogek", "Tradicionalis haromszog alaku es egyeb haromszog alaku etelek", 1800);
    menuk = ujMenuFelvetele(menuk, &menuMeret,"Csikok", "Tradicionalisan csik alaku es egyeb csik alaku etelek", 1000);

    menukListazas(menuk, &menuMeret);

    menuk = menuPontTorlese(menuk,&menuMeret,1);

    menukListazas(menuk, &menuMeret);

    menuFelszabaditas(menuk, &menuMeret);
    return 0;
}