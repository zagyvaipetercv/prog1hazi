#include "rendeles.h"


Rendeles* ujRendelesHozzad(Rendeles* rendelesek, char* rendelo, Menu* megrendeltMenu) {
	if (megrendeltMenu == NULL) {
		printf("Nem letezik ilyen menu\n");
		return rendelesek;
	}

	//Megkeresi, hogy létezik-e már ilyen rendelő, ha van akkor mozgo felveszi a rendelő listatag ptr-ét, ha nem akkor a NULL értéket
	Rendeles* rendeles = rendelesek;
	while (rendeles != NULL && strcmp(rendeles->renedloNeve, rendelo))
	{
		rendeles = rendeles->kov;
	}
	
	Menu* ujMenu = menuMasolas(megrendeltMenu);
	//Megvizsgálja hogy menut sikeresen masolta-e
	if (ujMenu == NULL)
	{
		//Ha nem...
		printf("Nem sikerult a menut atmasolni.\n"); //Hibauzentet kuld
		return rendelesek; //Visszadobja az eredeti listat
	}

	if (rendeles == NULL) //Ha új a rendelő
	{
		//Uj rendelés létrehozása:
		Rendeles* ujRendelo = (Rendeles*)malloc(sizeof(Rendeles));
		//Ha nem sikerult letrehozni, visszateritjuk a meglevo rendelesek listajat, felszabaditja a lefoglalt ujMenu memoriajat es hibauzenetet kuld
		if (ujRendelo == NULL)
		{
			printf("Nem sikerult uj rendelest letrehozni\n");
			free(ujMenu);	
			return rendelesek;
		}
		strcpy(ujRendelo->renedloNeve, rendelo); //Uj rendelo nevet definiálja
		ujRendelo->megrendeltMenuk = ujMenu; //Megrendelt menut definiálja
	
		ujRendelo->kov = rendelesek; //Beilleszti lista elejere
		printf("Uj rendeles sikeresen felveve\n");
		return ujRendelo; //Visszaadja az uj rendelesek lista kezdo pointerét
	}
	else //Ha már létezett a rendelo
	{
		// az uj rendelt menut  lista elejere teszi, majd visszaadja az eredeti rendelesek listat
		ujMenu->kov = rendeles->megrendeltMenuk; 
		rendeles->megrendeltMenuk = ujMenu;
		printf("Uj rendeles sikeresen felveve\n");
		return rendelesek;
	}
}

void rendelesekFelszabaditasa(Rendeles* rendelesek) {
	//Végighalad az osszes rendelesen
	Rendeles* rendelesMozgo = rendelesek;
	while (rendelesMozgo != NULL)
	{
		menuFelszabaditas(rendelesMozgo->megrendeltMenuk); //Felszabaditja az adott rendeles menuit
		//Felszabaditja a rendelest és halad a következore
		Rendeles* tmp = rendelesMozgo;
		rendelesMozgo = rendelesMozgo->kov;
		free(tmp);
	}
}

Rendeles* rendeloKereses(Rendeles* rendelesek, int keresettIndex) {
	if (keresettIndex < 1)
		return NULL;
	Rendeles* rendeles = rendelesek;
	for (int i = 1; i < keresettIndex; i++)
	{
		if (rendeles == NULL)
		{
			return NULL;
		}
		rendeles = rendeles->kov;
	}
	return rendeles;
}

int rendelesOsszege(Rendeles* rendelo) {
	int sum = 0;
	for (Menu* menu = rendelo->megrendeltMenuk; menu != NULL; menu = menu->kov)
	{
		sum += menu->ar;
	}
	return sum;
}

size_t rendelokSzama(Rendeles* rendelesek) {
	size_t meret = 0;
	for (Rendeles* mozgo = rendelesek; mozgo != NULL; mozgo = mozgo->kov)
	{
		meret++;
	}
	return meret;
}

Rendeles* rendelesTorlese(Rendeles* rendelesek, int* torlendoRendelesIndexe, int torlendoMenuIndexe) {
	//Megkeresi a torlendo elemet:
	Rendeles* torlendoRendeles = rendeloKereses(rendelesek, torlendoRendelesIndexe);
	//Megvizsgalja, hogy letezik-e a torlendo elem:
	if (torlendoRendeles != NULL)
	{
		//Megvizsgalja, hogy a torlendo menu letezik-e:
		if (menuPontKereses(torlendoRendeles->megrendeltMenuk,torlendoMenuIndexe) != NULL)
		{
			//Torli a menut a rendelesek kozul:
			torlendoRendeles->megrendeltMenuk = menuPontTorlese(torlendoRendeles->megrendeltMenuk, torlendoMenuIndexe);
			//Vizsgalja, hogy van-e még menu az adott rendelonel:
			if (torlendoRendeles->megrendeltMenuk == NULL)
			{
				//Ha nincs akkor törli a rendelot is a rendelesek listabol:
				//(Külön kezeli az elso elem torleset a tobbitol)
				//Ha elso elemet torlunk:
				if (torlendoRendelesIndexe == 1)
				{
					//Elmenti a masodik es elso elemet:
					Rendeles* masodik = rendelesek->kov;
					Rendeles* tmp = rendelesek;
					//Elsot felszabadítja:
					free(rendelesek);
					printf("Sikeres torles\n");
					//Masodikat vissaadja értékként:
					return masodik;
				}
				//Ha nem elso elemet torlunk:
				else
				{
					//Megkeresi a torlendo elotti elemet:
					Rendeles* torlendoElotti = rendelesek;
					while (torlendoElotti->kov != torlendoRendeles && torlendoElotti != NULL)
					{
						torlendoElotti = torlendoElotti->kov;
					}
					//Vizsgalja, hogy ez letezik-e (Kéne létezni-e csak egy biztosítas)
					if (torlendoElotti != NULL)
					{
						//Átállítja a torlendo elotti követekző elemre mutató pointerét:
						torlendoElotti->kov = torlendoRendeles->kov;
						//Felszabadítja a törlendőt:
						free(torlendoRendeles);
					}
				}
			}
		}
	}
	else
		//Ha nem letezett a torlendo elem jelzi:
		printf("Nem letezik ilyen rendelo\n");

	//Visszatériti a módósított listát és jelzi hogy sikeres volt:
	printf("Sikeres torles\n");
	return rendelesek;
}