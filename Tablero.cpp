#include "Tablero.h"

Tablero::Tablero()
{
	srand(time(NULL));
	for(int y=0; y<15;y++)
	{
	
		for(int x=0;x<10;x++)
		{
			tabla[y][x]=0;
			
		}
		
	}
	cambio_direccion=0;
	encargado=true;
	velocidad=10;
	paso=CLOCKS_PER_SEC/velocidad; 
	tempo=clock();
	tiempo2=1;
	sumatoria_de_puntos=0;
	int cord_y=0;
	int cord_x=0;
	tiempo_pieza=5;
	pieza_aleatoria=0;
	pieza_aleatoria= rand()%5+1;
	F=new Ficha(pieza_aleatoria);
	colocar_ficha();

}


void Tablero::imprimir_pant()
{
	
	system("cls");
	for(int y=0; y<15;y++)
	{
		cout<<endl;
		for(int x=0;x<10;x++)
		{
			cout<<" "<<tabla[y][x];
			
		}
		
	}
	mostrar_puntos();
	
}
void Tablero::bucle()//EL QUE SE ENCARGA DE TODO
{
	while(encargado==true)
	{
		if(tempo+paso<clock())
		{
			
			if(tiempo2==0)
			{
				imprimir_pant();
				tiempo2=1;
				detectar_botones();
				detectar_colisiones();
				detectar_derrota();
			}
			if(tiempo_pieza==0)
			{
				bajar_pieza();
				tiempo_pieza=5;
				detectar_tetris();
				
			}
			tiempo2--;
			tiempo_pieza--;
			tempo=clock();//Siempre al final
		}
		
	}
}
void Tablero::colocar_ficha()
{
	for(int y=0; y<4;y++)
	{
		
		for(int x=0;x<4;x++)
		{
			if(F->devolver_pieza(y,x)==1)
			{
				tabla[y][x+4]=F->devolver_pieza(y,x);
			}
		}
		
	}
}
void Tablero::detectar_botones()
{
	if(kbhit())
	{
		tecla=getch();
		switch(tecla){
	case 114:
		rotar_pieza();
		break;
		case 75:case 77: case 80:
		mov_posible(tecla);
		break;
		}
		
	}
	tecla=0;
	
}
void Tablero::mov_posible(int numero_pieza)
{
	switch(numero_pieza)
	{
		case 75:
		//Estos 2 for recorren la tabla de arriba para abajo y de izquierda a derecha
			
		for(int y=14; y>=0;y--)
		{
			
		for(int x=0; x<10;x++)
		{
			
			//Cuando encuentre una ficha y no se encuentre al lado de una pared o un bloque
			
			if(tabla[y][x]==1 && (tabla[y][x-1]==2 || x==0))
			{

				numero_pieza=0;
				mover(numero_pieza);
				//corta la busqueda si es que encuentra un bloqueo
				break;
			}
				
				
		}
		
		
		}
		if(numero_pieza != 0)
		{
			numero_pieza=1;
			mover(numero_pieza);
		}
		
		
		break;
	case 77:
		//Estos 2 for recorren la tabla de arriba para abajo y de izquierda a derecha
		
		for(int y=14; y>=0;y--)
		{
			
			for(int x=10; x>=0;x--)
			{
				
				//Cuando encuentre una ficha y no se encuentre al lado de una pared o un bloque
				
				if(tabla[y][x]==1 && ((tabla[y][x+1]!=0 && tabla[y][x+1]!=1) || x==9))
				{
					
					numero_pieza=0;
					mover(numero_pieza);
					//corta la busqueda si es que encuentra un bloqueo
					break;
				}
				
				
			}
			
			
		}
		if(numero_pieza != 0)
		{
			numero_pieza=2;
			mover(numero_pieza);
		}
		
		break;
		
	case 80:
		//Estos 2 for recorren la tabla de arriba para abajo y de izquierda a derecha
		
		for(int y=14; y>=0;y--)
		{
			
			for(int x=10; x>=0;x--)
			{
				
				//Cuando encuentre una ficha y no se encuentre al lado de una pared o un bloque
				
				if(tabla[y][x]==1 && ((tabla[y+1][x]!=0 && tabla[y+1][x]!=1) || y==14))
				{
					
					numero_pieza=0;
					mover(numero_pieza);
					//corta la busqueda si es que encuentra un bloqueo
					break;
				}
				
				
			}
			
			
		}
		if(numero_pieza != 0)
		{
			numero_pieza=3;
			mover(numero_pieza);
		}
		
		
		
		break;
	}
	
}
void Tablero::mover(int llamado_posible)
{

		switch( llamado_posible)
		{
		case 1:
			for(int y=14; y>=0;y--)
			{
				
				for(int x=0; x<10;x++)
				{
					if(tabla[y][x]==1)
					{
						tabla[y][x]=0;
						tabla[y][x-1]=1;
					}				
					
				}
			}
			break;
		case 2:
			for(int y=14; y>=0;y--)
			{
				
				for(int x=10; x>=0;x--)
				{
					if(tabla[y][x]==1)
					{
						tabla[y][x]=0;
						tabla[y][x+1]=1;
					}				
					
				}
			}
			break;
		case 3:
			for(int y=14; y>=0;y--)
			{
				
				for(int x=10; x>=0;x--)
				{
					if(tabla[y][x]==1)
					{
						tabla[y][x]=0;
						tabla[y+1][x]=1;
					}				
					
				}
			}
			break;
	
		}
	
}
void Tablero::rotar_pieza()
{
		switch(F->devolver_indicador())
		{
		case 1:
			if(F->devolver_rotada()==0)
			{
				for(int y=14; y>=0;y--)
				{
					
					for(int x=0; x<10;x++)
					{
						//Pimero encuentro pivote
						if(tabla[y][x]==1 && tabla[y-1][x]==1 && (tabla[y+1][x]==0 || tabla[14][x]==1))
						{
							cord_x=x;
							cord_y=y;
							//revisa si se puede realizar movimiento
							if(cord_x>2 && tabla [cord_y][cord_x-3]==0 && tabla [cord_y][cord_x-2]==0 && tabla [cord_y][cord_x-1]==0)
							{
								
								F->rotar();
								borrar_piezaant();
								pieza_rotada(1);
							}
							else {
								
								pieza_rotada(0);
							}
							
						
						}
					}
				}
			}
			else
			   {
				if(F->devolver_rotada()==1)
				{
					for(int y=14; y>=0;y--)
					{
						
						for(int x=0; x<10;x++)
						{
							if(tabla[y][x]==1 && tabla[y][x-1]==1 && tabla[y][x+1]==0)
							{
								cord_x=x;
								cord_y=y;
								if(cord_y>2 && tabla [cord_y-3][cord_x]==0 && tabla [cord_y-2][cord_x]==0 && tabla [cord_y-1][cord_x]==0)
								{
									
									F->rotar();
									borrar_piezaant();
									pieza_rotada(2);
								}
								pieza_rotada(0);
								
							}
						}
					}
				}	
				}
			break;
		case 3:
			if(F->devolver_rotada()==0)
			{
				for(int y=14; y>=0;y--)
				{
					
					for(int x=0; x<10;x++)
					{
						//Pimero encuentro pivote
						if(tabla[y][x]==1 && tabla[y+1][x]==1 && tabla[y-1][x]==0)
						{
							cord_x=x;
							cord_y=y;
							//revisa si se puede realizar movimiento
							if(tabla [cord_y][cord_x+1]==0 )
							{
								
								F->rotar();
								borrar_piezaant();
								pieza_rotada(3);
							}
							else {
								
								pieza_rotada(0);
							}
							
							
						}
					}
				}
			}
			else
			{
				if(F->devolver_rotada()==1)
				{
					for(int y=14; y>=0;y--)
					{
						
						for(int x=0; x<10;x++)
						{
							if(tabla[y][x]==1 && tabla[y+1][x]==1 && tabla[y-1][x]==0)
							{
								cord_x=x;
								cord_y=y;
								if(tabla [cord_y+2][cord_x+1]==0 )
								{
								
									F->rotar();
									borrar_piezaant();
									pieza_rotada(4);
								}
								pieza_rotada(0);
								
							}
						}
					}
				}	
			}
			break;
		case 4:
			if(F->devolver_rotada()==0)
			{
				for(int y=14; y>=0;y--)
				{
					
					for(int x=0; x<10;x++)
					{
						//Pimero encuentro pivote
						if(tabla[y][x]==1 && tabla[y][x+1]==1)
						{
							cord_x=x;
							cord_y=y;
							//revisa si se puede realizar movimiento
							if(tabla [cord_y+1][cord_x]==0 && tabla[cord_y-1][cord_x+1]==0)
							{
								
								F->rotar();
								borrar_piezaant();
								pieza_rotada(5);
							}
							else {
								
								pieza_rotada(0);
							}
							
							
						}
					}
				}
			}
			else
			{
				if(F->devolver_rotada()==1)
				{
					for(int y=14; y>=0;y--)
					{
						
						for(int x=0; x<10;x++)
						{
							if(tabla[y][x]==1 && tabla[y][x+1]==1)
							{
								cord_x=x;
								cord_y=y;
								if(tabla [cord_y-1][cord_x]==0 && tabla[cord_y+1][cord_x+1]==0 )
								{
								
									F->rotar();
									borrar_piezaant();
									pieza_rotada(6);
								}
								pieza_rotada(0);
								
							}
						}
					}
				}	
			}
			break;
		case 5:
			if(F->devolver_rotada()==0)
			{
				for(int y=14; y>=0;y--)
				{
					
					for(int x=0; x<10;x++)
					{
						//Pimero encuentro pivote
						if(tabla[y][x]==1 && tabla[y+1][x]==1)
						{
							cord_x=x;
							cord_y=y;
							//revisa si se puede realizar movimiento
							if(tabla [cord_y-1][cord_x]==0 && cord_y>0)
							{
								
								F->rotar();
								borrar_piezaant();
								pieza_rotada(7);
							}
							else {
								
								pieza_rotada(0);
							}
							
							
						}
					}
				}
			}
			else
			{
				if(F->devolver_rotada()==1)
				{
					for(int y=14; y>=0;y--)
					{
						
						for(int x=0; x<10;x++)
						{
							if(tabla[y][x]==1 && tabla[y-1][x]==1)
							{
								cord_x=x;
								cord_y=y;
								if(tabla [cord_y+1][cord_x]==0 && cord_y<15)
								{
									
									F->rotar();
									borrar_piezaant();
									pieza_rotada(8);
								}
								pieza_rotada(0);
								
							}
						}
					}
				}	
			}
			break;
		}
}
void Tablero::pieza_rotada(int llamar_accion)
{
	
	switch(llamar_accion)
	{
	case 1:
		
			tabla[cord_y][cord_x]=1;
			tabla[cord_y][cord_x-1]=1;
			tabla[cord_y][cord_x-2]=1;
			tabla[cord_y][cord_x-3]=1;
			
			break; 
			
	case 2:
		
			tabla[cord_y][cord_x]=1;
			tabla[cord_y-1][cord_x]=1;
			tabla[cord_y-2][cord_x]=1;
			tabla[cord_y-3][cord_x]=1;
		
		break;
	case 3:
		
		tabla[cord_y][cord_x]=1;
		tabla[cord_y+1][cord_x]=1;
		tabla[cord_y+2][cord_x]=1;
		tabla[cord_y][cord_x+1]=1;
		
		break; 
		
	case 4:
		
		tabla[cord_y][cord_x]=1;
		tabla[cord_y+1][cord_x]=1;
		tabla[cord_y+2][cord_x]=1;
		tabla[cord_y+2][cord_x+1]=1;
		
		break;
	case 5:
		
		tabla[cord_y][cord_x]=1;
		tabla[cord_y][cord_x+1]=1;
		tabla[cord_y-1][cord_x+1]=1;
		tabla[cord_y+1][cord_x]=1;
		
		break; 
		
	case 6:
		
		tabla[cord_y][cord_x]=1;
		tabla[cord_y-1][cord_x]=1;
		tabla[cord_y][cord_x+1]=1;
		tabla[cord_y+1][cord_x+1]=1;
		
		break; 
	case 7:
		
		tabla[cord_y][cord_x]=1;
		tabla[cord_y-1][cord_x]=1;
		tabla[cord_y][cord_x+1]=1;
		tabla[cord_y][cord_x-1]=1;
		
		break; 
		
	case 8:
		
		tabla[cord_y][cord_x]=1;
		tabla[cord_y+1][cord_x]=1;
		tabla[cord_y][cord_x+1]=1;
		tabla[cord_y][cord_x-1]=1;
		
		break; 
	}
}
void Tablero::borrar_piezaant()
{
	for(int y=14; y>=0;y--)
	{
		
		for(int x=0; x<10;x++)
		{
		if(tabla[y][x]==1)
		{
			tabla[y][x]=0;
			
		}
		
		}
	}
}
void Tablero::transformar()
{
	for(int y=14; y>=0;y--)
	{
		
		for(int x=0; x<10;x++)
		{
			if(tabla[y][x]==1)
			{
				tabla[y][x]=2;
				
			}
		}
	}
	reiniciar_pieza();
}
void Tablero::detectar_colisiones()
{
	for(int y=14; y>=0;y--)
	{
		
		for(int x=0; x<10;x++)
		{
			if(tabla[y][x]==1 && (tabla[y+1][x]==2 || y==14))
			{
				transformar();
			}
		}
	}
}

