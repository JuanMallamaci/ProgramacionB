/*
 * Complejo.hpp
 *
 *  Created on: 27 mar. 2024
 *      Author: alumno
 */

#ifndef COMPLEJO_HPP_
#define COMPLEJO_HPP_

#include <iostream>
#include <exception>
#include <cmath>
/**
 * La calse complejo toma double y crea un punto con parte entera y real
 */
class Complejo
{
	private:
		double real;
		double imag;
	public:
		// Constructores
		/**
		 * @fn  Complejo()
		 * @brief
		 * Construye el complejo con valores cero cero
		 */
		Complejo();

		/**
		 * @fn  Complejo(const double&, const double=0.0)
		 * @brief
		 * Construye el complejo con parte imagnaria en cero
		 * @param re Parte real del numero complejo
		 * @param im Parte imaginaria del numero complejo
		 */
		Complejo(const double& re, const double im=0.0);

		/**
		* @fn  Complejo(const Complejo&)
		 * @brief
		 * Construye una copia de un complejo
		 * @param c Complejo a copiar
		 */
		Complejo(const Complejo&c);

		// SetThings
		/**
		 * @fn void SetData(const double& re, const double& im)
		 * @brief
		 * Sobrecarga la parte real e imaginaria del Complejo
		 * @param re parte real
		 * @param im parte imaginaria
		 */
		void SetData(const double& re, const double& im);
		/**
		 * @fn void SetData(const Complejo& c)
		 * @brief
		 * Copia un Complejo en otro
		 * @param c Complejo a copiar
		 */
		void SetData(const Complejo& c);
		/**
		 * @fn void SetReal(const double&);
		 * @brief
		 * Sobrecarga la parte real del complejo
		 * @param re parte real
		 */
		void SetReal(const double&);
		/**
		 * @fn void SetImag(const double&);
		 * @brief
	     * Sobrecarga la parte imaginaria del complejo
		 * @param im parte imaginaria
		 */
		void SetImag(const double&);

		// GetThings
		/**
		 * @fn double GetReal() const{return real;}
		 * @brief
		 * Externaliza la parte real del complejo
		 * @return double real
		 */
		double GetReal() const{return real;}

		/**
		 * @fn double GetImag() const{return imag;}
		 * @brief
		 * Externaliza la parte imaginaria del complejo
		 * @return double imag
		 */
		double GetImag() const{return imag;}

		// Sobrecarga de operadores aritmetico

		/**
		 * @fn Complejo operator +(const Complejo&)
		 * @brief
		 * Subrecarga de operador suma, suma entre compeljos
		 * @param a Numero complejo
		 * @return Suma entre dos complejos
		 */
		Complejo operator+ (const Complejo&) const;

		/**
		 * @fn Complejo operator +(const double&)
		 * @brief
		 * Sobrecarga de operador suma, suma a la parte real del numero complejo
		 * @param re Cantidad a sumar al numero complejo
		 * @return Numero complejo aumentado
		 */
		Complejo operator+ (const double&) const;

		/**
		 * @fn Complejo operator -(const Complejo&)
		 * @brief
		 * Sobrecarga de opeardor resta, resta entre complejos
		 * @param a Numero complejo a restar
		 * @return Complejo resultatnte de la suma entre ambos
		 */
		Complejo operator- (const Complejo&) const;
		/**
		 * @fn Complejo operator* (const Complejo&);
		 * @brief
		 * Sobrecarga de operador producto, producto entre complejos
		 * @param c Numero Complejo a multiplicar
		 * @return Resultado del producto
		 */
		Complejo operator* (const Complejo&) const;
		/**
		 * @fn double ProdEscalar (const Complejo&);
		 * @brief
		 * Sobrecarga de producto escalar, producto punto entre los vectores complejo
		 * @param c Numero complejo a multiplicar
		 * @return Resultado del producto
		 */
		double ProdEscalar (const Complejo&);
		/**
		 * @fn double ProdVectorial (const Complejo& c);
		 * @brief
		 * Calcula un producto vectoreal entre dos complejos
		 * @param c complejo de operacion
		 * @return Resultado
		 */
		double ProdVectorial (const Complejo& c);
		/**
		* @fn Complejo operator/ (const Complejo&);
		* @brief
		* Sobrecarga de operador division, division entre complejos
		* @param c denominador del cociente
		* @return Resultado de la division
		*/
		Complejo operator/ (const Complejo&) const;
		/**
		 * @fn Complejo& operator= (const Complejo&);
		 * @brief
		 * Sobrecarga de operador asignacion, asigna nuevos valores reales e imaginarios
		 * @param c complejo a comparar
		 * @return Complejo actualizado
		 */
		Complejo& operator= (const Complejo&);
		/**
		 * @fn bool operator== (const Complejo&);
		 * @brief
		 * Sobrecarga de operador comparacion, verifica si dos complejos son iguales
		 * @param complejo a comparar
		 * @return Verdadero cuando sean distintos
		 */
		bool operator== (const Complejo&) const;
		/**
		 * @fn bool operator!= (const Complejo&);
		 * @brief
		 * Sobrecarga de operador comparacion, verifica si dos complejos son distintos
		 * @return Verdadero cuando sean iguales
		 */
		bool operator!= (const Complejo&) const;
		/**
		 * @fn bool operator >(const Complejo&)
		 * @brief
		 * Sobrecarga operador de mayor
		 * @param c Complejo
		 * @return Verdadero cuando c es mayor
		 */
		bool operator> (const Complejo& c) const;
		/**
		 * @fn bool operator <(const Complejo&)
		 * @brief
		 * Sobrecarga de operador de mayor
		 * @param c Complejo
		 * @return Verdadero cuando c es menor
		 */
		bool operator< ( const Complejo& c ) const;
		/**
		 * @fn double Distancia(const Complejo&)
		 * @brief
		 * Calcula la distancia pitagorica entre dos puntos del plano complejo
		 * @param Numero complejo
		 * @return Distancia entre los dos puntos
		 */
		double Distancia(const Complejo&) const;
};

/**
 * @fn std::ostream operator <<&(std::ostream&, const Complejo&)
 * @brief
 * Escritura de numero complejo por stream en formato (real, imag)
 * @param os Stream de salida
 * @param c Numero complejo a escribir
 * @return stream de salida
*/
std::ostream& operator<< (std::ostream& os, const Complejo& c);

/**
 * @fn std::istream operator >>&(std::istream&, Complejo&)
 * @brief
 * Lectura de numero complejo por stream en formato (real, imag)
 * @param in Stream de entrada
 * @param c Numero complejo a leer
 * @return stream de entrada
 */
std::istream& operator>> (std::istream& in, Complejo& c);

#endif // COMPLEJO_HPP_
