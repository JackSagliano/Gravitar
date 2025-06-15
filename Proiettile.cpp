#include "Proiettile.hpp"

bool Proiettile::spara() //una volta che viene sparato il proiettile, il bool sparato diventa true
{
	sparato = true;
	return (sparato);
}

int Proiettile::movimentoproiettile() //si muove lungo l'asse delle y
{
	y = y + 1;
	return (y);
}

bool Proiettile::distruggiproiettile() //una volta arrivato a terra, il bool sparato diventerà false
{
	sparato = false;
	return (sparato);
}
