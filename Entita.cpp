#include "stdafx.h"
#include "Entita.h"
#include "Position.h"
#include <iostream>

using namespace std;

int Entita::N_Istance = 0;


//        COSTRUTTORE

Entita::Entita(Position p, int size) : P(p), Level(size), Health(100 * size) {
	N_Istance++;
}


//       OSSERVATORI

Position Entita::GetPOS() { return P; }

double  Entita::GetHP() { return Health; }

double Entita::GetLVL() { return Level; }

int Entita::GetIstance() { return N_Istance; }



//distruttore
Entita::~Entita() {
	N_Istance--;
	P.ModifyPosition(-1, -1, -1);
}


//     METODI

double TakeDamage(Entita N) {

}


//metodo di contrtollo limiti 
void Entita::CheckLim() {
	if (P.GetX() > 50) P.ModifyPosition(50, P.GetY(), P.GetZ());
	else if (P.GetX() < 0) P.ModifyPosition(0, P.GetY(), P.GetZ());
	return;
}

void Entita::HPNeg() {
	if (Health < 0) P.ModifyPosition(-1, -1, -1);

}

void Entita::CheckLVL() {
	if (P.GetY() > 1000) {
		P.ModifyPosition(P.GetX(), 0, P.GetZ());
		Level++;
		Health *= Level;
		return;
	}
	else return;
}


//     METODI TEST

void Entita::printEntita() {
	GetPOS().printPosition();
	cout << "Health: " << GetHP() << endl
		<< "Level: " << GetLVL() << endl
		<< "N_istance: " << GetIstance() << endl;

}