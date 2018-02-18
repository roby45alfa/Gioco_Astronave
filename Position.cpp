#include "stdafx.h"
#include "Position.h"
#include <iostream>
#include <math.h>

using namespace std;

int Position::N_Istance = 0;

Position::Position() : X(0), Y(0), Z(0), N_vect(0), name(NULL), Pointer(NULL), Other(NULL) {
	N_Istance++;
}

////              COSTRUTTORI 2D
//
//Position::Position(double x, double y) : X(x), Y(y), Z(0), N_vect(0), name(NULL), Pointer(NULL), Other(NULL) {
//	N_Istance++;
//}
//
////costruttore con nome
//Position::Position(double x, double y, char* name, int nv) : X(x), Y(y), Z(0), N_vect(nv), Pointer(NULL), Other(NULL) {
//	N_Istance++;
//	name = new char[nv];
//}
//
////costruttore con puntatore
//Position::Position(double x, double y, Position* P, Position* O) : X(x), Y(y), Z(0), Pointer(P), N_vect(0), name(NULL), Other(O) {
//	N_Istance++;
//}
//
////costruttore con nome e puntatore
//Position::Position(double x, double y, char* name, int nv, Position* P) : X(x), Y(y), Z(0), N_vect(nv), Pointer(P), Other(NULL) {
//	N_Istance++;
//	name = new char[nv];
//}
//

//              COSTRUTTORI 3D

Position::Position(double x, double y, double z) : X(x), Y(y), Z(z), N_vect(0), name(NULL), Pointer(NULL) {
	N_Istance++;

}

//costruttore con nome
Position::Position(double x, double y, double z, char* name, int nv) : X(x), Y(y), Z(z), N_vect(nv), Pointer(NULL), Other(NULL) {
	N_Istance++;
	name = new char[nv];
}

//costruttore con puntatore
Position::Position(double x, double y, double z, Position* P, Position* O) : X(x), Y(y), Z(z), Pointer(P), N_vect(0), name(NULL), Other(O) {
	N_Istance++;
}

//costruttore con nome e puntatore
Position::Position(double x, double y, double z, char* name, int nv, Position* P, Position* O) : X(x), Y(y), Z(z), N_vect(nv), Pointer(P), Other(O) {
	N_Istance++;
	name = new char[nv];
}


//         distruttore
Position::~Position() {
	N_Istance--;
	if (name) delete[] name;
	Pointer = Other = NULL;
	N_vect = 0;
}


//           PROPRIETA'

//    OSSERVATORI
double Position::GetX() {
	return X;
}

double Position::GetY() {
	return Y;
}

double Position::GetZ() {
	return Z;
}

char* Position::GetName() {
	if (!name) {
		std::cout << "Non e' stato possibile leggere il contenuto della stringa." << std::endl;
		exit(1);
	}
	return name;
}

Position* Position::GetPointer() {
	if (!Pointer) {
		std::cout << "Non e' stato possibile accedere all'area di memoria." << std::endl;
		exit(1);
	}
	return Pointer;
}

Position* Position::GetOther() {
	if (!Other) {
		std::cout << "Non e' stato possibile accedere all'area di memoria." << std::endl;
		exit(1);
	}
	return Other;
}

int Position::GetIstance() {
	return N_Istance;
}

int Position::GetNvect() {
	return N_vect;
}

Position Position::GetPosition() {

	Position F(Position::GetX(), Position::GetY(), Position::GetZ(), Position::GetName(), Position::GetNvect(), Position::GetPointer(), Position::GetOther());
	return F;
}

//       METODI

double Position::PointDistance(Position B) {              //carlcola la distanza tra due punti
	double x1 = B.GetX();
	double y1 = B.GetY();
	double z1 = B.GetZ();

	double d = sqrt(pow(X - x1, 2) + pow(Y - y1, 2) + pow(Z - z1, 2));
	return d;
}

//connette due punti con relativa scelta ( "P" per usare il Pointer, "O" per usare Other, ALTRO li connette entrambi nella posizione passata)
void Position::ConnectPoint(Position P, char s) {
	if (s == 'P') { Pointer = &P; return; }
	else if (s == 'O') { Other = &P; return; }
	Pointer = &P;
	Other = &P;

}

//disconnete due punti con relativa scelta ( "P" per usare il Pointer, "O" per usare Other, ALTRO li sconnette entrambi nella posizione passata)
void Position::DisconnectPoint(char s) {
	if (s == 'P') { Pointer = NULL; return; }
	else if (s == 'O') { Pointer = NULL; return; }
	Pointer = NULL;
	Other = NULL;
}

//modifica la posizione dell'entità
void Position::ModifyPosition(double x, double y, double z) {
	X = x;
	Y = y;
	Z = z;
}

//     METODI TEST
void Position::printPosition() {
	cout << "POSITION:\nX: " << X << endl
		<< "Y: " << Y << endl
		<< "Z: " << Z << endl;

}