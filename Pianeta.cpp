#include <iostream>
#include <cstring>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "Pianeta.hpp"
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

using namespace std;

bool Pianeta::GameOver(bool & gameover, int & vite, int & serbatoio, int & ax, int & ay)  //se le vite finiscono, perdi.
                                                                                    //Altrimenti respawni in alto a sinistra con del carburante impostato di default
{
	if (vite == 0 || serbatoio == 0) { //finito le vite o finito il serbatoio? hai perso
		gameover = true;

	}
	else { //altrimenti perdi una vita
		vite = vite - 1;
		serbatoio = 50;
		ax = 1;
		ay = 1;

	}
	return(gameover); 
}

void Pianeta::PosizioneXBunker(int & bdx, int & bfx, int pavimento[]) 
{
	int i;
	bool BDAssegnato; //è stato generato il bunker debole?
	bool BFAssegnato; //stessa cosa ma per il bunker forte
	BDAssegnato = false;
	BFAssegnato = false;
	while (BDAssegnato == false || BFAssegnato == false) {    //la condizione che una non esclude l'altra è fatta per fare in modo che tutti e due i bunker
		                                                      //vengano sempre spawnati
		for (i = 1; i < 38; i++) {
			if (pavimento[i] == 1 && BDAssegnato == false) {    //pavimento[i]==1 indica che il bunker verrà sempre spawnato su una montagna 
				bdx = i; 
				BDAssegnato = true;
			}
			else if (pavimento[i] == 1 && BDAssegnato == true) {
				bfx = i;
				BFAssegnato = true;
			}

		}
	}
	if (bfx == 37) {
		bfx = 35;
	}
}

void Pianeta::terreno(int pavimento[])
{

	int i = 0;
	srand(time(NULL));

	while (i < 38 - 1) {
		if (i == 35) {
			pavimento[i] == 1;
			i = i + 1;
			pavimento[i] == 1;
			i = i + 1;
		}

		pavimento[i] = rand() % 2;

		if (pavimento[i] == 1) {
			pavimento[i + 1] = 1; //condizione di tipo estetico, per evitare che le montagne siano dei grissini viene stampata un'altra stanghetta
			i = i + 2;
		}

		i++;
	}
}

void Pianeta::stampaterreno(int pavimento[])
{
	int i;
	i = 0;
	cout << endl << "|";
	while (i < 38) {
		if (pavimento[i] == 0) {
			cout << "_";
		}
		else {
			cout << "|";

		}
		i++;

	}
	cout << "|";
}

