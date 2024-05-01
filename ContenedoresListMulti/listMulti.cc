/*
 * Template/listMulti.cc
 *
 *  Created on: 26/08/2017
 *      Author: adrian
 *  Utiliza arrays bidimensionales template auto dimensionables
 *  a partir de los datos de archivos
 */


#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <complex>

enum{ ERROR_ARCHIVO, ERROR_NRO_FILAS_COL };

template <class T>
void LeeListBidim( const std::string& nameFile, std::list< std::list<T> >& lext )
{
	std::ifstream ifs(nameFile.c_str());
	std::string linea;

	if( !ifs )
	{
		//cout << "Disparara ERROR_ARCHIVO= " << ERROR_ARCHIVO << " con archivo= " << nameFile.c_str() << endl;
		throw( int(ERROR_ARCHIVO));
	}
	//
	getline( ifs, linea);
	while( !ifs.eof() )
	{
		std::istringstream iss( linea );
		T tAux;
		std::list<T> lAux;
		char cAux;
		cAux = iss.get();
		while( !iss.eof() )
		{
			iss.putback(cAux);
			iss >> tAux;
			lAux.push_back(tAux);
			cAux = iss.get();
		}
		lext.push_back(lAux);
		getline( ifs, linea);
	}
	ifs.close();
}


template <class T>
std::list< std::list<T> > operator *( std::list< std::list<T> >& m1, std::list< std::list<T> >& m2)
{
	//en sentencias como la siguiente, se necesita typename porque std::list<std::list<T> > tiene alcance dependiente de T
	typename std::list< std::list<T> >::iterator ii1 = m1.begin();
	if( ii1->size() != m2.size() ) //si la cant de columnas de la primer matriz difieren de la cant de filas de la segunda
	{
		//cout << "Disparara ERROR_NRO_FILAS_COL= " << ERROR_NRO_FILAS_COL << endl;
		throw( int(ERROR_NRO_FILAS_COL));
	}
	//
	std::list< std::list<T> > m2T; //guarda m2Transpuesta para facilitar los productos
	typename std::list< std::list<T> >::iterator ii2 = m2.begin();
	int cantCol = ii2->size();
	//barro la segunda matriz por columnas para irla metiendo como filas en la transpuesta
	for( int iCol=0; iCol < cantCol; iCol++ )
	{
		std::list<T> lAux;

		for( ii2 = m2.begin(); ii2 != m2.end(); ii2++ )
		{
			typename std::list<T>::iterator ii = ii2->begin();
			for( int i=0; i < iCol; i++ )
				ii++;
			lAux.push_back( *ii );
		}
		m2T.push_back(lAux);
	}
	//
	std::list< std::list<T> > lresul;
	//
	for( ; ii1 != m1.end(); ii1++ )
	{
		std::list<T> lfilaResultado;
		typename std::list< std::list<T> >::iterator ii2T = m2T.begin();
		for( ; ii2T != m2T.end(); ii2T++ )
		{
			typename std::list<T>::iterator iiFila1 = ii1->begin();
			typename std::list<T>::iterator iiCol2 = ii2T->begin();
			T tAux( T(0) );
			for( ; iiFila1 != ii1->end(); iiFila1++, iiCol2++ )
			{
				tAux +=  T(*iiFila1) * T(*iiCol2);
			}
			lfilaResultado.push_back(tAux);
		}
		lresul.push_back(lfilaResultado);
	}
	return lresul;
}

template <class T>
std::ostream& operator <<( std::ostream& os, std::list< std::list<T> >& m )
{
	typename std::list< std::list<T> >::iterator ii = m.begin();
	for( ; ii != m.end(); ii++ )
	{
		typename std::list<T>::iterator iiFila = ii->begin();
		os << std::endl;
		for( ; iiFila != ii->end(); iiFila++ )
		{
			os << "\t" << (*iiFila);
		}
	}
	os << std::endl;

	return os;
}
//
template <class T>
void Ejecuta( const std::string& str1, const std::string& str2 )
{
	std::list< std::list<T> > m1;
	std::list< std::list<T> > m2;

	try{
		LeeListBidim( str1, m1 );
		LeeListBidim( str2, m2 );
		std::list< std::list<T> > m3( m1 * m2 );
		std::cout << "M1=" << m1;
		std::cout << "M2=" << m2;
		std::cout << "M3 = M1 * M2 = " << m3;
	}
	catch( int e )
	{
		switch (e)
		{
			case (int(ERROR_ARCHIVO)):
				std::cerr << "Error al abrir un archivo\n";
			break;
			case (int(ERROR_NRO_FILAS_COL)):
				std::cerr << "Error no coinciden cols de la 1ra con filas de la 2da\n";
				//para haber visto nro filas y columnas ya leyo las matrices, luego las muestra para ayudar:
				std::cerr << "M1=" << m1;
				std::cerr << "M2=" << m2;
			break;
			default:
				std::cerr << "Error desconocido= " << e << std::endl;
		}
	}
	catch(...)
	{
		std::cerr << "Error throw no entero\n";
	}

}
//
int main( int argc, char **argv )
{
	if( argc < 3 )
	{
		std::cerr << "Debe llamarse: nombreEjecutable nombreArchivoM1 nombreArchivoM2" << std::endl;
		return 1;
	}
	//
	std::string nameM1(argv[1]);
	std::string nameM2(argv[2]);
	Ejecuta< std::complex<double> >( nameM1, nameM2 );
	//
	return 0;
}

