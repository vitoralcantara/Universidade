/*!
 ===========================================================================
 SOURCE FILE : distancia_pontos.cpp
 ===========================================================================
 DESCRIPTION.: Exemplo 2
 AUTHOR......: Demétrios.
 LOCATION....: DIMAp/UFRN.
 SATARTED ON.: Aug/2008
 TO COMPILE..: g++ -Wall distancia_pontos.cpp -o distancia_pontos
 ---------------------------------------------------------------------------
*/
/* includes*/

#include <iostream>
#include <cmath>
using namespace std;

/*Global Variables and Structes*/
struct ponto {
	double x;
	double y;
};
//!distanciadepontos function
double distanciadepontos(ponto p1,ponto p2);

/* DECLARATION OF THE MAIN PROGRAM */
int main()
{
	ponto p1 , p2;

        cout << "p1x : ";
        cin >>  p1.x;
        cout << "p1y : ";
        cin >>  p1.y;
        cout << "p2x : ";
        cin >>  p2.x;
        cout << "p2y : ";
        cin >>  p2.y;

        cout << distanciadepontos(p1,p2);

        return 0;
}

//! The function returns the distance between two points
/*! 
 *  @param p1 struct point one
 *  @param p2 struct point two
 *
 *  @return return the distance between two points
 */
double distanciadepontos(ponto p1,ponto p2){

    double x = pow((p2.x - p1.x),2);
    double y = pow((p2.y - p1.y),2);
    double d = sqrt ( x + y );

return d;

}
 