void Pianeta:: matrice(int& astronave_x, int& astronave_y, bool& raggio_tr, int& benz_x, int& benz_y, int& gpl_x, int& gpl_y,
	int& bunker1_x, int& bunker1_y, int& bunker2_x, int& bunker2_y,
	bool& sparato1, int& proiett1_x, int& proiett1_y, bool& sparato2, int& proiett2_x, int& proiett2_y, bool& sparato3, int& proiett3_x, int& proiett3_y,
	int& ProiettClassico_y, int& ProiettClassico_x, int& ProiettForteClassico_x, int& ProiettForteZigZag_x, int& ProiettDeboleDiagonale_x, int& ProiettForteDiagonale_x) {
	
	cout << "Non-Gravitar by Nur & Jack" << endl;


	int b, h, i;
	b = 0; //servirà per disegnare la base
	h = 0; //è l'altezza della matrice(corrisponde ad un endl)
	i = 0; //conta gli spazi per spazio


	while (b < 40) { //stampa la barriera alta del gioco
		cout << "-";
		b = b + 1;

	}

	while (h < 19) {
		cout << endl << "|"; //stampa la barriera sinistra
		while (i < 38) {
			cout << ' '; //riempie di spazi vuoti il campo di gioco fino ad arrivare alla barriera destra
			i = i + 1;
			if ((h == astronave_y) && (i == astronave_x)) {
				cout << 'V'; //nel caso le coordinate siano uguali, invece di uno spazio vuoto stampa l'astronave
				i = i + 1;

			}

			if ((h == bunker1_y) && (i == bunker1_x)) {
				cout << '0';
				i = i + 1;
			}

			if ((h == bunker2_y) && (i == bunker2_x)) {
				cout << '8';
				i = i + 1;
			}

			if ((h == proiett1_y) && (i == proiett1_x) && (sparato1 == true)) {
				cout << 'I';
				i = i + 1;
			}

			if ((h == proiett2_y) && (i == proiett2_x) && (sparato2 == true)) {
				cout << 'I';
				i = i + 1;
			}

			if ((h == proiett3_y) && (i == proiett3_x) && (sparato3 == true)) {
				cout << 'I';
				i = i + 1;
			}

			
			if (h == ProiettClassico_y) {
				if ((i == ProiettClassico_x) || (i == ProiettForteClassico_x) || (i == ProiettForteZigZag_x) || (i == ProiettDeboleDiagonale_x) || (i == ProiettForteDiagonale_x)) {
					cout << 'I';
					i = i + 1;
				}
			}

			if ((h == astronave_y + 1) && (i == astronave_x) && (raggio_tr == true)) { //stampa il raggio
				cout << 'A';
				i = i + 1;

			}


			if ((h == benz_y) && (i == benz_x)) { //stampa la benzina
				cout << 'B';
				i = i + 1;

			}

			if ((benz_y == astronave_y + 1) && (benz_x == astronave_x) && (raggio_tr == true)) { //nel caso con il raggio si prenda la benzina, essa scompare
				benz_y = 100;
				benz_x = 100;

			}

			if ((h == gpl_y) && (i == gpl_x)) { //stampa il GPL
				cout << 'G';
				i = i + 1;

			}

			if ((gpl_y == astronave_y + 1) && (gpl_x == astronave_x) && (raggio_tr == true)) { //nel caso
				//con il raggio si prenda il GPL, esso scompare
				gpl_y = 200;
				gpl_x = 200;

			}


		}
		cout << "|"; //stampa la barriera destra
		h = h + 1; 
		i = 0;   //ogni volta si riparte a ciclare dall'estremo sinistro di ogni riga

	}
}


void Pianeta::UI(int tacche_carburante, int vite, bool psparato1, bool psparato2, bool psparato3, int punteggio)
{
	int i = 0;
	cout << endl << "carburante" << endl;
	while (i < tacche_carburante / 10) {
		cout << "+";
		i = i + 1;

	}
	i = 0;
	cout << endl << "vite" << endl;
	while (i < vite) {
		cout << "V";
		i = i + 1;

	}

	cout << endl << "Punteggio giocatore:" << punteggio;

	cout << endl << "Missile 1";

	if (psparato1 == false) {
		cout << "PRONTO";
	}

	cout << endl << "Missile 2";

	if (psparato2 == false) {
		cout << "PRONTO";
	}

	cout << endl << "Missile 3";

	if (psparato3 == false) {
		cout << "PRONTO";
	}

	cout << endl;

}

