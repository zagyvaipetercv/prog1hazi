#include "fajlkezelo.h"

void asztalokMentese(Asztal* asztalok) {
	FILE* fp;

	//Megadja hogy mekkorának kell lenni a buffernak
	size_t asztalokMerete = asztalokMeret(asztalok);

	//Elmenti a metaadatokat
	fopen_s(&fp, "asztalok_elemszam.dat", "wb");
	if (fp == NULL)
	{
		printf("Nem sikerult letrehozni az asztalok_elemszam.dat adatallomanyt\n");
		return;
	}
	size_t metaadatokKiirva = fwrite(&asztalokMerete, sizeof(size_t), 1, fp);
	fclose(fp);
	if (metaadatokKiirva == 0)
	{
		printf("Nem sikerult elmenteni a metaadatokat\n");
		return;
	}

	//Letrehozza buffert
	AsztalBuffer* buffer = (AsztalBuffer*)malloc(asztalokMerete * sizeof(AsztalBuffer));
	if (buffer == NULL)
	{
		printf("Nem sikerult a buffert letrehozni\n");
		return;
	}

	//Elemek bufferbatoltese:
	Asztal* mozgo = asztalok;
	for (size_t i = 0; i < asztalokMerete; i++) {
		buffer[i].elerheto = mozgo->elerheto;
		buffer[i].ferohely = mozgo->ferohely;
		buffer[i].oszlop = mozgo->oszlop;
		buffer[i].sor = mozgo->sor;

		mozgo = mozgo->kov;
	}

	//Fajl megnyitasa
	fopen_s(&fp, "asztalok.dat", "wb");
	if (fp == NULL)
	{
		printf("Nem sikerult letrehozni az asztalok.dat adatallomanyt\n");
		free(buffer);
		return;
	}

	//Buffer kiirasa allomanyba
	size_t elemekKiirva = fwrite(buffer, sizeof(AsztalBuffer), asztalokMerete, fp);
	fclose(fp);
	free(buffer);
	if (elemekKiirva < asztalokMerete)
	{
		printf("Nem sikerult minden elemet kiirni a bufferbol\n");
		return;
	}
}

Asztal* asztalokBetoltese(Asztal* asztalok) {
	FILE* fp;
	Asztal* mozgo = asztalok;

	size_t bufferElemSzam = 0; //Tárolja, hogy hány elemet kell majd tárolni a memóriában

	//Metaadatot tároló fájl megnyitása:
	fopen_s(&fp, "asztalok_elemszam.dat", "rb");
	if (fp == NULL)
	{
		printf("Nem sikerult megnyitni az asztalok_elemszam.dat allomanyt\n");
		return asztalok;
	}

	//Metaadat olvasása:
	size_t sikeresElemszamOlvasas = fread_s(&bufferElemSzam, sizeof(size_t), sizeof(size_t), 1, fp);
	fclose(fp);
	if (sikeresElemszamOlvasas == 0)
	{
		printf("Nem sikerult olvasni az asztalok_elemszam.dat allomanyt\n");
		return asztalok;
	}

	//Adatok megnyitása:
	fopen_s(&fp, "asztalok.dat", "rb");
	if (fp == NULL)
	{
		printf("Nem sikerult megnyitni az asztalok.dat allomanyt\n");
		return asztalok;
	}

	//Adatokat tároló buffer létrehozása:
	AsztalBuffer* buffer = (AsztalBuffer*)malloc(bufferElemSzam * sizeof(AsztalBuffer));
	if (buffer == NULL)
	{
		fclose(fp);
		printf("Nem sikerult buffert letrehozni\n");
		return asztalok;
	}

	//Adatok olvasása betöltése bufferba
	size_t olvasottElemek = fread_s(buffer, bufferElemSzam * sizeof(AsztalBuffer), sizeof(AsztalBuffer), bufferElemSzam, fp);
	fclose(fp);
	if (olvasottElemek < bufferElemSzam)
	{
		printf("Nem sikerult minden adatot olvasni\n");
		free(buffer);
		return asztalok;
	}

	//Bufferből láncoltlistába átmásolás:
	for (size_t i = 0; i < bufferElemSzam; i++)
	{
		mozgo = ujAsztalHozzaad(mozgo, buffer[i].ferohely, buffer[i].sor, buffer[i].oszlop, buffer[i].elerheto);
	}
	free(buffer);
	return mozgo;
}

