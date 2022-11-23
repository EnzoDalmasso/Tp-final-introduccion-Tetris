#include "Ficha.h"



Ficha::Ficha(int num_piezas) {
	
	indicador_a_pieza=num_piezas;
	rotada=0;
	
	switch(num_piezas)
	{
	case 1:
		//Ficha Palo 
		for(int y=0; y<4;y++)
		{
			
			for(int x=0;x<4;x++)
			{
				if(x==0)
				{
					ficha[y][x]=1;
				}
				else
				{
					ficha[y][x]=0;
				}
			}
			
		}
		break;
		case 2:
			//Ficha cubo
			for(int y=0; y<4;y++)
			{
				
				for(int x=0;x<4;x++)
				{
					if(x<2 && y<2)
					{
						ficha[y][x]=1;
					}
					else
					{
						ficha[y][x]=0;
					}
				}
				
			}
		break;
	case 3:
		//Ficha Ele
		for(int y=0; y<4;y++)
		{
			
			for(int x=0;x<4;x++)
			{
				if((x<1 && y<3) || (x==1 && y==2))
				{
					ficha[y][x]=1;
				}
				else
				{
					ficha[y][x]=0;
				}
			}
			
		}
		break;
	case 4:
		//Ficha z
		for(int y=0; y<4;y++)
		{
			
			for(int x=0;x<4;x++)
			{
				if((x==0 && y<=1) || (x==1 && (y!=0&& y<=2)))
				{
					ficha[y][x]=1;
				}
				else
				{
					ficha[y][x]=0;
				}
			}
			
		}
		break;
	case 5:
		//Ficha T
		for(int y=0; y<4;y++)
		{
			
			for(int x=0;x<4;x++)
			{
				if((x<=2 && y==0) || (x==1 && y==1))
				{
					ficha[y][x]=1;
				}
				else
				{
					ficha[y][x]=0;
				}
			}
			
		}
		break;
			
	}

		   
}


	
	


int Ficha::devolver_pieza(int y, int x)
{
	return ficha[y][x];
}
void Ficha::rotar()
{
	rotada =! rotada;
}

