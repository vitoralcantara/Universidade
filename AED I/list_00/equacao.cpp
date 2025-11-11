#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

int raizes(float a, float b, float c, float *x1, float *x2)
	{
	 float delta;
	 delta = (b*b) - (4*a*c);
	 printf("%d\n",delta);
	  if (delta < 0)
		{
		 *x1 = *x2 = 0;
		 return(0);
		}
	  else
		{
         *x1 = (-b - sqrt(delta))/(a*2);          
		 *x2 = (-b + sqrt(delta))/(a*2);
         if (*x1 == *x2) return(1);
		 else return(2);
		} 
		
	}
	
int main()
{
     float a, b, c,v1=0,v2=0,*x1,*x2;
	 int n,s;
	 x1=&v1;
	 x2=&v2;
	 printf("O Valor para a: ");
	 scanf("%f",&a);
	 printf("para b: ");
	 scanf("%f",&b);
	 printf("para c: ");
	 scanf("%f",&c);
	 n = raizes(a,b,c,x1,x2);
	 printf("Esta equacao possui %d raiz(es)\n. Sao %.2f e %.2f", n,*x1,*x2);
    return(0);
}
