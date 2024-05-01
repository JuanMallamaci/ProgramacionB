// Template/list01.cc
#include <iostream>
#include <math.h>
#include <list>

class MiClase{
	double base;
	double exp;
public:
	MiClase();
	MiClase( const double& _base, const double& _exp );
	double GetBase()const;
	double GetExp()const;
	double Potencia()const;
	MiClase operator= ( const MiClase& );
	bool operator== ( const MiClase& )const;
	bool operator< ( const MiClase& )const;
	friend std::ostream& operator<< ( std::ostream& os, const MiClase& miClase );
};

bool ComparaMiClase( const MiClase& miClase1, const MiClase& miClase2 )
{
	return (miClase2.Potencia() < miClase1.Potencia());
}

MiClase::MiClase()
{
	base = 0.0;
	exp = 1.0;
}

MiClase::MiClase( const double& _base, const double& _exp ):base(_base), exp(_exp){};

double MiClase::GetBase()const
{
	return base;
}

double MiClase::GetExp()const
{
	return exp;
}

double MiClase::Potencia()const
{
	return pow(base, exp);
}

MiClase MiClase::operator= ( const MiClase& miClase )
{
	base = miClase.base;
	exp = miClase.exp;
	return *this;
}

bool MiClase::operator== ( const MiClase& miClase )const
{
	return( (base==miClase.base) && (exp==miClase.exp) );
}


bool MiClase::operator< ( const MiClase& miClase )const
{
	return ( Potencia() < miClase.Potencia() );
}


std::ostream& operator<< ( std::ostream& os, const MiClase& miClase )
{
	os << "potencia de " << miClase.base << " elevado a " << miClase.exp << " da " << miClase.Potencia();
	return os;
}


int main( int argc, char **argv )
{
   std::list<MiClase> listMiClase;
   //std::list<MiClase> listMiClase(4); //reserva 4 elementos, inicializados por defecto
   //std::list<MiClase> listMiClase(4, MiClase(0.5,2.0)); //reserva 4 elementos inicializados con MiClase(0.5,2.0)

   for( double i=0.1; i< 1.4; i+=0.3 )
   {
     MiClase miclase( 5.0 / i, -1.3 * i );
     listMiClase.push_back(miclase);
   }

   std::cout << std::endl << "Muestra utilizando iterator:" << std::endl;

   std::list<MiClase>::iterator ii;
   for(ii=listMiClase.begin(); ii!=listMiClase.end(); ii++)
   {
  	 std::cout << *ii << std::endl;
   }

   std::cout << std::endl << "Muestra utilizando const iterator:" << std::endl;

   std::list<MiClase>::const_iterator cii;
   for(cii=listMiClase.begin(); cii!=listMiClase.end(); cii++)
   {
  	 std::cout << *cii << std::endl;
   }

   std::cout << std::endl << "Muestra utilizando reverse Iterator:" << std::endl;

   std::list<MiClase>::reverse_iterator rii;
   for(rii=listMiClase.rbegin(); rii!=listMiClase.rend(); ++rii)
   {
  	 std::cout << *rii << std::endl;
   }

   std::cout << "size: " << listMiClase.size() << std::endl;

   listMiClase.sort();

   std::cout << "Luego de sort, utilizando la sobrecarga del operador < y utilizando iterator:\n";
   for(ii=listMiClase.begin(); ii!=listMiClase.end(); ii++)
   {
  	 std::cout << *ii << std::endl;
   }

   //ahora utilizando un metodo externo para ordenar
   listMiClase.sort( ComparaMiClase );
   std::cout << "Luego de sort, utilizando un metodo externo para ordenar y utilizando iterator:\n";
   for(ii=listMiClase.begin(); ii!=listMiClase.end(); ii++)
   {
  	 std::cout << *ii << std::endl;
   }

  return 0;
}

