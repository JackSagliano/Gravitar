#pragma once
#include "carburante.hpp"

class serbatoio_astronave : public carburante {
public:
	int n_movimenti; //serve a indicare il n_movimenti rimasti, poichè il carburante diminuisce ad ogni movimento eseguito

	int carbumeno(int& n_movimenti); //diminuisce il carburante

	int carbupoco(int& n_movimenti); //aumenta di poco il carburante

	int carbutanto(int& n_movimenti); //aumenta di tanto il carburante

};
