#include "menuk.h"
#include "megjelenito.h"

int main(int argc, char const *argv[])
{
    int menuMeret = 0;
    Menu *menuk = (Menu*)malloc(menuMeret*sizeof(Menu));



    

    menuFelszabaditas(menuk, &menuMeret);
    return 0;
}