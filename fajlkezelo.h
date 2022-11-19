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
	Menu* megrendeltMenuk;
}RendelesBuffer;

void asztalokMentese(Asztal* asztalok);

Asztal* asztalokBetoltese(Asztal* asztalok);

#endif

