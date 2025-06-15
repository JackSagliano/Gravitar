#pragma once
#include "posizionexy.hpp"
#include "Pianeta.hpp"

class Sistema_Solare {
public:

	bool SSspawnato = false; //indica se � stato creato o meno il sistema solare, se � falso tutti i suoi campi andranno inizializzati

	Pianeta Pianeta1; //ogni sistema solare ha pianeti, che sono uno diverso dall'altro 
	Pianeta Pianeta2; 


	void PosizionexyPianeti(int& p1x, int& p1y, int& p2x, int& p2y); //assegna delle coordinate casuali x e y ai due pianeti

	void matrice(int astronave_x, int astronave_y, int pianeta1_x, int pianeta1_y, int pianeta2_x, int pianeta2_y, bool Pianeta1Distrutto, bool Pianeta2Distrutto); //stampa su schermo il sistema solare con i pianeti e la nostra piccola astronave

	void UI(int punteggio); //stampa le informazioni di gioco (in questo caso il punteggio)

	void SistemaSolareDistrutto(int& punteggio, bool P1Distrutto, bool P2Distrutto); //appena vengono distrutti entrambi i pianeti, con questa funzione si rende true il bool SSDistrutto

	void GiocaSistemaSolare(int& punteggio, bool& gameover, int& vite, int& serbatoio, bool& VAI_SS_SINISTRA, bool& VAI_SS_DESTRA); //ci permette di giocare e di muoverci all'interno del sistema solare


};
