#pragma once
#include "ProiettileBunker.hpp"

class ProiettileBunker4 : public ProiettileBunker { //proiettile del bunker che si muove in diagonale a sinistra, ricordiamo che eredita le funzione come quella che permette il movimento lungo l'asse delle y, sia gli int x,y
public:

	int movimentoAsseX(); //funzione che permette il movimento a sinistra
};