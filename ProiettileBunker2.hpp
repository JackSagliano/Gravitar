#pragma once

#include "ProiettileBunker.hpp"

class ProiettileBunker2 : public ProiettileBunker { //proiettile del bunker che quando viene sparato si muove a zig zag, ricordiamo che eredita le funzione come quella che permette il movimento lungo l'asse delle y, sia gli int x,y
public:

	int movimentoAsseXDestra(); //funzione che permette il movimento a destra

	int movimentoAsseXSinistra(); //funzionefunzione che permette il movimento a sinistra

};