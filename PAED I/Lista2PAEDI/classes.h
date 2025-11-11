#include <iostream>
#include <vector>

using namespace std;

template <typename Object>
class ListaEncadeada
 {
         Object valor;
         Object *ListaEncadeada;
 };

template <class Object>
class PilhaQ1 {
      private:
              vector<Object> pilQ1;
      public:
             PilhaQ1();
             bool estaVazia()const;
             const Object &topo()const;
             void tornarVazia();
             void empilha(const Object &x);
             Object desempilha();
      };
/*      
template<class Object>
class FilaQ2 {
      private:
              vector<Object> FilQ2;
      public:
             FilaQ2();
             bool estaVazia()const;
             const Object &primeiroDaFila()const;
             void tornarVazia();
             void entrarNaFila(const Object &x);
      };
      
template<class Object>
class PilhaQ3 {
      private:
              Object *NO;
      public:
             PilhaQ3();
             ~PilhaQ3();
             bool estaVazia()const;
             const Object &topo()const;
             void tornarVazia();
             void empilha(const Object &x);
             Object desempilha();
             void print();
      };

template<class Object>
class FilaQ4 {
      private:
              Object *NO;
      public:
             FilaQ4();
             ~FilaQ4();
             bool estaVazia()const;
             const Object &primeiroDaFila()const;
             void tornarVazia();
             void entrarNaFila(const Object &x);
             void print();
      };
             
              
             
                     
               
