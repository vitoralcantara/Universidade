#ifndef LISTACARACTERES_H
#define LISTACARACTERES_H
#include <fstream>
#include <iostream>
#include <string>
#include <new>
using namespace std;


//variavel para a lista de prioridades
typedef struct prioriCaractere
{
	char character;
	int quantidade;
}pC;
//variavel para a arvore de Huffman	
typedef struct noHuff
{
        pC info;
        noHuff *left;
        noHuff *right;
}huff;

//variavel para a tabela codificada
typedef struct codeLine
{
    string codigo;
    char letra;
}code;

class ListaCaracteres;

//Funcoes Extras em uso na classe ListaCaracteres
void simetArv(huff * pt);
void preOrdem(huff * pt);
void posOrdem(huff * pt);
void tabelPosOrdem(code * tabel,huff * pt, string * binaryCode,int * posicao);//para a tabela de codificacao
void delPosOrdem(huff * pt);//para deletar a arvore de huffman
//Ordem das funcoes que ocorrem nesse programa
    //1-ListaCaracters
    //2-criarLista
        //2.1-ordenarLista
            //2.1.1-swap
            //2.1.2-aumtentarTamanho
        //2.2-ArvHuffman
            //2.2.1-organizar
            //
        //2.3-criarTabela
            //2.3.1-tabelPosOrdem
       
class ListaCaracteres
{
private:
    int bigDeal;
    huff * ptRaiz; //guarda a arvore de Huffman
	huff ** caracteres; //Lista de prioridades que armazenara os caracteres e suas frequencias
	code * codeTabel; //tabela de codificacao huffman
	int tamanho, intervalo, alturArvore;
    //duplica o tamanho de caracteres[] se falta memoria
    void aumentarTamanho();
    void swap(int,int); //troca duas posicoes da lista de prioridades(caracteres[])
    //organiza a lista durante o processo de criacao da arvHuffman
    void organizar();    		
public:
	//Cria o array de caracteres
	ListaCaracteres();
	//Destroi todos os Arrays e ponteiros da funcao
	~ListaCaracteres();
	//cria a Lista inicial com os caracteres e sua quantidade, ainda desordenados
	bool criarLista(char * arquivo); //Cria a lista de Prioridade a partir da leitura do arquivo
	//Ordena a lista
	void ordenarLista();//Ordena a lista usando o algoritmo InsertionSort	
	void showLista();   //Imprime a lista de Prioridade 
	void arvHuffman();  //Cria a Arvore de Huffman
	void showArvDone(); //Imprime a Arvore de Huffman   
	void criarTabela(); //Cria a tabela a partir da Arvore de Huffman
	void showTabel(); //Exibe na tela a tabela criada
    void writeOnFile(string outFile); //Grava em arquivo a tabela criada
    //Funcao que le e decodifica o arquivo
    //void decodeFile(char * filetoBDec);
    //Cria o arquivo decodificado
    void createDecodedFile();				
};




#endif // LISTACARACTERES_H

