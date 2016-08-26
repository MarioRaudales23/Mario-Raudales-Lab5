#pragma once
#include <iostream>
using std::ostream;
#include <string>
using std::string;


class matriz{
	friend ostream& operator<<(ostream&,const matriz&);
	private:
		double** matrizA;
		int filas,columnas;
	public:
		matriz();
		matriz(int,int);
		matriz(double**,int,int);
		matriz(const matriz&);
		~matriz();
		const matriz operator+(const matriz&)const;
		const matriz operator-(const matriz&)const;
		const matriz& operator-();
		const matriz operator*(const matriz&)const;
		const matriz& operator()()const;
		const matriz& operator--();
		bool operator!=(matriz&);
		bool operator==(matriz&);
		string tostring()const;
};