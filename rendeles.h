#ifndef RENDELES_H
#define RENDELES_H

#include "menu.h"


typedef struct Rendeles {
	char renedloNeve[101];
	Menu* megrendeltMenuk;
	struct Rendeles *kov;
}Rendeles;

#endif