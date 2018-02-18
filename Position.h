#pragma once

//DEFINIZIONE GENERALE POSITION

class Position {
private:

	//membri dati per la gestione della posizione 
	double X;
	double Y;
	double Z;

	//membri dati per la gestione del nome
	char *name;
	int N_vect;

	//puntatori ad altri punti per creare collegamenti
	Position* Pointer;
	Position* Other;

	//contatore istanze punti creati
	static int N_Istance;



public:

	Position();

	////costruttore 2d
	//Position(double x, double y);                                               //costruttore con solo due punti (X, Y)
	//Position(double x, double y, char* name, int nv);                           //costruttori con punti (X, Y), puntatore a vettore e numero di elementi del vettore
	//Position(double x, double y, Position* P, Position* O);                                  //costruttore con punti (X, Y) e puntatore 
	//Position(double x, double y, char* name, int nv, Position* P, Position);              //costruttore COMPLETO 2D

	//costruttori 3d
	Position(double x, double y, double z);                                     //costruttore con solo tre punti (X, Y, Z)
	Position(double x, double y, double z, char* name, int nv);                 //costruttori con punti (X, Y, Z), puntatore a vettore e numero di elementi del vettore
	Position(double x, double y, double z, Position* P, Position* O);                        //costruttore con punti (X, Y, Z) e puntatore
	Position(double x, double y, double z, char* name, int nv, Position* P, Position* O);    //costruttore COMPLETO 3D

	~Position();  //distruttore

				  //osservatori 
	double GetX();
	double GetY();
	double GetZ();
	char* GetName();
	Position* GetPointer();
	Position* GetOther();
	int GetIstance();
	int GetNvect();
	Position GetPosition();


	//   PROPRIETA'

	//calcola la distanza tra due punti
	double PointDistance(Position);

	//connette due punti con relativa scelta ( "P" per usare il Pointer, "O" per usare Other, ALTRO li connette entrambi nella posizione passata)
	void ConnectPoint(Position, char);

	//sconnette il punto in modo generale
	void DisconnectPoint(char);

	//modifica la posizione dell'entità
	void ModifyPosition(double, double, double);



	//     Metodi TEST
	void printPosition();



};
