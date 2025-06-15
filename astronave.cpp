#include "astronave.hpp"

int astronave::movimento() { //nel caso si inserisca come input 'a' o 'd', si fa il return(x) poichè ci si muove lungo l'asse delle x, con 'w' e 's' lungo l'asse delle y
	if ((button == 'w') && (y > 0)) {
		y = y - 1;
		return(y);

	}
	else if ((button == 'a') && (x > 0)) {
		x = x - 1;
		return(x);

	}
	else if ((button == 's') && (y < 18)) {
		y = y + 1;
		return(y);

	}
	else if ((button == 'd') && (x < 36)) {
		x = x + 1;
		return(x);

	}
}

int astronave::AumentaPunteggio(int& punteggio) { //si incrementa il punteggio e poi si esegue il return
	punteggio = punteggio + 100;
	return(punteggio);
}

int astronave::PunteggioExtra(int& punteggio) 
{
	punteggio = punteggio + 500;
	return (punteggio);
}

bool astronave::active_raggio_traente() { //se il raggio attraente è disattivato, si attiva, viceversa se è già attivato, si disattiva
	if ((raggio_traente == true)) {           
		raggio_traente = false;

	}
	else {
		raggio_traente = true;

	}
	return (raggio_traente);
}
