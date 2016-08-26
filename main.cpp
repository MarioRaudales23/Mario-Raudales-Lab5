#include "matriz.h"
#include <iostream>
#include <vector>
using namespace::std;

int main(int argc, char const *argv[])
{
	int menu,filas,columnas;
	char resp;
	vector<matriz> matrices;
	vector<matriz> respuesta;
	double** matrizB;
	do
	{
		cout<<"1.Agregar\n2.Suma\n3.Resta\n4.Negativa\n5.Multiplicacion\n6.Igules\n7.Diferente\n8.Transpuesta\n9.Determinante\n...";
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
				int temp;
				for (int i = 0; i < filas; ++i)
				{
					for (int j = 0; j < columnas; ++j)
					{
						cout<<"Ingrese el numero de la posicion i:"<<i<<" j: "<<j<<": ";
						cin>>temp;
						matrizB[i][j] = temp;
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
				respuesta.push_back(tem);
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
				respuesta.push_back(tem);
				cout<<tem<<endl;
				break;
			}
			case 4:
			{				
				int pos1,pos2;
				cout<<"Ingrese la posicion de la primera matriz: ";
				cin>>pos1;
				-matrices.at(pos1);
				respuesta.push_back(-matrices.at(pos1));
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
				if (pos1 < matrices.size() && pos2<matrices.size())
				{
						matriz tem((matrices.at(pos1) * matrices.at(pos2)));
						respuesta.push_back(tem);
						cout<<tem<<endl;
				}
				
				break;
			}
			case 6:
			{				
				int pos1,pos2;
				cout<<"Ingrese la posicion de la primera matriz: ";
				cin>>pos1;
				cout<<"Ingrese la posicion de la segunda matriz: ";
				cin>>pos2;
				if (pos1 < matrices.size() && pos2<matrices.size())
				{
					if ((matrices.at(pos1) == matrices.at(pos2)))
					{
						cout<<"Las matrices no son iguales";
					}else{
						cout<<"Las matrices son iguales";
					}
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
				if (pos1 < matrices.size() && pos2<matrices.size())
				{
					if ((matrices.at(pos1) != matrices.at(pos2)))
					{
						cout<<"Las matrices no son iguales";
					}else{
						cout<<"Las matrices son iguales";
					}
				}
				
				break;
			}
			case 8:
			{
				int pos1,pos2;
				cout<<"Ingrese la posicion de la primera matriz: ";
				cin>>pos1;
				if (pos1 < matrices.size())
				{
					matrices.at(pos1)();
					respuesta.push_back((matrices.at(pos1)()));
					cout<<matrices.at(pos1)();
				}
				break;
			}
			case 9:
			{
				int pos1,pos2;
				cout<<"Ingrese la posicion de la primera matriz: ";
				cin>>pos1;
				--matrices.at(pos1);
				cout<<"El determinante es: "<<--matrices.at(pos1);
				break;
			}
		}
		cout<<"Desea continuar[s/n]: ";
		cin>>resp;
	} while (resp == 's' || resp == 'S');
	return 0;
}