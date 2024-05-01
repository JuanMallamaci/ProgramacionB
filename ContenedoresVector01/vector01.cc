// Template/vector01.cc
#include <iostream>
#include <vector>
#include <algorithm> //para generar arg para std::sort
#include "Complejo.hpp"

template <class T>
struct SortMayorMenor
{
    inline bool operator() (const T& i1, const T& i2)
    {
    	return (i1 > i2);
    }
};

template <class T>
bool mioperador (const T& i1, const T& i2)
{
	return (i1 > i2);
}


int main( int argc, char **argv )
{
   std::vector<Complejo> vecComp;

   vecComp.push_back( Complejo (2,3) );
   vecComp.push_back( Complejo (4,5) );
   vecComp.push_back( Complejo (6,9) );

   std::cout << "Muestra utilizando indice:" << std::endl;

   unsigned int k;
   for( k=0; k < vecComp.size(); k++)
   {
  	 std::cout << vecComp[k] << std::endl;
   }

   std::cout << std::endl << "Muestra utilizando iterator:" << std::endl;

   std::vector<Complejo>::iterator ii;
   for(ii=vecComp.begin(); ii!=vecComp.end(); ii++)
   {
  	 std::cout << *ii << std::endl;
   }

   std::cout << std::endl << "Muestra utilizando const iterator:" << std::endl;

   std::vector<Complejo>::const_iterator cii;
   for(cii=vecComp.begin(); cii!=vecComp.end(); cii++)
   {
  	 std::cout << *cii << std::endl;
   }

   std::cout << std::endl << "Muestra utilizando reverse Iterator:" << std::endl;

   std::vector<Complejo>::reverse_iterator rii;
   for(rii=vecComp.rbegin(); rii!=vecComp.rend(); ++rii)
   {
  	 std::cout << *rii << std::endl;
   }

   std::cout << "size: " << vecComp.size() << std::endl;
   std::cout << "vecComp[2]: " << vecComp[2] << std::endl;

   std::swap(vecComp[0], vecComp[2]);
   std::cout << "vecComp[2] luego de swap con el [0]: " << vecComp[2] << std::endl;

   std::sort(vecComp.begin(),vecComp.end());

   std::cout << "Luego de sort sin metodo de ordenacion como argumento\n";
   for( k=0; k < vecComp.size(); k++)
   {
  	 std::cout << vecComp[k] << std::endl;
   }

   std::sort(vecComp.begin(),vecComp.end(), mioperador<Complejo>);

   std::sort(vecComp.begin(),vecComp.end(), SortMayorMenor<Complejo>());

   std::cout << "Luego de sort con metodo de ordenacion como argumento\n";
   for( k=0; k < vecComp.size(); k++)
   {
  	 std::cout <<  vecComp[k] << std::endl;
   }

  return 0;
}

