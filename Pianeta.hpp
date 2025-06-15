#pragma once
#include "posizionexy.hpp"
#include <iostream>
#include <cstring>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Pianeta : public posizionexy {
public:

	bool spawnato; //spawnato = è stato mai creato il pianeta?

	bool PianetaDistrutto; //serve per capire se è distrutto o meno


	//le seguenti variabili servono per mantenere le info del pianeta nel caso si esca e si rientra
	bool forte_distrutto;
	bool debole_distrutto;
	int x_benzina;
	int y_benzina;
	int x_GPL;
	int y_GPL;
	int x_forte;
	int x_debole;
	int pavimento[38];


	bool GameOver(bool& gameover, int& vite, int& serbatoio, int& ax, int& ay); //funzione che serve a diminuire le vite o a rendere true la variabile che indica se vi è un gameover o meno

	void PosizioneXBunker(int& bdx, int& bfx, int pavimento[]); //funzione che serve a inizializzare le coordinate dei bunker

	void terreno(int pavimento[]); //funzione che riempie array di 0 o 1, generati casualmente

	void stampaterreno(int pavimento[]); //se pavimento[i] == 0 allora pianura, altrimenti se == 1 stampa una parte di montagna

	void matrice(int& astronave_x, int& astronave_y, bool& raggio_tr, int& benz_x, int& benz_y, int& gpl_x, int& gpl_y,
		int& bunker1_x, int& bunker1_y, int& bunker2_x, int& bunker2_y,
		bool& sparato1, int& proiett1_x, int& proiett1_y, bool& sparato2, int& proiett2_x, int& proiett2_y, bool& sparato3, int& proiett3_x, int& proiett3_y,
		int& ProiettClassico_y, int& ProiettClassico_x, int& ProiettForteClassico_x, int& ProiettForteZigZag_x, int& ProiettDeboleDiagonale_x, int& ProiettForteDiagonale_x);
	//prende come parametri tutte le cordinate degli oggetti di gioco da stampare su schermo

	void UI(int tacche_carburante, int vite, bool psparato1, bool psparato2, bool psparato3, int punteggio); //stampa le info riguardanti le vite, punteggio, carburanti, proiettili astronave 

	void GiocaPianeta(int& punteggio, bool& gameover, bool& spawnato, int& vite, int& serbatoio, bool& PDistrutto); //funzione che verrà richiamata quando si entrerà nel pianeta
};