void menukMentese(Menu* menuk) {
	Menu* mozgo = menuk;
	FILE* fp;

	//Menu és bufferméretének megadása:
	size_t menuMeret = menuMerete(menuk);
	if (menuMeret == 0) //Ha üres a lista akkor egyből kilép
		return;

	//Metaadat mentes
	fopen_s(&fp, "menuk_meret.dat", "wb");
	if (fp == NULL)
	{
		printf("menuk_meret.dat allomanyt nem sikerult megnyitni\n");
		return;
	}
	size_t elemszamKiirasaSikeres = fwrite(&menuMeret, sizeof(size_t), 1, fp);
	fclose(fp);
	if (elemszamKiirasaSikeres == 0)
	{
		printf("menuk_meret.dat irasa sikertelen\n");
		return;
	}


	fopen_s(&fp, "menuk.dat", "wb");
	if (fp == NULL)
	{
		printf("Nem sikerult menuk.dat allomanyt megnyitni\n");
		return;
	}

	//Buffer létrehozása:
	MenuBuffer* buffer = (MenuBuffer*)malloc(menuMeret * sizeof(MenuBuffer));
	if (buffer == NULL)
	{
		fclose(fp);
		printf("Nem sikerult a buffert letrehozni\n");
		return;
	}
	
	//Buffer feltöltése adatokkal;
	for (size_t i = 0; i < menuMeret; i++)
	{
		buffer[i].ar = mozgo->ar;
		strcpy_s(buffer[i].leiras, 501, mozgo->leiras);
		strcpy_s(buffer[i].nev, 101, mozgo->nev);

		mozgo = mozgo->kov;
	}

	size_t kiirtElemek = fwrite(buffer, sizeof(MenuBuffer), menuMeret, fp);
	fclose(fp);
	free(buffer);
	if (kiirtElemek < menuMeret)
	{
		printf("Nem sikerult minden elemet kiirni\n");
		return;
	}
}

Menu* menukBetoltese(Menu* menuk) {
	FILE* fp;

	//Metaadatok megnyitása
	fopen_s(&fp, "menuk_meret.dat", "rb");
	if (fp == NULL)
	{
		printf("menuk_meret.dat allomanyt nem sikerult megnyitni\n");
		return menuk;
	}

	//Elemszám mentése
	size_t menukMeret;
	size_t sikeresMeretOlvas = fread_s(&menukMeret, sizeof(size_t), sizeof(size_t), 1, fp);
	fclose(fp);
	if (sikeresMeretOlvas == 0)
	{
		printf("Nem sikerult a menuk_meret.dat allomanyt olvasni\n");
		return menuk;
	}

	//Kilép, ha üres:
	if (menukMeret == 0)
		return NULL;

	//Adatok megnyitása:
	fopen_s(&fp, "menuk.dat", "rb");
	if (fp == NULL)
	{
		printf("Nem sikerult menuk.dat allomanyt megnyitni");
		return menuk;
	}
	
	//Buffer létrehozása:
	MenuBuffer* buffer = (MenuBuffer*)malloc(menukMeret * sizeof(MenuBuffer));
	if (buffer == NULL)
	{
		printf("Nem sikerult buffert letrehozni\n");
		fclose(fp);
		return menuk;
	}

	//Adatok olvasasa:
	size_t olvasottElemek = fread_s(buffer, menukMeret * sizeof(MenuBuffer), sizeof(MenuBuffer), menukMeret, fp);
	fclose(fp);
	if (olvasottElemek < menukMeret)
	{
		printf("Nem sikerult minden adatot olvasni\n");
		free(buffer);
		return menuk;
	}

	//buffer átmásolása listába:
	Menu* mozgo = menuk;
	for (size_t i = 0; i < menukMeret; i++)
	{
		mozgo = ujMenuFelvetele(mozgo, buffer[i].nev, buffer[i].leiras, buffer[i].ar);
	}
	free(buffer);

	return mozgo;
}

