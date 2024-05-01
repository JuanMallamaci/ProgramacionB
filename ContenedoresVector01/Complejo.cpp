/*
 * Complejo.cpp
 *
 *  Created on: 27 mar. 2024
 *      Author: alumno
 */

#include "Complejo.hpp"
#include <cmath>
#include <iostream>
// constructor por defecto
Complejo::Complejo()
{
	real = 0.0;
	imag = 0.0;
}
// constructor con argumentos
Complejo::Complejo( const double& re, const double im):real(re),imag(im){}
// constructor de copia
Complejo::Complejo(const Complejo& c)
{
	*this = c;
}
//
void Complejo::SetData( const double& re, const double& im )
{
	real = re;
	imag = im;
}
//
void Complejo::SetData(const Complejo& c)
{
	*this = c;
}
void Complejo::SetReal(const double& re)
{
	real = re;
}
void Complejo::SetImag(const double& im)
{
	imag = im;
}
// operador miembro + sobrecargado
Complejo Complejo::operator+ (const Complejo &a) const
{
	Complejo suma;
	suma.real = real + a.real;
	suma.imag = imag + a.imag;
	return suma;
}
// operador miembro + sobrecargado
Complejo Complejo::operator+ (const double &re) const
{
	Complejo suma;
	suma.real = real + re;
	suma.imag = imag;
	return suma;
}
// operador miembro - sobrecargado
Complejo Complejo::operator- (const Complejo &a) const
{
	Complejo resta;
	resta.real = real - a.real;
	resta.imag = imag - a.imag;
	return resta;
}
//
Complejo Complejo::operator* (const Complejo& c) const
{
	Complejo prod;

	prod.real = (real * c.real - imag * c.imag);
	prod.imag =(real * c.imag + imag * c.real);
	return prod;
}
//
Complejo Complejo::operator/ (const Complejo& c) const
{
	Complejo div;

	double den = (c.real * c.real) + (c.imag * c.imag);

	if (den == 0)
	{
		throw "Error division por cero";
	}
	Complejo num =(*this) * Complejo(c.real,-c.imag);
	div.real = (num.real)/den;
	div.imag = (num.imag)/den;
	return div;
}
//
double Complejo::ProdEscalar (const Complejo& c)
{
	double prod( (real * c.real) + (imag * c.imag) );
	return prod;
}
double Complejo::ProdVectorial (const Complejo &c)
{
	double prod( (real * c.imag) - (imag * c.real) );
	return prod;
}
//
Complejo& Complejo::operator= (const Complejo& c)
{
	real = c.real;
	imag = c.imag;
	return *this;
}
//
bool Complejo::operator== (const Complejo& c) const
{
	double dif(0);
	bool condReal(false), condImag(false);

	if((dif = (real - c.GetReal())) < 0)
	{
		dif = -dif;
	}

	condReal = dif < (real / 1000);

	if((dif = (imag- c.GetImag())) < 0)
	{
		dif = -dif;
	}
	condImag = dif < (imag / 1000);

	return (condReal && condImag);
}
//
bool Complejo::operator!= (const Complejo&c) const
{
	return !(*this == c);
}
//
bool Complejo::operator> (const Complejo& c) const
{
	double dif(0);
	Complejo a(0,0);

	dif = c.Distancia( a ) - this->Distancia( a );

	return (dif < ( 0 - c.Distancia(a) / 1000) );
}
//
bool Complejo::operator< (const Complejo& c) const
{
	return ( c > *this );
}
//
double Complejo::Distancia(const Complejo& c) const
{
	double dist(0.0);
	double difR( real - c.real );
	double difImg( imag - c.imag );

	dist = sqrt( difR * difR + difImg * difImg );
	return dist;
}
//
std::ostream& operator<< (std::ostream& os, const Complejo& c)
{
	os << "(" << c.GetReal() << ", " << c.GetImag() << ")";
	return os;
}

std::istream& operator>> (std::istream& is , Complejo& c)
{
	char ch('a');

	is >> ch;
	if(ch!='('){
		throw "Formato de dato incorrecto";
	}
	double d1;
	is >> d1;
	c.SetReal(d1);
	is >> ch;

	if(ch!=',')
	{
		throw "Formato de dato incorrecto";
	}

	is >> d1;
	c.SetImag(d1);
	is >> ch;
	if(ch!=')')
	{
		throw "Formato de dato incorrecto";
	}
		return is;
}
