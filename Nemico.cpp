#include "stdafx.h"
#include "stdlib.h"
#include "Nemico.h"
#include <time.h>


#define randomize srand((unsigned)time(NULL))

Nemico::Nemico(Position p, int size) { 
	randomize;
	int x = rand() % 50 + 1;
	int y = rand() % 1000 + 1;
	p.ModifyPosition(x, y, 0);
	Entita(p, size);
}


Nemico::~Nemico()
{
}
