#pragma once
#include "Position.h"

class Entita {

private:

	Position P;             //posizione generale dell'entit�
	double Health;          //salute generale dell'entit� =100
	int Level;              //livello generale dell'entit�
	static int N_Istance;   //numero di istanze di entit�




public:


	//      COSTRUTTORI

	Entita(Position, int);    //costruttore generale con assegnazione livello


							  //        OSSERVATORI
	double GetHP();
	double GetLVL();
	Position GetPOS();
	static int GetIstance();


	//        MODIFICATORI
	void CheckLim();            //controlla limiti del campo di gioco
	void CheckLVL();            //controlla il superamento del livello
	void HPNeg();               //controllo che la vita non sia al di sotto dello 0

	double TakeDamage(Entita);


	~Entita();  //distruttore

				//           METODI TEST
	void printEntita(); //stampa tutte le caratteristiche dell'entit�
};
