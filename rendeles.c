#include "rendeles.h"

Rendeles* ujRendelesHozzad(Rendeles* rendelesek, char* rendelo, Menu* megrendeltMenu) {
	if (megrendeltMenu == NULL) {
		printf("Nem letezik ilyen menu\n");
		return rendelesek;
	}
	if (rendelesek == NULL)
	{
		printf("Nincsenek meg rendelesk\n");
		return rendelesek;
	}

	//Megkeresi, hogy létezik-e már ilyen rendelő, ha van akkor mozgo felveszi a rendelő listatag ptr-ét, e nem akkor a NULL értéket
	Rendeles* mozgo = rendelesek;
	while (strcmp(mozgo->renedloNeve,rendelo) != 0 && mozgo != NULL)
	{
		mozgo = mozgo->kov;
	}
	
	if (mozgo == NULL) //Ha új a rendelő
	{

	}
	else
	{

	}
}