void Pianeta::GiocaPianeta(int& punteggio, bool& gameover, bool& spawnato, int& vite, int& serbatoio_rimasto, bool& PDistrutto)
{

		bool go = false; //gameover
		bool youwin = false; //youwin

		bool proiettilebunkersparato = false; //i bunker hanno sparato?

		astronave infinity;
		infinity.x = 1;
		infinity.y = 1;
		infinity.raggio_traente = false;
		infinity.vite = vite; //deve cambiare quando si esce e rientra


		Bunker1 BunkerForte;
		BunkerForte.y = 18;
		BunkerForte.distrutto = false; 

		Bunker2 BunkerDebole;
		BunkerDebole.y = 18;
		BunkerDebole.distrutto = false; 

		serbatoio_astronave serbatoio;

		carburante benzina;
		srand(time(NULL));
		benzina.x = rand() % 35 + 2; 
		benzina.y = rand() % 15 + 2; 

		carburante GPL;
		GPL.x = rand() % 35 + 2; 
		GPL.y = rand() % 15 + 2; 


		Proiettile Proiettile1; //proiettile 1 2 3 sono della navicella, 1 si spara con I, 2 con O, 3 con P
		Proiettile Proiettile2;
		Proiettile Proiettile3;
		Proiettile1.sparato = false;
		Proiettile2.sparato = false;
		Proiettile3.sparato = false;


		ProiettileBunker ProiettileClassico; //sono tutti proiettili diversi, ognuno si muove in direzione diversa
		ProiettileBunker ProiettileForteClassico;
		ProiettileBunker2 ProiettileForteZigZag;
		ProiettileBunker3 ProiettileDeboleDiagonaleDestro;
		ProiettileBunker4 ProiettileForteDiagonaleSinistro;

		if (spawnato == false) { 
			
			terreno(pavimento);//funzione che genera il terreno 
			PosizioneXBunker(BunkerDebole.x, BunkerForte.x, pavimento);

			forte_distrutto = BunkerForte.distrutto; 
			debole_distrutto = BunkerDebole.distrutto; 
			x_benzina = benzina.x;  
			y_benzina = benzina.y; 
			x_GPL = GPL.x; 
			y_GPL = GPL.y; 
			x_debole = BunkerDebole.x; 
			x_forte = BunkerForte.x; 

			spawnato = true;
		}

	while ((go == false) && (youwin == false) && (infinity.y != 0)) { //ciclo di gioco, si interrompe se si esce dal pianeta, se si vince o perde
		//SE IL PROIETTILE DEL BUNKER NON è STATO SPARATO, ALLORA GLI VENGONO ASSEGNATE LE COORDINATE INIZIALI
		if (proiettilebunkersparato == false) {
			ProiettileClassico.y = BunkerDebole.y - 1;
			if (debole_distrutto == false) {
				ProiettileClassico.x = ProiettileDeboleDiagonaleDestro.x = x_debole;
			}
			else {
				ProiettileClassico.x = ProiettileDeboleDiagonaleDestro.x = 1000;
			}
			if (forte_distrutto == false) {
				ProiettileForteClassico.x = x_forte - 3;
				ProiettileForteDiagonaleSinistro.x = x_forte;
				ProiettileForteZigZag.x = x_forte + 1;
			}
			else {
				ProiettileForteClassico.x = 1000;
			}
			proiettilebunkersparato = true; //APPENA IL PROIETTILE è STATO SPARATO, QUESTO BOOL DIVENTA TRUE IN MODO TALE DA NON CREARE UNA RAFFICA DI
			                               //PROIETTILI E SPARARNE UNO ALLA VOLTA
		}

		//VIENE STAMPATA LA GRAFICA DEL PIANETA
		matrice(infinity.x, infinity.y, infinity.raggio_traente, x_benzina, y_benzina, x_GPL, y_GPL,
			x_debole, BunkerDebole.y, x_forte, BunkerForte.y,
			Proiettile1.sparato, Proiettile1.x, Proiettile1.y, Proiettile2.sparato, Proiettile2.x, Proiettile2.y, Proiettile3.sparato, Proiettile3.x, Proiettile3.y,
			ProiettileClassico.y, ProiettileClassico.x, ProiettileForteClassico.x, ProiettileForteZigZag.x, ProiettileDeboleDiagonaleDestro.x, ProiettileForteDiagonaleSinistro.x
		);

		stampaterreno(pavimento);

		UI(serbatoio_rimasto, infinity.vite, Proiettile1.sparato, Proiettile2.sparato, Proiettile3.sparato, punteggio); 

		infinity.button = _getch(); //la funzione getch ci permette di memorizzare ogni carattere premuto senza dover premere invio e quindi di far muovere la nostra astronave
		
		//SE L'ASTRONAVE SI MUOVE, BISOGNA RICHIAMARE LA FUNZIONE CHE PERMETTE IL SUO MOVIMENTO E LA FUNZIONE CHE ESAURISCE IL CARBURANTE
		if ((infinity.button == 'w') || (infinity.button == 'a') || (infinity.button == 's') || (infinity.button == 'd')) {
			infinity.movimento();
			serbatoio.carbumeno(serbatoio_rimasto);

		}
		//RAGGIO ATTRAENTE RICHIAMATO COL TASTO 'x'
		else if ((infinity.button == 'x')) {
			infinity.active_raggio_traente();

		}

		//PROIETTILI DELL'ASTRONAVE SPARATI CON I TASTI 'i' 'o' 'p' SOLO SE IL BOOL CORRISPONDENTE è FALSE, IL CHE VUOL DIRE CHE ANCHE IN QUESTO 
		//CASO L'ASTRONAVE SPARA UN PROIETTILE(DELLO STESSO TIPO) ALLA VOLTA 
		else if ((infinity.button == 'i') || (infinity.button == 'o') || (infinity.button == 'p')) {
			if (infinity.button == 'i' && Proiettile1.sparato == false) {
				Proiettile1.spara();
				Proiettile1.x = infinity.x;
				Proiettile1.y = infinity.y;
			}
			if (infinity.button == 'o' && Proiettile2.sparato == false) {
				Proiettile2.spara();
				Proiettile2.x = infinity.x;
				Proiettile2.y = infinity.y;
			}
			if (infinity.button == 'p' && Proiettile3.sparato == false) {
				Proiettile3.spara();
				Proiettile3.x = infinity.x;
				Proiettile3.y = infinity.y;
			}
		}
		
		//IF CHE PERMETTE AI PROIETTILI DELL'ASTRONAVE DI CONTINUARE IL LORO MOTO VERSO IL BASSO
		if ((Proiettile1.sparato == true)) {
			Proiettile1.movimentoproiettile();
			if (Proiettile1.y == 19) {
				Proiettile1.distruggiproiettile();
			}
		}
		if ((Proiettile2.sparato == true)) {
			Proiettile2.movimentoproiettile();
			if (Proiettile2.y == 19) {
				Proiettile2.distruggiproiettile();
			}
		}
		if ((Proiettile3.sparato == true)) {
			Proiettile3.movimentoproiettile();
			if (Proiettile3.y == 19) {
				Proiettile3.distruggiproiettile();
			}
		}

		//SE UNO DEI TRE PROIETTILI DELL'ASTRANAVE TOCCA UNO DEI BUNKER, QUEST'ULTIMO VIENE DISTRUTTO
		if (((x_debole == Proiettile1.x) && (BunkerDebole.y == Proiettile1.y)) ||
			((x_debole == Proiettile2.x) && (BunkerDebole.y == Proiettile2.y)) ||
			((x_debole == Proiettile3.x) && (BunkerDebole.y == Proiettile3.y))) {
			x_debole = 1000;
			debole_distrutto = true;
			infinity.AumentaPunteggio(punteggio);

		}
		if (((x_forte == Proiettile1.x) && (BunkerForte.y == Proiettile1.y)) ||
			((x_forte == Proiettile2.x) && (BunkerForte.y == Proiettile2.y)) ||
			((x_forte == Proiettile3.x) && (BunkerForte.y == Proiettile3.y))) {
			x_forte = 1000;
			forte_distrutto = true;
			infinity.AumentaPunteggio(punteggio);
		}
		
		//SE L'ASTRONAVE HA IL RAGGIO ATTRAENTE ATTIVO ED ESSA SI TROVA SULLA VERTICALE DEL CARBURANTE(CON Y MAGGIORE DI 1 RISPETTO AL CARBURANTE), 
		//ALLORA VIENE INCREMENTATO IL CARBURANTE ALL'INTERNO DEL SERBATOIO
		if ((x_benzina == infinity.x) && (y_benzina == infinity.y + 1) && (infinity.raggio_traente == true)) {
			serbatoio.carbutanto(serbatoio_rimasto);

		}
		else if ((x_GPL == infinity.x) && (y_GPL == infinity.y + 1) && (infinity.raggio_traente == true)) {
			serbatoio.carbupoco(serbatoio_rimasto);

		}

		//SE ENTRAMBI I BUNKER VENGONO DISTRUTTI, OTTENIAMO PUNTEGGIO EXTRA(MAGGIORE RISPETTO A QUELLO OTTENUTO SE SI DISTRUGGE UN SINGOLO BUNKER)
		//E ANCHE IL PIANETA VIENE DISTRUTTO
		if ((debole_distrutto == true) && (forte_distrutto == true)) {
			infinity.PunteggioExtra(punteggio);
			youwin = true;
		}

		//SE IL PROIETTILE CLASSICO(QUELLO CHE VA SOLO VERTICALMENTE) TOCCA LA PARTE ALTA DELLA MATRICE, VUOL DIRE CHE TUTTI I PROIETTILI HANNO 
		//TOCCATO LA PARTE ALTA DELLA MATRICE(PERCHè VENGONO SPARATI CONTEMPORANEAMENTE) E QUINDI POSSONO ESSERE SPARATI DI NUOVO DAI BUNKER
		if (ProiettileClassico.y == 0) {
			proiettilebunkersparato = false;
		}
		//VIENE RICHIAMATO IL MOVIMENTO DEI PROIETTILI
		ProiettileClassico.movimentoproiettile();
		ProiettileDeboleDiagonaleDestro.movimentoAsseX();
		ProiettileForteDiagonaleSinistro.movimentoAsseX();
		//PER FAR SI CHE IL PROIETTILE CHE VA A ZIG ZAG SI MUOVA
		if (ProiettileForteZigZag.x == (x_forte + 1)) {
			ProiettileForteZigZag.movimentoAsseXSinistra();
		}
		else {
			ProiettileForteZigZag.movimentoAsseXDestra();
		}

		//SE SI ESAURISCE IL CARBURANTE, O L'ASTRONAVE TOCCA A TERRA, O VIENE COLPITA DA UN PROIETTILE, ALLORA SI RICHIAMA LA FUNZIONE GAMEOVER CHE:
		//FA PERDERE IL GIOCATORE SE LE VITE SONO ESAURITE
		//FA RESPAWNARE IL GIOCATORE NELLE COORDINATE(1,1) CON IL CARBURANTE INIZIALE E CON UNA VITA IN MENO
		if ((serbatoio_rimasto <= 0) || infinity.y == 18 || ((infinity.y == ProiettileClassico.y) &&
			((infinity.x == ProiettileClassico.x) || (infinity.x == ProiettileForteClassico.x) ||
			(infinity.x == ProiettileDeboleDiagonaleDestro.x) || (infinity.x == ProiettileForteDiagonaleSinistro.x) || (infinity.x == ProiettileForteZigZag.x))))
		{
			GameOver(go, infinity.vite, serbatoio_rimasto, infinity.x, infinity.y);
			proiettilebunkersparato = false;
		}
		system("cls");

	}

	if (go == true) {
		cout << endl << "Gameover, il tuo Punteggio:" << punteggio << endl;
	}

	else if (youwin == true) {
		cout << endl << "Pianeta distrutto, il tuo punteggio:" << punteggio << endl;
		PianetaDistrutto = true;
	}

	gameover = go;
	
	vite = infinity.vite;
	PDistrutto = PianetaDistrutto;
	//mostra il punteggio prima di chiudere il gioco
	system("pause");
}
