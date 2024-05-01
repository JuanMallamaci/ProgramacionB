// Template/vector02.cc
#include <iostream>
#include <vector>
using namespace std;

int main( int argc, char **argv )
{
   vector< vector < vector<int> > > vecMultiDim( 4, vector < vector<int> >( 2, vector<int>(3, -1)));


	//luego de inicializado en -1, se muestra el contenido del vector multidimensional mediante iteradores constantes
   std::cout << "Muestra utilizando iteradores constantes:" << std::endl;
   for( vector< vector < vector<int> > >::const_iterator cExt=vecMultiDim.begin();
  		 cExt != vecMultiDim.end(); cExt++ )
   {
  	 cout << "Dimension externa\n";
     for( vector < vector<int> >::const_iterator cMed= cExt->begin();
    		 cMed != cExt->end(); cMed++ )
     {
    	 cout << "Dimension intermedia\n";
       for( vector<int>::const_iterator cInterior= cMed->begin();
      		 cInterior != cMed->end(); cInterior++ )
       {
      	 cout << *cInterior << "  ";
       }
    	 cout << endl;
     }
   }

   std::cout << "Muestra utilizando indices:" << std::endl;

   for( unsigned int k=0; k < vecMultiDim.size(); k++ )
   {
  	 cout << "Dimension externa\n";
     for( unsigned int j=0; j < vecMultiDim[k].size(); j++ )
     {
    	 cout << "Dimension intermedia\n";
       for( unsigned int i=0; i < vecMultiDim[k][j].size(); i++ )
       {
      	 cout << "vecMultiDim[" << k << "][" << j << "][" << i << "]= "<< vecMultiDim[k][j][i] << "  ";
       }
    	 cout << endl;
     }
   }

   std::cout << "Reasigna utilizando iteradores, desde 111 al primer elemento hasta 423 el ultimo:" << std::endl;

   int k=1;
   for( vector< vector < vector<int> > >::iterator iiExt=vecMultiDim.begin();
  		 iiExt != vecMultiDim.end(); iiExt++, k++ )
   {
     int j=1;
     for( vector < vector<int> >::iterator iiMed= iiExt->begin();
    		 iiMed != iiExt->end(); iiMed++, j++ )
     {
       int i=1;
       for( vector<int>::iterator iiInterior= iiMed->begin();
      		 iiInterior != iiMed->end(); iiInterior++, i++ )
       {
      	 *iiInterior = k * 100 + j * 10 + i;
       }
     }
   }

   std::cout << "Muestra lo reasignado utilizando iteradores constantes:" << std::endl;

   for( vector< vector < vector<int> > >::const_iterator cExt=vecMultiDim.begin();
  		 cExt != vecMultiDim.end(); cExt++ )
   {
  	 cout << "Dimension externa\n";
     for( vector < vector<int> >::const_iterator cMed= cExt->begin();
    		 cMed != cExt->end(); cMed++ )
     {
    	 cout << "Dimension intermedia\n";
       for( vector<int>::const_iterator cInterior= cMed->begin();
      		 cInterior != cMed->end(); cInterior++ )
       {
      	 cout << *cInterior << "  ";
       }
    	 cout << endl;
     }
   }

   return 0;
}