void Tablero::reiniciar_pieza()
{
	delete F;
	pieza_aleatoria= rand()%5+1;
	F=new Ficha(pieza_aleatoria);
	colocar_ficha();
}
void Tablero::bajar_pieza()
{
	mov_posible(80);
}
void Tablero::detectar_tetris()
{
	int contador=0;
	for(int y=14; y>=0;y--)
	{
		
		for(int x=0; x<10;x++)
		{
			if(tabla[y][x]==2)
			{
				contador++;
				if(contador == 10)
				{
					borra_linea_tetris(y);
					sumar_puntos();
				}
			}
			else
			{
			contador=0;
			}
		}
		contador=0;
	}
}
//borra la fila segun la Y
void Tablero::borra_linea_tetris(int enc_fila)
{
	for(int x=0; x<10;x++)
	{
		tabla [enc_fila][x]=0;
	}
	baja_linea_tetris();
}
//Detecta todos los bloques y los baja 1 sola vez
void Tablero::baja_linea_tetris()
{
	for(int y=14; y>=0;y--)
	{
		
		for(int x=0; x<10;x++)
		{
			if(tabla[y][x]==2 && y<14 && tabla[y+1][x]==0)
			{
				tabla[y][x]=0;
				tabla[y+1][x]=2;
			}
		}
	}
}
void Tablero::sumar_puntos()
{
	sumatoria_de_puntos += 5;;
}
void Tablero::mostrar_puntos()
{
	gotoxy(30,1);
	cout<<"Puntaje: ";
	cout<<sumatoria_de_puntos;
	gotoxy(1,1);
}
void Tablero::detectar_derrota()
{
		
	if(tabla[2][4]==2 || tabla[2][5]==2 || tabla[2][6]==2 )
	{
		encargado=false;
	}
		
}
	
