#include "ProiettileBunker2.hpp"

int ProiettileBunker2::movimentoAsseXDestra() //si muove a destra...
{
	x = x + 2;
	return(x);
}

int ProiettileBunker2::movimentoAsseXSinistra() //...poi a sinistra per dare un effetto a zig zag
{
	x = x - 2;
	return(x);
}
