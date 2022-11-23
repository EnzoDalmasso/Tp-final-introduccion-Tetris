#ifndef TABLERO_H
#define TABLERO_H
#include<iostream>
#include <conio2.h>
#include <ctime>
#include "Ficha.h"
using namespace std;

class Tablero {
public:
	Tablero();
	void bucle();
	
private:
	//variables
	bool encargado;
	clock_t tempo; 
	clock_t paso; 
	int velocidad;
	float tiempo2;
	int tabla[15][10];
	Ficha* F;
	int tecla;
	int cambio_direccion;
	int cord_y;
	int cord_x;
	int copia_de_tabla[15][10];
	float tiempo_pieza;
	int pieza_aleatoria;
	int sumatoria_de_puntos;
	//funciones
	void imprimir_pant();
	void colocar_ficha();
	void detectar_botones();
	void mov_posible(int numero_pieza);
	void mover(int llamado_posible);
	void rotar_pieza();
	void pieza_rotada(int llamar_accion);
	void borrar_piezaant();
	void transformar();
	void detectar_colisiones();
	void reiniciar_pieza();
	void bajar_pieza();
	void detectar_tetris();
	void borra_linea_tetris(int enc_fila);
	void baja_linea_tetris();
	void sumar_puntos();
	void mostrar_puntos();
	void detectar_derrota();
};

#endif

