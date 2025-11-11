//UFRN - CCET - Dimap
//Materia: Algoritmos e Estruturas de Dados I
//Prof: Uira Kulesza
//Aluno: Vitor Alcantara de Almeida
//Matricula: 2008018563

//Programa: Simulador de Codificacao Huffman
//v.1.0
#include <cstdlib>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include "listacaracteres.h"
using namespace std;

//void menu()
//{
//    ListaCaracteres listaPriori;
//    char arquivo[30];
//    cout << "Qual o arquivo de texto desejas compactar?\n";
//    cin >> arquivo;
    

int main(int argc, char *argv[])
{
 	cout << "Programa Simulador de Codificao Huffman em arquivos" << endl;
 	cout << "Autor: Vitor Alcantara de Almeida\n"
 	<< "Matricula: 2008018563" << endl ;
 	char escolha = 'S';
    while(escolha == 'S' || escolha == 's')
    {
        
        bool status=false;
        char arquivo[30]; 
        string outFile;
	    cout << "Qual o arquivo de texto desejas compactar?\n";
	    //cin >> arquivo;
	    ListaCaracteres * listaPriori;
        do
	   {
            listaPriori = new ListaCaracteres;
            cout << "\nNome do Arquivo: ";
            cin >> arquivo;
            status = listaPriori->criarLista(arquivo);
            cout << "Qual o nome do arquivo a gerar o codigo?" << endl;
            cin >> outFile;
            listaPriori->writeOnFile(outFile);
            listaPriori->createDecodedFile();
        }while (status == false);
        do
        {
            cout << "\n\nGostaria de codificar outro arquivo? (S) ou (N)\n";
            cin >> escolha;
        }while(escolha != 'N' && escolha != 'S' && escolha != 's' && escolha != 'n');
        delete listaPriori;
    }
	system("PAUSE");
    return EXIT_SUCCESS;
}
	/*Apenas para testes**
	char character;
  	ifstream openFile("teste.txt",ios::in);
  	while((character=openFile.get()) != EOF)
  	{
		//teste=character;
	  	cout << character;
	}*/
