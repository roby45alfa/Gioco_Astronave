// Gioco_Astronave[CLASSI].cpp : definisce il punto di ingresso dell'applicazione console.
//

#include "stdafx.h"
#include "Entita.h"
#include "Astronave.h"
#include "Position.h"

int main()
{
	Position P_astronave(25, 0, 0);
	Astronave Astronave(P_astronave, 1);

	Astronave.PrintAstronave();
	return 0;
}

