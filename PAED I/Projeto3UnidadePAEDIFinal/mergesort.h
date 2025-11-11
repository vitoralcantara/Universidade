#include<cstdlib>
void mergeSort(int vetor[],int aux[],int tam) {
   m_sort(vetor,aux,0,tam-1);
}
 
void merge(int vetor[],int aux[],int esq,int meio,int dire) {

   int i,esq_fim,num_elementos,aux_pos;

   esq_fim=meio-1;
   aux_pos=esq;
   num_elementos=dire-esq+1;

   while ((esq<=esq_fim)&&(meio<=dire)) {
 
    if (vetor[esq]<=vetor[meio]) {
   
      aux[aux_pos]=vetor[esq];
      aux_pos=aux_pos+1;
      esq=esq+1;
    }
    else {
   
      aux[aux_pos]=vetor[meio];
      aux_pos=aux_pos + 1;
      meio=meio+1;
    }
   }

   while (esq<=esq_fim) {
 
     aux[aux_pos]=vetor[esq];
     esq=esq+1;
     aux_pos=aux_pos+1;
   }

   while (meio<=dire) {
 
     aux[aux_pos]=vetor[meio];
     meio=meio+1;
     aux_pos=aux_pos+1;
   }

   for (i=0;i<num_elementos;i++) {
 
     vetor[dire]=aux[dire];
     dire=dire-1;
   }
}

void m_sort(int vetor[],int aux[],int esq,int dire) {

   int meio;
   if (dire>esq) {
       meio=(dire+esq)/ 2;
       m_sort(vetor,aux,esq,meio);
       m_sort(vetor,aux,meio+1,dire);
       merge(vetor,aux,esq,meio+1,dire);
   }
}
