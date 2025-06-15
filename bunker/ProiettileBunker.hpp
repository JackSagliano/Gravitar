#pragma once
#include "../Proiettile.hpp"

class ProiettileBunker : public Proiettile { //proiettile del bunker classico, dato che � figlio di proiettile che � figlio di posizionexy, eredita le funzione di movimento (come quella che permette il movimento lungo l'asse delle y) sia gli int x,y
public:

	int movimentoproiettile(); //funzione che permette il movimento del proiettile
};