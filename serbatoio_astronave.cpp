#include "serbatoio_astronave.hpp"

int serbatoio_astronave::carbumeno(int& n_movimenti) //ad ogni movimento il n_movimenti diminuisce di 1
{
	n_movimenti = n_movimenti - 1;
	return(n_movimenti);

}

int serbatoio_astronave::carbupoco(int& n_movimenti) //si hanno 10 nuovi movimenti a disposizione
{
	n_movimenti = n_movimenti + 10;
	return(n_movimenti);
}

int serbatoio_astronave::carbutanto(int& n_movimenti) //si hanno 20 nuovi movimenti a disposizione
{
	n_movimenti = n_movimenti + 20;
	return(n_movimenti);
}
