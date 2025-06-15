#pragma once
#include "posizionexy.hpp"

class Proiettile : public posizionexy { //proiettile classico che pu� sparare la nostra astronave
public:

	bool sparato; //serve per indicare se il proiettile � stato sparato

	bool spara(); //funzione che serve appunto a sparare il proiettile

	int movimentoproiettile(); //funzione che permette il movimento del proiettile

	bool distruggiproiettile(); //funzione che permette la distruzione del proiettile una volta che � arrivato a terra

};
