#ifndef MEGJELENITO_H
#define MEGJELENITO_H

#include <stdio.h>
#include "menu.h"
#include "asztal.h"

void vonalKiir(int hossz);

void menukListazas(Menu *menuk, int *menuMeret);

void asztalokListazas(Asztalok asztalok);

#endif