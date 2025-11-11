/*#include <iostream>
using namespace std;


using namespace std;
typedef struct prioriCaractere
{
	char character;
	int quantidade;
}pC;


typedef struct noArvBin
{
	cP info;
	noArvBin * left;
	noArvBin * right;
}AB;

              
                  
                          
void buscaArvore(cP valor, cP *  ptInfo, int * status)
{
     status = new int;
     if(ptInfo == NULL)
          *status = 0;
     else if (valor.character == *ptInfo.character)
          *status = 1;
     else if(valor.quantidade < *ptInfo.quantidade)
     {
                              if(*ptInfo.left == NULL)
                                              *status = 2;
                              else(ptInfo=*ptInfo.left)
                                              buscaArvore(valor,ptInfo,status);
                              
     }
     else if(*ptInfo.right == NULL)
          *status=3;
     else
     {
         ptInfo=*ptInfo.right;
         buscaArvore(valor,ptInfo,status);
     }
}

void insercaoArvore(cP valor, cP * ptPai, int * status)
{
     cP * ptInfo,pt1;
     ptInfo = ptPai;
     buscaArvore(valor,ptInfo,status)
     if(*status==1)
     {
                   cerr << "insercaoArvore: Ja existe esse valor";
     }
     else 
     {
          pt1 = new cP;
          *pt1 = valor;
          if(*status == 0)
          {
                     ptPai = pt1;
          }
          else if(*status == 2)
               *ptInfo.left = pt1;
          else *ptIndo.right = pt1;
}     
  
  
pC takeBack(pC * info)
{
     pC * pt;
     pt=info;
     if(*pt.left != NULL)
     {
                 pt=*pt.left;
                 return takeBack(pt);
     }
     else
     {
         if(


          
void binarySort(pC * lista,int tamanho)
{
              AB * ptPai;
              ptPai;
              int * status;
              for(int i=0;i<tamanho;i++)
              {
                      insercaoArvore(lista[i],ptPai,status);
              }
              
*/          
          
          
           

                          
                                 
                          
                             
              
