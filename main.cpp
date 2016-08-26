#include "matriz.h"
#include <iostream>
#include <vector>
using namespace::std;

int main(int argc, char const *argv[])
{
	int menu,filas,columnas;
	char resp;
	vector<matriz> matrices;
	double** matrizB;
	do
	{
		cout<<"1.Agregar\n2.Suma\n3.Resta\n4.Negativa\n5.Multiplicacion\n6.Igules\n7.Diferente\n...";
		cin>>menu;
		switch(menu){
			case 1:
			{
				cout<<"Ingrese las filas: ";
				cin>>filas;
				cout<<"Ingrese las columnas: ";
				cin>>columnas;
				matrizB = new double*[filas];
				for (int i = 0; i < filas; ++i)
				{
					matrizB[i] = new double[columnas];
				}
				int tem;
				for (int i = 0; i < filas; ++i)
				{
					for (int j = 0; j < columnas; ++j)
					{
						cout<<"Ingrese el numero de la posicion i:"<<i<<" j: "<<j<<": ";
						cin>>tem;
						matrizB[i][j] = tem;
					}
				}
				matriz nueva(matrizB,filas,columnas);
				matrices.push_back(nueva);
				break;
			}
			case 2:
			{
				int pos1,pos2;
				cout<<"Ingrese la posicion de la primera matriz: ";
				cin>>pos1;
				cout<<"Ingrese la posicion de la segunda matriz: ";
				cin>>pos2;
				matriz tem((matrices.at(pos1) + matrices.at(pos2)));
				cout<<tem<<endl;
				break;
			}
			case 3:
			{
				int pos1,pos2;
				cout<<"Ingrese la posicion de la primera matriz: ";
				cin>>pos1;
				cout<<"Ingrese la posicion de la segunda matriz: ";
				cin>>pos2;
				matriz tem((matrices.at(pos1) - matrices.at(pos2)));
				cout<<tem<<endl;
				break;
			}
			case 4:
			{				
				int pos1,pos2;
				cout<<"Ingrese la posicion de la primera matriz";
				cin>>pos1;
				-matrices.at(pos1);
				cout<<matrices.at(pos1);
				break;
			}
			case 5:
			{
				int pos1,pos2;
				cout<<"Ingrese la posicion de la primera matriz: ";
				cin>>pos1;
				cout<<"Ingrese la posicion de la segunda matriz: ";
				cin>>pos2;
				break;
			}
			case 6:
			{				
				int pos1,pos2;
				cout<<"Ingrese la posicion de la primera matriz: ";
				cin>>pos1;
				cout<<"Ingrese la posicion de la segunda matriz: ";
				cin>>pos2;
				if ((matrices.at(pos1) == matrices.at(pos2)))
				{
					cout<<"Las matrices son iguales";
				}else{
					cout<<"Las matrices no son iguales";
				}
				break;
			}
			case 7:
			{
				int pos1,pos2;
				cout<<"Ingrese la posicion de la primera matriz: ";
				cin>>pos1;
				cout<<"Ingrese la posicion de la segunda matriz: ";
				cin>>pos2;
				if ((matrices.at(pos1) != matrices.at(pos2)))
				{
					cout<<"Las matrices no son iguales";
				}else{
					cout<<"Las matrices son iguales";
				}
				break;
			}
			case 8:
			{
				break;
			}
			case 9:
			{
				break;
			}
		}
		cout<<"Dese continuar[s/n]: ";
		cin>>resp;
	} while (resp == 's' || resp == 'S');
	return 0;
}