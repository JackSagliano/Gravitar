#include <iostream>
#include <cstring>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "astronave.hpp"
#include "Bunker1.hpp"
#include "Bunker2.hpp"
#include "carburante.hpp"
#include "Pianeta.hpp"
#include "posizionexy.hpp"
#include "Proiettile.hpp"
#include "ProiettileBunker.hpp"
#include "ProiettileBunker2.hpp"
#include "ProiettileBunker3.hpp"
#include "ProiettileBunker4.hpp"
#include "serbatoio_astronave.hpp"
#include "Sistema_Solare.hpp"
#include "lista_sistemi_solari.hpp"

using namespace std;

int main() {

	bool VAI_SS_SINISTRA; //servir� per capire se si sta cercando di accedere al sistema solare di sinistra...
	VAI_SS_SINISTRA = false;
	bool VAI_SS_DESTRA; //...o al sistema solare di destra
	VAI_SS_DESTRA = false;

	bool GAMEOVER = false; //booleano che permette di concludere la partita
	astronave infinity; //la nostra astronave infinity viene inizializzata...
	infinity.punteggio = 0; //...con il punteggio del giocatore...
	infinity.vite = 3; //...e con le vite disponibili.
	serbatoio_astronave serbatoio; //serbatoio dell'astronave...
	serbatoio.n_movimenti = 100; //viene inizializzato a 100 movimenti
	
	ptr_SistemaSolare EurAsia; //l'head della lista dei sistemi solari

	EurAsia = new listaSistemiSolari;
	EurAsia->SS.GiocaSistemaSolare(infinity.punteggio, GAMEOVER, infinity.vite, serbatoio.n_movimenti, VAI_SS_SINISTRA, VAI_SS_DESTRA); //si inizia il gioco entrando nel primo sistema solare

	ptr_SistemaSolare head; //head lo utilizziamo come iteratore per scorrere la lista
	head = EurAsia;
	head->sinistra = NULL;
	head->destra = NULL;

	while (GAMEOVER == false) { //il ciclo di gioco si interrompe quando GAMEOVER == true, ossia quando si perdono tutte e 3 le vite

		if (VAI_SS_SINISTRA == true) { //se si cerca di accedere al sistema solare di sinistra, il booleano divetner� true (questo accade nella funzione GiocaSistemaSolare contenuta all'interno della classe Sistema_Solare)
			if (head->sinistra == NULL){ //nel caso non esista il sistema solare di sinistra, ne viene inizializzato uno nuovo
			head->sinistra = new listaSistemiSolari;
			head->sinistra->destra = NULL;
			head->sinistra->sinistra = NULL;
			VAI_SS_SINISTRA = false; //diventa falso poich� si entrer� in un nuovo sistema solare e di conseguenza spetter� al giocatore se entrare in un pianeta, oppure accedere al sistema solare di sinistra o di destra
			head->sinistra->SS.GiocaSistemaSolare(infinity.punteggio, GAMEOVER, infinity.vite, serbatoio.n_movimenti, VAI_SS_SINISTRA, VAI_SS_DESTRA);
			head->sinistra->destra = head; //dato che siamo entrati nel sistema solare di sinistra, per ritornare nel vecchio sistema solare ci servir� un secondo puntatore (che appunto � quello di destra), poich� se si va a sinistram, per tornare a destra si dovr� andaree a destra
			head = head->sinistra; 
			
		}
			else { //nel caso si cerchi di accedere ad un sistema solare che � stato gi� creato in precedenza
				VAI_SS_SINISTRA = false;
				head->sinistra->SS.GiocaSistemaSolare(infinity.punteggio, GAMEOVER, infinity.vite, serbatoio.n_movimenti, VAI_SS_SINISTRA, VAI_SS_DESTRA);
				head = head->sinistra;
			}
		}

		else if (VAI_SS_DESTRA == true) { //stessa logica di prima, cambia solo che invece di entrare a sinistra si sta accedendo a destra
			if (head->destra == NULL) {
				head->destra = new listaSistemiSolari;
				head->destra->sinistra = NULL;
				head->destra->destra = NULL;
				VAI_SS_DESTRA = false;
				head->destra->SS.GiocaSistemaSolare(infinity.punteggio, GAMEOVER, infinity.vite, serbatoio.n_movimenti, VAI_SS_SINISTRA, VAI_SS_DESTRA);
				head->destra->sinistra = head;
				head = head->destra;
			}
			else {
				VAI_SS_DESTRA = false;
				head->destra->SS.GiocaSistemaSolare(infinity.punteggio, GAMEOVER, infinity.vite, serbatoio.n_movimenti, VAI_SS_SINISTRA, VAI_SS_DESTRA);
				head = head->destra;
			}
		}
	}
	return 0;
}