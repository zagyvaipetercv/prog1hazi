#ifndef MEGJELENITO_H
#define MEGJELENITO_H

#include <stdio.h>
#include "menu.h"
#include "asztal.h"
#include "rendeles.h"

void vonalKiir(int hossz);

void menukListazas(Menu *menuk);

void asztalokListazas(Asztal *asztalok);

void megrendelokListazasa(Rendeles* rendelesek);

void szamlaKiirasa(Rendeles* rendelo);

#endif