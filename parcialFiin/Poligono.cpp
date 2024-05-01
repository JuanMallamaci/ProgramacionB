/*
 * Poligono.cc
 *
 *  Created on: 18/03/2024
 *      Author: adrian
 */

#include <iostream>
#include <math.h>
#include "Poligono.hpp"
using namespace std;
bool IgDouble(const double& n1, const double& n2);
void OrdenaDouble( double* n, const int& cantVert);

Poligono::Poligono()
{
	cout << "En constructor de Poligono sin argumentos" << endl;
	cantVert=0;
	vert = NULL;
}

Poligono::Poligono( int n, const Complejo pto[] )
{
	cantVert=n;
	vert = new Complejo[cantVert];


	//cout << "En constructor de Poligono, this= " << (this)  << " y direccion de vert= " << (vert) << ", con vertices:" << endl;
	for( int i=0; i < cantVert; i++ )
	{
		vert[i] = pto[i];
	}
}
Poligono::~Poligono()
{
	cout << "En destructor de Poligono con cantVert=" << cantVert << ", liberara mem de vert= " << vert << endl;
	if( cantVert > 0 )
		delete []vert;
}
//
std::ostream& operator<< (std::ostream& os, const Poligono& p)
{
	for( int i = 0; i < p.GetCantVert(); i++)
	{
		os << p.GetVert(i) << " ";
	}
	return os;
}
//
std::istream& operator>> (std::istream& in, Poligono& p)
{
	Complejo aux(0,0);

	for ( int i = 0; i < p.GetCantVert(); i++ )
	{
		in >> aux;
		p.SetVert(aux, i);
	}
}

// **** Triangulo ****
Triangulo::Triangulo( const Complejo pto[]):Poligono( 3, pto )
{
	cout << "En constructor de Triangulo" << endl;
		//valida que es un triangulo
		//evalua la propiedad que la suma de dos lados de un triangulo es mayor al restante
		double dist[3] = {vert[0].Distancia(pto[1]), vert[0].Distancia(pto[2]), vert[1].Distancia(pto[2])};
		if( !((dist[0] + dist[1] > dist[2]) && (dist[0] + dist[2] > dist[1]) && (dist[1] + dist[2] > dist[0])) )
		{
			throw int( ERROR_NO_TRIANGULO );
		}
}
Triangulo::~Triangulo()
{
	cout << "En destructor Triangulo" << endl;
}
double Triangulo::Area() const
{
	//como el area del paralelogramo limitado en un extremo por dos vectores coincide con la norma del producto
	//vectorial de los mismos, el area del triangulo es la mitad de la del paralelogramo
	//Estas operaciones pueden hacerse mediante el uso de metodos de bibliotecas, pero para iniciar el estudio,
	//se desarrollaran completamente, considerando los puntos como vectores en el plano complejo, luego los
	//vectores a considerar seran los vectores diferencia (vert[1] - vert[0]), (vert[2] - vert[0])

	Complejo vecDif[2] = { ( vert[1] - vert[0] ), ( vert[2] - vert[0] ) };
	return ( abs( vecDif[0].ProdVectorial(vecDif[1]) ) /2.0f );
}
double Triangulo::Perimetro() const
{
	//el perimetro lo evalua como la suma de las distancias entre los vertices
	double perim( vert[0].Distancia(vert[1]) +
	             vert[1].Distancia(vert[2]) +
	             vert[2].Distancia(vert[0]) );
	return perim;
}
// **** Rectangulo ****
Rectangulo::Rectangulo( const Complejo pto[]):Poligono( 4, pto )
{
	cout << "En constructor de Rectangulo" << endl;
	//Valida rectangulo
	//calcula la longitud de dos lados y la diagonal, compara la diagonal con la hipotenusa calculada con los otros dos lados calculados

	double dist[] = { vert[0].Distancia(vert[1]), vert[0].Distancia(vert[2]), vert[0].Distancia(vert[3]) };
	OrdenaDouble(dist, 3);
	double h = sqrt(dist[0] * dist[0] + dist[1] * dist[1]);

	if( !(IgDouble(h, dist[2])) || IgDouble(h, 0)  )
		{
			throw int(ERROR_NO_RECTANGULO);
		}
	}
Rectangulo::~Rectangulo()
{
	cout << "En destructor Rectangulo" << endl;
}
double Rectangulo::Area() const
{
	//como el area del rectangulo es igual al producto de base por su altura, se evaluan las distancias de
	//un vertice a los tres restantes y se multiplican las dos distancias menores

		double dist[] = { vert[0].Distancia(vert[1]), vert[0].Distancia(vert[2]), vert[0].Distancia(vert[3])};
		OrdenaDouble(dist, 3);
	return ( dist[0] * dist[1] );
}
double Rectangulo::Perimetro() const
{
	//el perimetro lo evalua como la suma de las distancias entre los vertices
		double dist[] = { vert[0].Distancia(vert[1]), vert[0].Distancia(vert[2]), vert[0].Distancia(vert[3]) };
		OrdenaDouble( dist, 4 );
	return ( dist[0] + dist[1] ) * 2;
}
// **** Cuadrado ****
Cuadrado::Cuadrado( const Complejo pto[]):Rectangulo( pto )
{
	cout << "En constructor de Cuadrado" << endl;
	//verifica que los vertices formen un cuadrado tomando las distancias entre un vertice y los otros 3
	//luego de ordenar, las dos distancias menores deben ser iguales entre si y la tercera sqrt(2) * distancia menor
	double dist[3] = {vert[0].Distancia(vert[1]),vert[0].Distancia(vert[2]), vert[0].Distancia(vert[3])};
		OrdenaDouble(dist, 3);

		if( !( IgDouble(dist[0], dist[1]) ) || !( IgDouble(dist[2], (sqrt(2)*dist[0]))) || dist[0] == 0 )
		{
			throw int( ERROR_NO_CUADRADO );
		}
	}
 Cuadrado::~Cuadrado()
{
	cout << "En destructor Cuadrado" << endl;
}
double Cuadrado::Area() const
{
	//como el area del cuadrado se puede evaluar como la del rectangulo
	return(Rectangulo::Area());
}
//
double Cuadrado::Perimetro() const
{
//como el perimetro del cuadrado se puede evaluar como el del rectangulo
	return(Rectangulo::Perimetro());
}
//auxiliar para evaluar igualdad o diferencia entre doubles
bool IgDouble(const double& n1, const double& n2)
{
	double limInf( n1 / 1000.0 ), dif( n1 - n2 );

	return ( abs(dif) <= limInf);
}
//Funcion auxiliar para ordenar doubles de menor a mayor
void OrdenaDouble( double* n, const int& cantVert)
{
	for( int k=0; k < cantVert; k++ )
	{
		for( int i=k+1; i < (cantVert-1); i++ )
		{
			if( n[i] < n[k] )
			{
				double nAux= n [k];
				n[k] = n[i];
				n[i] = nAux;
			}
		}
	}
}
