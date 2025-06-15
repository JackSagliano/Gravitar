#pragma once
#include "Sistema_Solare.hpp"

struct listaSistemiSolari { //abbiamo creato un file apposito per la lista sistemi solari in modo che possa essere disponibile ovunque scrivendo solo #include "lista_sistemi_solari"
	Sistema_Solare SS; //classe sistema solare
	listaSistemiSolari *sinistra; //puntatore alla struttura di sinistra
	listaSistemiSolari *destra; //puntatore alla struttra di destra
};
typedef listaSistemiSolari* ptr_SistemaSolare; //definisco il tipo