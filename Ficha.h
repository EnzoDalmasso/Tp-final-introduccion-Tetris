#include<iostream>
#include <conio2.h>
#include <ctime>
#ifndef FICHA_H
#define FICHA_H
using namespace std;

class Ficha {
public:
	Ficha(int num_piezas);
	int devolver_pieza(int y,int x);
	int devolver_indicador(){return indicador_a_pieza;};
	bool devolver_rotada(){return rotada;};
	void rotar();
	
private:
	int ficha[4][4];
	int indicador_a_pieza;
	bool rotada;
	
};

#endif

