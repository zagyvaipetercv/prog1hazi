#include "fajlkezelo.h"

size_t aBufferbaToltes(Asztal* asztalok, AsztalBuffer* buffer, size_t bufferMerete) {
	Asztal* mozgo = asztalok;
	size_t betoltottek = 0;
	for (betoltottek; betoltottek < bufferMerete; betoltottek++) {
		buffer[betoltottek].elerheto = mozgo->elerheto;
		buffer[betoltottek].ferohely = mozgo->ferohely;
		buffer[betoltottek].oszlop = mozgo->oszlop;
		buffer[betoltottek].sor = mozgo->sor;

		mozgo = mozgo->kov;
	}

	return betoltottek;
}

void asztalokMentese(Asztal* asztalok) {
	FILE* fp;

	//Megadja hogy mekkorának kell lenni a buffernak
	size_t bufferMeret = asztalokMeret(asztalok);

	//Elmenti a metaadatokat
	fopen_s(&fp, "asztalok_elemszam.dat", "wb");
	if (fp == NULL)
	{
		printf("Nem sikerult letrehozni az asztalok_elemszam.dat adatallomanyt\n");
		return;
	}
	size_t metaadatokKiirva = fwrite(&bufferMeret, sizeof(size_t), 1, fp);
	fclose(fp);
	if (metaadatokKiirva == 0)
	{
		printf("Nem sikerult elmenteni a metaadatokat\n");
		return;
	}

	//Letrehozza buffert
	AsztalBuffer* buffer = (AsztalBuffer*)malloc(bufferMeret * sizeof(AsztalBuffer));

	//Fajl megnyitasa
	fopen_s(&fp, "asztalok.dat", "wb");
	if (fp == NULL)
	{
		printf("Nem sikerult letrehozni az asztalok.dat adatallomanyt\n");
		return;
	}

	//Elemek bufferba toltese
	size_t elemekBetoltve = aBufferbaToltes(asztalok, buffer, bufferMeret);

	for (size_t i = 0; i < bufferMeret; i++)
	{
		printf("sor: %d, oszlop: %d\n", buffer[i].sor, buffer[i].oszlop);
	}

	//Buffer kiirasa allomanyba
	size_t elemekKiirva = fwrite(buffer, sizeof(AsztalBuffer), elemekBetoltve, fp);
	fclose(fp);
	free(buffer);
	if (elemekKiirva < elemekBetoltve)
	{
		printf("Nem sikerult minden elemet kiirni a bufferbol\n");
		return;
	}

}

Asztal* asztalokBetoltese(Asztal* asztalok) {
	FILE* fp;
	Asztal* mozgo = asztalok;

	size_t bufferElemSzam = 0;

	fopen_s(&fp, "asztalok_elemszam.dat", "rb");
	if (fp == NULL)
	{
		printf("Nem sikerult megnyitni az asztalok_elemszam.dat allomanyt\n");
		return asztalok;
	}
	size_t sikeresElemszamOlvasas = fread_s(&bufferElemSzam, sizeof(size_t), sizeof(size_t), 1, fp);
	fclose(fp);
	if (sikeresElemszamOlvasas == 0)
	{
		printf("Nem sikerult olvasni az asztalok_elemszam.dat allomanyt\n");
		return asztalok;
	}

	fopen_s(&fp, "asztalok.dat", "rb");
	if (fp == NULL)
	{
		printf("Nem sikerult megnyitni az asztalok.dat allomanyt\n");
		return asztalok;
	}

	AsztalBuffer* buffer = (AsztalBuffer*)malloc(bufferElemSzam * sizeof(AsztalBuffer));
	size_t olvasottElemek = fread_s(buffer, bufferElemSzam * sizeof(AsztalBuffer), sizeof(AsztalBuffer), bufferElemSzam, fp);
	fclose(fp);
	if (olvasottElemek < bufferElemSzam)
	{
		printf("Nem sikerult minden adatot olvasni\n");
		free(buffer);
		return asztalok;
	}
	for (size_t i = 0; i < bufferElemSzam; i++)
	{
		mozgo = ujAsztalHozzaad(mozgo, buffer[i].ferohely, buffer[i].sor, buffer[i].oszlop, buffer[i].elerheto);
	}
	free(buffer);
	return mozgo;
}