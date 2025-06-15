#include "Sistema_Solare.hpp"
#include <iostream> 
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "astronave/astronave.hpp"
#include "bunker/Bunker1.hpp"
#include "bunker/Bunker2.hpp"
#include "astronave/carburante.hpp"
#include "Pianeta.hpp"
#include "posizionexy.hpp"
#include "Proiettile.hpp"
#include "bunker/ProiettileBunker.hpp"
#include "bunker/ProiettileBunker2.hpp"
#include "bunker/ProiettileBunker3.hpp"
#include "bunker/ProiettileBunker4.hpp"
#include "astronave/serbatoio_astronave.hpp"
#include "Sistema_Solare.hpp"
#include "lista_sistemi_solari.hpp"

using namespace std;

void Sistema_Solare::PosizionexyPianeti(int& p1x, int& p1y, int& p2x, int& p2y)
{
	srand(time(NULL)); //assegna un valore randomico alle x e y dei 2 pianeti
	p1x = rand() % 34 + 2;
	p1y = rand() % 15 + 2;

	p2x = rand() % 34 + 2;
	p2y = rand() % 15 + 2;

	//if ((p1x == p2x) && (p2x > 2)) { //serve a prevenire che i due pianeti si sovrappongano
		//p2x = p2x - 1;
	//}
	//else if ((p1x == p2x) && (p2y > 2)) {
		//p2y == p2y - 1;
	//}
}

void Sistema_Solare::matrice(int astronave_x, int astronave_y, int pianeta1_x, int pianeta1_y, int pianeta2_x, int pianeta2_y, bool Pianeta1Distrutto, bool Pianeta2Distrutto)
{
	cout << "Non-Gravitar by Nur & Jack" << endl;


	int b, h, i;
	b = 0; //indice che servir� per stampare la base
	h = 0; //indice che servir� per stampare l'altezza
	i = 0; //indice che servir� per stampare gli spazi vuoti


	while (b < 40) { //stampa la barriera superiore del gioco
		cout << "-";
		b = b + 1;

	}

	while (h < 19) {
		cout << endl << "|"; //stampa la barriera sinistra
		while (i < 38) {

			cout << ' '; //riempie di spazi vuoti il campo di gioco fino ad arrivare alla barriera destra

			i = i + 1;
			if ((h == astronave_y) && (i == astronave_x)) {
				cout << 'V'; //nel caso le coordinate siano uguali all'astronave, invece di uno spazio vuoto stampa l'astronave
				i = i + 1;

			}
			if ((h == pianeta1_y) && (i == pianeta1_x) && (Pianeta1Distrutto == false)) { //nel caso le coordinate siano uguali al pianeta 1 e 2, invece di uno spazio vuoto stampa il pianeta (sempre se non � stato distrutto)
				cout << 'S';
				i++;
			}
			if ((h == pianeta2_y) && (i == pianeta2_x) && (Pianeta2Distrutto == false)) {
				cout << 'N';
				i++;

		}
	}
		cout << "|"; //stampa la barriera destra
		h = h + 1;
		i = 0;

}
	cout << endl;
	b = 0;
	while (b < 40) //stampa la barriera inferiore
	{
		cout << "-";
		b = b + 1;
	}
}

void Sistema_Solare::UI(int punteggio)
{
	cout << endl << "Punteggio: " << punteggio; //stampa semplicemente il valore del punteggio
}

void Sistema_Solare::SistemaSolareDistrutto(int & punteggio, bool P1Distrutto, bool P2Distrutto)
{
	if ((P1Distrutto == true) && (P2Distrutto == true)) { //entrambi i pianeti sono stati distrutti? allora ti meriti un punteggio extra 
		punteggio = punteggio + 1000;
	}
}

void Sistema_Solare::GiocaSistemaSolare(int& punteggio, bool& GAMEOVER, int& vite, int& serbatoio, bool& VAI_SS_SINISTRA, bool& VAI_SS_DESTRA)
{

	astronave infinity;
	infinity.x = 1;
	infinity.y = 1;

	if (SSspawnato == false) { //nel caso spawnato sia false, vuol dire che il sistema solare non � stato mai creato quindi vengono inizializzati tutti i suoi campi

		PosizionexyPianeti(Pianeta1.x, Pianeta1.y, Pianeta2.x, Pianeta2.y);

		Pianeta1.spawnato = false;
		Pianeta1.PianetaDistrutto = false; 
		Pianeta2.spawnato = false;
		Pianeta2.PianetaDistrutto = false; 

		SSspawnato = true; //dato che sono state inizializzati tutti i campi, ora spawnato sar� true in modo che non vengano riniziallizati di nuovo, dato che vogliamo che quando si rientra nel sistema solare rimanga invariato
	}


	while ((GAMEOVER == false) && (infinity.x != 0) && (infinity.x != 36)) {  //finch� non si perde, oppure non si va al sistema solare di sinistra o destra si continua a ciclare il sistema solare

		if ((infinity.x == Pianeta1.x) && (infinity.y == Pianeta1.y) && (Pianeta1.PianetaDistrutto == false)) { //se il pianeta non � stato distrutto e se le coordinate di astronave e pianeta sono uguali, si entra nel pianeta
			Pianeta1.GiocaPianeta(punteggio, GAMEOVER, Pianeta1.spawnato, vite, serbatoio, Pianeta1.PianetaDistrutto); 
		}

		if ((infinity.x == Pianeta2.x) && (infinity.y == Pianeta2.y) && (Pianeta2.PianetaDistrutto == false)) {
			Pianeta2.GiocaPianeta(punteggio, GAMEOVER,Pianeta2.spawnato, vite, serbatoio, Pianeta2.PianetaDistrutto); 	
		}

		matrice(infinity.x, infinity.y, Pianeta1.x, Pianeta1.y, Pianeta2.x, Pianeta2.y, Pianeta1.PianetaDistrutto, Pianeta2.PianetaDistrutto); //stampa la schermata di gioco
		UI(punteggio); //stampa le informazioni
		SistemaSolareDistrutto(infinity.punteggio, Pianeta1.PianetaDistrutto, Pianeta2.PianetaDistrutto); 
		infinity.button = _getch(); //attende l'input dell'utente, grazie a _getch() si digita quello che si vuole senza la necessti� di confermare tramite il tasto invio

		if ((infinity.button == 'w') || (infinity.button == 'a') || (infinity.button == 's') || (infinity.button == 'd')) { //se l'input � uno dei tasti wasd, ci si muove
			infinity.movimento();

		}

		system("cls"); //pulisce la schermata, per dare un effetto di refresh (cosi non si stampa una matrice sopra l'altra, ma si cancella e si ristampa in continuazione)

	}


	if (infinity.x == 0) { //quando si esce dal ciclo, se la posizione dell'astronave � all'estrema sinistra, il bool VAI_SS_SINISTRA diventa true (ci servir� per il main)

		VAI_SS_SINISTRA = true;
	}
	else if (infinity.x == 36) { //stessa cosa cambia solo che qui si va all'estrema destra
		VAI_SS_DESTRA = true;
	}

	system("pause");
}




