#pragma once
#include "../posizionexy.hpp"

class astronave : public posizionexy { //� la classe astronave che viene guidata dal giocatore, ricordiamo che possiede anche int x ed int y ereditati
public:

	char button; //� il carattere della tastiera (ad esempio w a s d) che viene premuto per eseguire in seguito un determinato comando
	bool raggio_traente; //booleano poich� il raggio � o attivato o diasstivato
	int vite; //numero vite
	int punteggio;


	int movimento(); //funzione che serve a far muovere l'astronave in qualsiasi direzione

	int AumentaPunteggio(int& punteggio); //funzione che aumenta il punteggio

	int PunteggioExtra(int& punteggio); //funzione che da un punteggio extra

	bool active_raggio_traente(); //funzione che attiva o disattiva il raggio attraente

};