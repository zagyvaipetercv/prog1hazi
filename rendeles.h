#ifndef RENDELES_H
#define RENDELES_H

#include "menu.h"
#include "debugmalloc.h"
#include <stdlib.h>
#include <string.h>


typedef struct Rendeles {
	char renedloNeve[101];
	Menu* megrendeltMenuk;
	struct Rendeles *kov;
}Rendeles;

	Rendeles* ujRendelesHozzad(Rendeles* rendelesek, char* rendelo, Menu* megrendeltMenu);

	void rendelesekFelszabaditasa(Rendeles* rendelesek);

	Rendeles* rendeloKereses(Rendeles* rendelesek, int keresettIndex);

	int rendelesOsszege(Rendeles* rendelo);

#endif