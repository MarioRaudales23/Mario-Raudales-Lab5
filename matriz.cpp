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
	matriz nueva(filas,columnas);
	for (int i = 0; i < filas; ++i)
	{
		for (int j = 0; j < columnas; ++j)
		{
				nueva.matrizA[i][j] = (this->matrizA[i][j] + derecha.matrizA[i][j]); 
		}
	}
	return nueva;
}

const matriz matriz::operator-(const matriz& derecha)const{
	matriz nueva(filas,columnas);
	for (int i = 0; i < filas; ++i)
	{
		for (int j = 0; j < columnas; ++j)
		{
				nueva.matrizA[i][j] = (this->matrizA[i][j] - derecha.matrizA[i][j]); 
		}
	}
	return nueva;
}
const matriz& matriz::operator-(){
	for (int i = 0; i < filas; ++i)
	{
		for (int j = 0; j < columnas; ++j)
		{
				this->matrizA[i][j] * -1;
		}
	}
}
const matriz& matriz::operator--(){
	for (int i = 0; i < filas; ++i)
	{
		for (int j = 0; j < columnas; ++j)
		{
				this->matrizA[i][j] * -1;
		}
	}
}
const matriz matriz::operator*(const matriz& derecha)const{
	int fnueva = this->filas;
	int cnueva = derecha.columnas;
	int interno = this->columnas;
	matriz nueva(filas,columnas);
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
}

const matriz& matriz::operator()(){
	matriz nueva(columnas,filas);
	for (int i = 0; i <	columnas; ++i)
	{
		for (int j = 0; j < filas; ++j)
		{
				nueva.matrizA[i][j] = this->matrizA[j][i];
		}
	}
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