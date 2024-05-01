/*
 * Poligono.h
 *
 *  Created on: 18/03/2024
 *      Author: adrian
 */

#ifndef HERSOBRECARGA_H_
#define HERSOBRECARGA_H_
//metodo para carga de rect triang sobra friend
enum {ERROR_NO_CUADRADO, ERROR_NO_RECTANGULO, ERROR_NO_TRIANGULO};

#include "Complejo.hpp"
/**
 * La clase poligono es una clase abstracta que toma un arreglo de vertices tipo Complejo,
 * calcula el Area y perimetro con los datos leidos
 */
class Poligono
{
protected:
	Complejo *vert; /// vertices del poligono, en principio, no se sabe cuantos son
	int cantVert;
public:
	 /**
	  * @fn Poligono()
	  * @brief
	  * Construye el poligono instanciando NULL , cero
	  */
	Poligono(); //constructor por defecto, sin argumentos
	/**
	 *@fn Poligono( int n, const Complejo pto[] );
	 *@brief
	 *Construye un Poligno ordenando sus vertices de forma creciente
	 *@param n Cantidad de vertices
	 *@param pto  Arreglo con los pares coordenados de los vertices de la figura
	 */
	Poligono( int n, const Complejo pto[] ); //constructor con argumentos
	/**
	 * Destructor de la clase
	 */
	virtual ~Poligono();
	virtual double Area() const=0;
	virtual double Perimetro() const=0;
	/**
	 * @fn int GetCantVert() const {return cantVert;}
	 * @brief
	 * Externaliza la cantidad de vertices del Poligono
	 */
	int GetCantVert() const {return cantVert;}
	/**
	 * @fn int GetVert() const {return cantVert;}
	 * @brief
	 * Externaliza los vertices del Poligono
	 */
	Complejo GetVert(int n) const {return vert[n];}
	/**
	 * @fn void SetVert(const Complejo&)
	 * @brief
	 * Modifica el valor de un vertice;
	 * @param c Nuevo valor del vertice
	 * @param n Numero de vertice
	 */
	void SetVert( const Complejo& c, const int& n) {vert[n] = c;};

};
/**
 * @fn std::ostream operator <<&(std::ostream&, const Poligono&)
 * @brief
 * Escritura de un vertices de un Poligono
 * @param os stream de salida
 * @param p Poligono a escribir
 * @return stream de salida
 */
std::ostream& operator<< (std::ostream& os, const Poligono& p);
/**
 * @fn std::istream operator >>&(std::istream&, Complejo&)
 * @brief
 * Lectura de vertices de un poligono forma (real,imag)
 * @param in stream de entrada
 * @param p poligono
 * @return stream de entrada
 */
std::istream& operator>> (std::istream& in, Poligono& p);

//clase Triangulo, deriva de Poligono
class Triangulo:public Poligono
{
public:
	/**
	 * @fn Triangulo( const Complejo pto[])
	 * @brief
	 * Evalua si es triangulo por suma de lados
	 */
	Triangulo( const Complejo pto[]);
	virtual ~Triangulo();
	/**
	 * @fn 	virtual double Area() const
	 * @brief
	 * Calcula la distancia de un vertice con respecto
	 * a los otros dos y luego calcula el producto escalar
	 * con esas distancias dividido dos
	 */
	virtual double Area() const;
	/**
	 * @fn virtual double Perimetro() const
	 * @brief
	 * Suma la distancia entre todos sus vertices
	 */
	virtual double Perimetro() const;
};
//
//clase Rectangulo, deriva de Poligono
class Rectangulo:public Poligono
{
public:
	/**
	 * @fn Rectangulo( const Complejo pto[])
	 * @prief
	 * Valida si es rectangulo con la longitud de los lados
	 */
	Rectangulo( const Complejo pto[]);
	virtual ~Rectangulo();
	/**
	 * @fn virtual double Area() const
	 * @brief
	 * Calcula distancias de 3 vertices respecto a uno
	 * y multiplica las dos menores
	 */
	virtual double Area() const;
	/**
	 * @fn virtual double Perimetro() const
	 * @brief
	 * Suma la distancias entre todos su vertices
	 */
	virtual double Perimetro() const;
};
//
//clase Cuadrado, deriva de Rectangulo
class Cuadrado:public Rectangulo
{
public:
	/**
	 * @fn Cuadrado( const Complejo pto[])
	 * @brief
	 * Calcula distancias de 3 vertices respecto a uno
	 * evalua si es cuadrado y decuelve error si no lo es
	 */
	Cuadrado( const Complejo pto[]);
	virtual ~Cuadrado();
	/**
	 * @fn virtual double Area() const
	 * @brief
	 * Evalua area como rectangulo
	 */
	virtual double Area() const;
	/**@fn virtual double Perimetro() const
	 * @brief
	 * Evalua perimetro como rectangulo
	 */
	virtual double Perimetro() const;
};
#endif // HERSOBRECARGA_H_ 
