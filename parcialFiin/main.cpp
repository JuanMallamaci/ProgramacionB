/*
 * main.cpp
 *
 *  Created on: 27 mar. 2024
 *      Author: alumno
 */

#include "Complejo.hpp"
#include "Poligono.hpp"

#include <iostream>
#include <fstream>
using namespace std;


void LeePuntos(std::istream& in, const int& cant, Complejo pto[]);
void EjecutaCuadrado(Complejo pt[], const char ruta[]);
void EjecutaRectangulo(Complejo pt[], const char ruta[]);
void EjecutaTriangulo(Complejo pt[], const char ruta[]);
int main()
{
	Complejo pTriang[3];
	Complejo pRect[4];
	Complejo pCuad[4];
	int opcion=0, t=0;
	char flag;
	string ruta;
	fstream arch;

	while(opcion != 99)
	{
		switch (opcion)
		{
		case 0:
			cout << " Desde donde quiere leer los vertices del Cuadrado A(archivo) o B(teclado): " << endl;
			cin >> (flag);
			switch (flag)
			{
				case 'A':
					opcion = 10;
					break;
				case 'B':
					opcion = 20;
					break;
			}
			t=4;
			break;
		case 10:
			opcion=1;
			try
			{
			cout << "Ingrese el nombre del archivo: " << endl;
			cin >> ruta;
			ifstream arch(ruta);
			if ( !arch.is_open() )
			{
				cerr << "Error abriendo archivo." << endl;
				break;
			}
			LeePuntos(arch, t, pCuad);
			arch.close();
			 }
			catch ( const char *msj)
			{
				cerr << msj << endl;
				opcion = 0;
			}
				break;
		case 20:
			opcion = 1;
			try
			{
			cout << "Ingrese vertices (real,imaginario) : " << endl;
			LeePuntos(cin, t, pCuad);
			}
			catch (const char *msj)
			{
			     cerr << msj << endl;
				 opcion = 0;
			}
			break;

		case 1:
			cout << " Desde donde quiere leer los vertices del Rectangulo A(archivo) o B(teclado): " << endl;
			cin >> (flag);
			switch (flag)
				{
					case 'A':
					opcion = 11;
						break;
					case 'B':
					opcion = 21;
						break;
				}
			t=4;
				break;
		case 11:
			opcion = 2;
			try
			{
			cout << "Ingrese el nombre del archivo: " << endl;
			cin >> ruta;
			ifstream arch(ruta);
			if ( !arch.is_open() )
			{
				cerr << "Error abriendo archivo." << endl;
				break;
			}
			LeePuntos(arch, t, pRect);
			arch.close();
			}
			catch ( const char *msj)
			{
				cerr << msj << endl;
				opcion = 1;
			}

			break;
		case 21:
			opcion = 2;
			try
			{
			cout << "Ingrese los vertices (real,imaginario) : " << endl;
			LeePuntos(cin, t, pRect);
			}
			catch (const char *msj)
			{
			     cerr << msj << endl;
				 opcion = 1;
			}
			break;
		case 2:
			cout << " Desde donde quiere leer los vertices del Triangulo A(archivo) o B(teclado): " << endl;
			cin >> (flag);
			switch (flag)
				{
					case 'A':
					opcion = 12;
						break;
					case 'B':
					opcion = 22;
						break;
				}
						t=3;
				break;
		case 12:
			opcion = 99;
			try
			{
			cout << "Ingrese el nombre del archivo: " << endl;
			cin >> ruta;
			arch.open (ruta);
			if ( !arch.is_open() )
				{
					cerr << "Error abriendo archivo." << endl;
					break;
				}
			LeePuntos(arch, t, pTriang);
			}
			catch (const char *msj)
			{
				cerr << msj << endl;
				 opcion = 2;
			}
			break;
		case 22:
			opcion = 99;
			try
			{
			cout << "Ingrese vertices : " << endl;
			LeePuntos(cin, t, pTriang);
			}
			catch (const char *msj)
			{
				cerr << msj << endl;
				opcion = 2;
			}
			break;
		}
	}

	try
	{
		EjecutaCuadrado(pCuad, "Cuadrado.dat");
	}
	catch ( const int msj)
	{
		if (ERROR_NO_CUADRADO == msj)
			cerr << "No es cuadrado." << endl;
	}

	try
	{
		EjecutaRectangulo(pRect, "Rectangulo.dat");
	}
	catch ( const int msj)
	{
		if ( ERROR_NO_RECTANGULO  == msj )
			cerr << "No es cuadrado." << endl;
	}
	try
	{
		EjecutaTriangulo(pTriang, "Triangulo.dat");
	}
	catch ( const int msj)
	{
		if ( ERROR_NO_TRIANGULO == msj)
			cerr << "No es cuadrado." << endl;
	}




	return 0;
}

void LeePuntos( istream& in, const int& cant, Complejo pto[] )
{

		for( int i = 0; i < cant; i ++)
		{
			in >> pto[i];
		}
}

void EjecutaCuadrado(Complejo pt[], const char ruta[])
{
	ofstream arch(ruta);

	try
	{
		Cuadrado C1(pt);

		cout << "[ " << C1 << " ] Area Cuad: " << C1.Area()<< " Perimetro Cuad: " << C1.Perimetro() << endl;

		if( ! arch.is_open())
		{
			cerr << "Error abriendo archivo." << endl;
			return;
		}
		arch << C1 << endl <<  C1.Area() << " " << C1.Perimetro() << endl;
		arch.close();
	}
	catch(const int msj)
	{
		if( msj == ERROR_NO_CUADRADO )
		{
			cerr << "Los puntos no corresponden a un cuadrado." << endl;
		}
	}
}

void EjecutaRectangulo(Complejo pt[], const char ruta[])
{
	ofstream arch(ruta);

	try
	{
		Rectangulo R1(pt);

		cout << "[ " << R1 << " ] Area Rec: " << R1.Area()<< " Perimetro Rec: " << R1.Perimetro() << endl;

		if( ! arch.is_open())
		{
			cerr << "Error abriendo archivo." << endl;
			return;
		}
		arch << R1 << endl <<  R1.Area() << " " << R1.Perimetro() << endl;
		arch.close();
	}
	catch(const int msj)
	{
		if( msj == ERROR_NO_RECTANGULO)
		{
			cerr << "Los puntos no corresponden a un reactangulo." << endl;
		}
	}
}

void EjecutaTriangulo(Complejo pt[], const char ruta[])
{
	ofstream arch(ruta);

	try
	{
		Triangulo T1(pt);

		cout << "[ " << T1 << " ] Area Tria: " << T1.Area()<< " Perimetro Tria: " << T1.Perimetro() << endl;

		if( ! arch.is_open())
		{
			cerr << "Error abriendo archivo." << endl;
			return;
		}
		arch << T1 << endl <<  T1.Area() << " " << T1.Perimetro() << endl;
		arch.close();
	}
	catch(const int msj)
	{
		if( msj == ERROR_NO_TRIANGULO )
		{
			cerr << "Los puntos no corresponden a un triangulo." << endl;
		}
	}
}

