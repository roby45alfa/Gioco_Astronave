#pragma once
#include "Position.h"
#include "Entita.h"
#include "Nemico.h"

class Astronave : public Nemico , public Entita {

private:

	int Ammo;

	void Forward(int);          //spostamento in avanti
	void Left(int);             //spostamento a sinistra
	void Right(int);            //spostamento a destra



public:

	Astronave(Position, int);



	void PrintAstronave();


	//~Astronave();

};
