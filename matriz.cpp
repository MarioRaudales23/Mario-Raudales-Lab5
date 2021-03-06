#include "matriz.h"
#include <iostream>
using std::ostream;
#include <string>
using std::string;
#include <sstream>
using std::stringstream;

matriz::matriz(){
}
matriz::matriz(const matriz& derecha){
	int fil = derecha.filas;
	int col = derecha.columnas;
	this->filas = fil;
	this->columnas = col;
		matrizA = new double*[fil];
	for (int i = 0; i < fil; ++i)
	{
		matrizA[i] = new double[col];
	}
	for (int i = 0; i < fil; ++i)
	{
		for (int j = 0; j < columnas; ++j)
		{
			this->matrizA[i][j] = derecha.matrizA[i][j];
		}
	}
}
matriz::matriz(int fil,int col){
	this->filas = fil;
	this->columnas = col;
	matrizA = new double*[fil];
	for (int i = 0; i < fil; ++i)
	{
		matrizA[i] = new double[col];
	}
}
matriz::matriz(double** matri,int fil,int col){
	this->filas = fil;
	this->columnas = col;
	matrizA = new double*[fil];
	for (int i = 0; i < fil; ++i)
	{
		matrizA[i] = new double[col];
	}
	for (int i = 0; i < fil; ++i)
	{
		for (int j = 0; j < columnas; ++j)
		{
			this->matrizA[i][j] = matri[i][j];
		}
	}
}
matriz::~matriz(){
	for (int i = 0; i < filas; ++i)
	{
		delete[] matrizA[i];
	}
	delete matrizA;
}
ostream& operator<<(ostream& out,const matriz& r){
	out<<r.tostring();
	return out;
}

string matriz::tostring()const{
	stringstream matrix;
	for (int i = 0; i < this->filas; ++i)
	{
		for (int j = 0; j < this->columnas; ++j)
		{
			matrix<<"["<<matrizA[i][j]<<"]";
		}
		matrix<<"\n";
	}
	return matrix.str();
}

const matriz matriz::operator+(const matriz& derecha)const{
	if (this->filas == derecha.filas && this->columnas == derecha.columnas)
	{
		matriz nueva(filas,columnas);
		for (int i = 0; i < filas; ++i)
		{
			for (int j = 0; j < columnas; ++j)
			{
					nueva.matrizA[i][j] = (this->matrizA[i][j] + derecha.matrizA[i][j]); 
			}
		}
		return nueva;
	}else{
		std::cout<<"No tienen el mismo tamaño";
	}
}
	

const matriz matriz::operator-(const matriz& derecha)const{
	if (this->filas == derecha.filas && this->columnas == derecha.columnas)
	{
		matriz nueva(filas,columnas);
		for (int i = 0; i < filas; ++i)
		{
			for (int j = 0; j < columnas; ++j)
			{
					nueva.matrizA[i][j] = (this->matrizA[i][j] - derecha.matrizA[i][j]); 
			}
		}
		return nueva;
	}else{
		std::cout<<"No tienen el mismo tamaño";
	}
}
const matriz& matriz::operator-(){
	for (int i = 0; i < this->filas; ++i)
	{
		for (int j = 0; j < this->columnas; ++j)
		{
				this->matrizA[i][j] *= -1;
		}
	}
}
const int matriz::operator--(){
	if (this->filas == 3 && this->columnas==3)
	{
		return (((matrizA[0][0]*matrizA[1][1]*matrizA[2][2])+(matrizA[0][1]*matrizA[1][2]*matrizA[2][0])+(matrizA[0][2]*matrizA[1][0]*matrizA[2][1]))-(matrizA[2][0]*matrizA[1][1]*matrizA[0][2])-(matrizA[2][1]*matrizA[1][2]*matrizA[0][0])-(matrizA[2][2]*matrizA[1][0]*matrizA[0][1]));
	}else if (this->filas == 2 && this->columnas==2)
	{
		return (matrizA[0][0]*matrizA[1][1]) - (matrizA[0][1]*matrizA[1][0]);
	}
}
const matriz matriz::operator*(const matriz& derecha)const{
	int fnueva = this->filas;
	int cnueva = derecha.columnas;
	int interno = this->columnas;
	if (this->columnas == derecha.filas)
	{
		matriz nueva(fnueva,cnueva);
		for (int i = 0; i < fnueva; ++i)
		{
			for (int j = 0; j < cnueva; ++j)
			{
				for (int k = 0; k < interno; ++k)
				 {
				 	nueva.matrizA[i][j] += this->matrizA[i][k] * derecha.matrizA[k][j];
				 } 
			}
		}
		return nueva;
	}else{
		std::cout<<"La matrices no se pueden multiplicar";
	}
	
	
}

const matriz matriz::operator()()const{
	matriz nuevax(this->columnas,this->filas);
	for (int i = 0; i <	this->columnas; ++i)
	{
		for (int j = 0; j < this->filas; ++j)
		{
				nuevax.matrizA[i][j] = this->matrizA[j][i];
		}
	}
	return nuevax;
}
bool matriz::operator==(matriz& derecha){
	int tama = 0;
	if (this->filas==derecha.filas && this->columnas==derecha.columnas)
	{
		int mult = filas * columnas;
		for (int i = 0; i < filas; ++i)
		{
			for (int j = 0; j < columnas; ++j)
			{
				if (this->matrizA[i][j] == derecha.matrizA[i][j])
				{
					tama++;
				}
			}
		}
		if (tama == mult)
		{
			return true;
		}else{
			return false;
		}
	}else{
		return false;
	}
}
bool matriz::operator!=(matriz& derecha){
	int tama = 0;
	if (this->filas==derecha.filas && this->columnas==derecha.columnas)
	{
		for (int i = 0; i < filas; ++i)
		{
			for (int j = 0; j < columnas; ++j)
			{
				if (this->matrizA[i][j] != derecha.matrizA[i][j])
				{
					tama++;
				}
			}
		}
		if (tama <= 1)
		{
			return true;
		}else{
			return false;
		}
	}else{
		return false;
	}
}