#ifndef FAJLKEZELO_H
#define FAJLKEZELO_H

#include <stdlib.h>
#include <stdio.h>
#include "debugmalloc.h"
#include "asztal.h"
#include "menu.h"
#include "rendeles.h"

typedef struct AsztalBuffer {
	bool elerheto;
	int ferohely;
	int sor;
	int oszlop;
}AsztalBuffer;

typedef struct MenuBuffer {
	char nev[101];
	char leiras[501];
	int ar;
}MenuBuffer;

typedef struct RendelesBuffer {
	char renedloNeve[101];
	size_t megrendeltMenukSzama;
}RendelesBuffer;

void asztalokMentese(Asztal* asztalok);

Asztal* asztalokBetoltese(Asztal* asztalok);

void menukMentese(Menu* menuk);

Menu* menukBetoltese(Menu* menuk);

void rendeleskMentese(Rendeles* rendelesek);

Rendeles* rendelesekBetoltese(Rendeles* rendelesek);

#endif

