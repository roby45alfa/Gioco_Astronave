#include "stdafx.h"
#include "Astronave.h"
#include <iostream>

//using namespace Entita;

//Costruttore 
Astronave::Astronave(Position p, int size) : Ammo(10 * size), Entita(p, size) {

	std::cout << "Astronave creata!" << std::endl; // << "Inizia a giocare!" << std::endl;
}


//----------------Metodi di test------------------

void Astronave::PrintAstronave() {
	printEntita();
	std::cout << "Ammo: " << Ammo << std::endl;
	return;
}


//--------------metodi di movimento----------------

//spostamento in avanti di n posizioni
void Astronave::Forward(int n) {
	//accedo alla posizione con GetPos() e richiamo il metodo ModifyPosition() dove modifico, cioè aggiungo,  l'assoluto (onde evitare errori) n + l'asse delle y del punto
	GetPOS().ModifyPosition(GetPOS().GetX(), GetPOS().GetY() + abs(n), GetPOS().GetZ());
	CheckLVL(); //controllo che non sia stato superato il livello
	Ammo *= GetLVL();
}

//spostamento a sinistra di n posizioni
void Astronave::Left(int n) {
	//accedo alla posizione con GetPos() e richiamo il metodo ModifyPosition() dove modifico, cioè sottraggo (perchè devo spostarmi a sinistra e la positione di partenza è a (25, 0), l'assoluto (onde evitare errori) n + l'asse delle y del punto
	GetPOS().ModifyPosition(GetPOS().GetX() - abs(n), GetPOS().GetY(), GetPOS().GetZ());
	CheckLim(); //controllo i limiti
}

//spostamento a destra di n posizioni
void Astronave::Right(int n) {
	//accedo alla posizione con GetPos() e richiamo il metodo ModifyPosition() dove modifico, cioè aggiungo(perchè devo spostarmi a destra e la positione di partenza è a (25, 0), l'assoluto (onde evitare errori) n + l'asse delle y del punto
	GetPOS().ModifyPosition(GetPOS().GetX() + abs(n), GetPOS().GetY(), GetPOS().GetZ());
	CheckLim(); //controllo i limiti
}


//          METODI





//Astronave::~Astronave() {
//	std::cout << "Astronave Distrutta!" << std::endl << "HAI PERSO!" << std::endl;
//}