void rendeleskMentese(Rendeles* rendelesek) {
	FILE* fp;

	size_t rendelesekMeret = rendelokSzama(rendelesek);
	if (rendelesekMeret == 0)
		return;

	fopen_s(&fp, "rendelesek_szama.dat", "wb");
	if (fp == NULL)
	{
		printf("Nem sikerult megynitni a rendelesek_szama.dat allomanyt\n");
		return;
	}

	size_t sikeresMeretIras = fwrite(&rendelesekMeret, sizeof(size_t), 1, fp);
	fclose(fp);
	if (sikeresMeretIras == 0)
	{
		printf("Nem sikerult a rendelesek_szama.dat allomany kiirasa\n");
		return;
	}

	fopen_s(&fp, "rendelesek.dat", "wb");
	if (fp == NULL)
	{
		printf("Nem sikerult megynitni a rendelesek.dat allomanyt\n");
		return;
	}

	RendelesBuffer* rBuffer = (RendelesBuffer*)malloc(rendelesekMeret * sizeof(RendelesBuffer));
	if (rBuffer == NULL)
	{
		printf("Rendeles buffert nem sikerult letrehozni\n");
		fclose(fp);
		return;
	}

	Rendeles* mozgo = rendelesek;
	for (size_t i = 0; i < rendelesekMeret; i++)
	{
		strcpy_s(rBuffer[i].renedloNeve, 101, mozgo->renedloNeve);
		rBuffer[i].megrendeltMenukSzama = menuMerete(mozgo->megrendeltMenuk);
	}

	size_t kiirtrendelokSzama = fwrite(rBuffer, sizeof(RendelesBuffer), rendelesekMeret, fp);
	fclose(fp);
	if (kiirtrendelokSzama < rendelesekMeret)
	{
		free(rBuffer);
		printf("Nem sikerult rendelesek.dat allomanyt kiirni\n");
		return;
	}


	for (size_t i = 0; i < rendelesekMeret; i++)
	{
		//Allomanynev elkeszitese:
		char allomanynev[17] = "rendelo_m";
		char elem[4] = "";
		itoa(i, elem, 10);

		if (i < 10) {
			char tmp[4] = "";
			strcat_s(tmp, 4, "00");
			strcat_s(tmp, 4, elem);
			strcpy_s(elem, 4, tmp);
		}
		else if (i < 100) {
			char tmp[4] = "";
			strcat_s(tmp, 4, "0");
			strcat_s(tmp, 4, elem);
			strcpy_s(elem, 4, tmp);
		}
		else if (i >= 1000) {
			printf("A rendelesek szama megahaladja a maximalis (1000 db) meretet\n");
			free(rBuffer);
			return;
		}
		strcat_s(allomanynev, 17, elem);
		strcat_s(allomanynev, 17, ".dat");


		//Allomany megnyitasa:
		fopen_s(&fp, allomanynev, "wb");
		if (fp == NULL)
		{
			printf("Nem sikerult megynitni a %s allomanyt\n", allomanynev);
			free(rBuffer);
			return;
		}


		//i. rendeleshez tartozo MenuBuffer létrehozása:
		MenuBuffer* mBuffer = (MenuBuffer*)malloc(rBuffer[i].megrendeltMenukSzama * sizeof(MenuBuffer));
		if (mBuffer == NULL)
		{
			fclose(fp);
			free(rBuffer);
			printf("Nem sikerult kiirni a %s allomany tratalmat\n", allomanynev);
			return;
		}

		//MenuBuffer feltoltese i. rendelo rendelesivel:
		Menu* menu = rendeloKereses(rendelesek, i + 1)->megrendeltMenuk;
		for (size_t i = 0; i < rBuffer[i].megrendeltMenukSzama; i++)
		{
			mBuffer[i].ar = menu->ar;
			strcpy_s(mBuffer[i].leiras, 501, menu->leiras);
			strcpy_s(mBuffer[i].nev, 101, menu->nev);
		}

		size_t kiirtMenuk = fwrite(mBuffer, sizeof(MenuBuffer), rBuffer[i].megrendeltMenukSzama, fp);
		fclose(fp);
		free(mBuffer);
		if (kiirtMenuk < rBuffer[i].megrendeltMenukSzama)
		{
			printf("%s allomanyba nem sikerult minden adatot kiirni\n", allomanynev);
			free(rBuffer);
			return;
		}
	}
	free(rBuffer);
}

Rendeles* rendelesekBetoltese(Rendeles* rendelesek) {

}