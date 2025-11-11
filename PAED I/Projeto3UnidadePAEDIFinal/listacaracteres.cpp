#include "listacaracteres.h"

ListaCaracteres::ListaCaracteres()
{
	try
	{
		caracteres = new huff*[50];
	}
	catch(bad_alloc &erroDeAlocacao)
	{
		cerr << erroDeAlocacao.what() << endl;
	}
	tamanho=50;
	intervalo=-1;
    alturArvore=0;	
			
}

ListaCaracteres::~ListaCaracteres()
{
	delete [] caracteres;
	delPosOrdem(ptRaiz);
	delete [] codeTabel;	
}
bool ListaCaracteres::criarLista(char * text)
{
	int tempindice=0;
	char alfa;
	huff * pont;
	ifstream openFile(text,ios::in);
	if(!openFile)
	{
        cout << "O arquivo nao pode ser aberto. Provaveis motivos\n" 
        << "1: O arquivo nao e do tipo texto (arquivos .exe por exemplo)\n"
        << "2: Foi digitado um nome de arquivo invalido\n"
        << "Por favor, tente novamente ou escolha outro arquivo" << endl;
        return false;
    }        
	while((alfa=openFile.get()) != EOF)
	{
		cout << alfa;
        if(intervalo>=tamanho)
			this->aumentarTamanho();
		
		for(tempindice;tempindice<=intervalo;tempindice++)
		{
			if(caracteres[tempindice]->info.character == alfa)
			{
				caracteres[tempindice]->info.quantidade += 1;
				tempindice=0;
				break;
			}
		}
		if (tempindice>intervalo)
		{
			caracteres[tempindice] = new huff;
            caracteres[tempindice]->info.character = alfa;
			caracteres[tempindice]->info.quantidade = 1;
			++intervalo;
			tempindice=0;
		}
	}
	openFile.close();
    ordenarLista();
	showLista();
	cout << "\nSecao 2 da Impressao: Montagem da Arvore de Huffman\n";
	system("PAUSE");
	arvHuffman();
	cout << endl;
	showArvDone();
	criarTabela();
	cout << "\nTabela Criada\n";
    showTabel();
	cout << "\nTabela Criada\n";
    return true;
}


void ListaCaracteres::ordenarLista()
{
     int i,j,max;
     for(i=0;i<intervalo;i++)
     {
        max=i;
        for(j=i+1;j<=intervalo;j++)
        {
              if(caracteres[j]->info.quantidade > caracteres[max]->info.quantidade)
              max = j;
        }            
        swap(i,max);
     }
}
	
	

void ListaCaracteres::swap(int x,int y)
{
	huff temp = (*caracteres[x]);
	(*caracteres[x])=(*caracteres[y]);
	(*caracteres[y])=temp;
}	
void ListaCaracteres::aumentarTamanho()
{
	huff * tempLista;
	int i;
	try
	{
		tempLista = new huff[tamanho];
	}
	catch(bad_alloc &memoryAllocationException)
	{
		cerr << memoryAllocationException.what() << endl;
	}
	for(i=0;i<tamanho;i++)
		tempLista[i]=(*caracteres[i]);
	delete [] caracteres;
	try
	{
		caracteres = new huff*[tamanho=tamanho*2];
		for(i=0;i<=intervalo;i++)
		{
            caracteres[i] = new huff;
        }
	}
	catch(bad_alloc &erroDeAlocacao)
	{
		cerr << erroDeAlocacao.what() << endl;
	}
	for(i=0;i<=intervalo;i++)
			(*caracteres[i])=tempLista[i];	
	delete [] tempLista;
}

void ListaCaracteres::showLista()
{
	cout << "\nDados da Lista:" << endl;
    cout << "Intervalo = " << intervalo << endl;
	cout << "Tamanho = " << tamanho << endl;
	for(int i=0;i<=intervalo;i++)
	{
		if(caracteres[i] == NULL) break;
        cout << "caracteres[" << i << "]->character = " << caracteres[i]->info.character
		<< "  caracteres[" << i << "]->quantidade = " << caracteres[i]->info.quantidade
		<< endl;
	}
}
                        
void ListaCaracteres::arvHuffman()
{
    bigDeal = intervalo;
    huff menorRQ, menorLQ;
    int posMenorRQ, posMenorLQ, i;
    huff * sPont;
    if (intervalo < 0)
    {
        cerr << "\nnenhuma lista encontrada para fazer a arvore\n";
        return;
    }
    else if(intervalo==0)
    {
        ptRaiz = new huff;
        (*ptRaiz) = (*caracteres[0]);
        delete [] caracteres;
        return;
    }
    else
    {
        
        while(intervalo > 0)
        {
            menorRQ = (*caracteres[intervalo]);
            posMenorRQ = intervalo;
            menorLQ = (*caracteres[intervalo-1]);
            posMenorLQ = intervalo-1;
            for(i=intervalo;i>=0;i--)
            {
                if(caracteres[i] == NULL) continue;
                if(caracteres[i]->info.quantidade < menorRQ.info.quantidade && i != intervalo-1)
                {  
                    menorRQ = (*caracteres[i]);
                    posMenorRQ = i;
                }
                if(caracteres[i]->info.quantidade < menorLQ.info.quantidade 
                && menorRQ.info.character != caracteres[i]->info.character)
                {
                    menorLQ = (*caracteres[i]);
                    posMenorLQ = i;
                }
                    
            }
            //atribuicoes
            if(posMenorRQ < posMenorLQ)
            {
                int temp = posMenorRQ;
                posMenorRQ = posMenorLQ;
                posMenorLQ = temp;
                huff troca = menorRQ;
                menorRQ = menorLQ;
                menorLQ = troca;
            }
            sPont = new huff;
            sPont->info.quantidade = menorRQ.info.quantidade + menorLQ.info.quantidade;
            sPont->info.character = '_';            
            sPont->left = new huff;
            sPont->left->info = menorLQ.info;
            sPont->left->left = menorLQ.left;
            sPont->left->right = menorLQ.right;
            sPont->right = new huff;
            sPont->right->info = menorRQ.info;
            sPont->right->left = menorRQ.left;
            sPont->right->right = menorRQ.right;
            //Aqui onde esta o perigo
            caracteres[posMenorLQ] = sPont;            
            caracteres[posMenorRQ] = NULL;
            this->organizar();
            cout << endl;
        }  
        ptRaiz = caracteres[0];
    }
}
        
void ListaCaracteres::organizar()
{   
    int i,j;
    for(i=0;i<=intervalo;i++)
    {
        if(caracteres[i] == NULL)
        {
            caracteres[i] = new huff;
            for(j=i;j<intervalo;j++)
            {
                (*caracteres[j]) = (*caracteres[j+1]);
            }
            break;
        }
    }
    --intervalo;
    ++alturArvore;
}                

void ListaCaracteres::showArvDone()
{
    cout << "Mostrando a Arvore percorrida em PreOrdem, Simetrica, e PosOrdem: " << endl;
    huff * pont;
    pont = ptRaiz;
    cout << "\nOrdem Simetrica:\n";
    simetArv(pont);
    cout << "\nPre Ordem:\n";
    pont = ptRaiz;
    preOrdem(pont);
    cout << "\nPos Ordem\n";
    pont = ptRaiz;
    posOrdem(pont);
}

void ListaCaracteres::criarTabela()
{
    string * binaryCode;
    try
    {
        codeTabel = new code[alturArvore+1];
        binaryCode = new string;
    }
    catch(bad_alloc &erroDeAlocacao)
	{
		cerr << erroDeAlocacao.what() << endl;
	}
    (*binaryCode) = "";
    int * posicao;
    posicao = new int;
    (*posicao) = 0;    
    tabelPosOrdem(codeTabel,ptRaiz,binaryCode,posicao);
}

void ListaCaracteres::showTabel()
{
    cout <<"\nTabela com os caracteres codificados:\n" << endl;
    int i;
    for(i=0;i<=alturArvore;i++)
    {
        //cout<<"codeTabel["<<i<<"].letra: "<<codeTabel[i].letra<<" "<<"codeTabel["<<i<<"].codigo = "<<codeTabel[i].codigo;
        //cout << endl;
        cout << "Codigo da Letra " << codeTabel[i].letra << ": " <<  codeTabel[i].codigo;
        cout << endl;
    }
}

void ListaCaracteres::writeOnFile(string fileOut)
{
    fileOut+=".txt";
    char fileOff[fileOut.length()];
    int i;
    for(i=0;i<fileOut.length();i++)
    {
        fileOff[i] = fileOut.at(i);
    }
    ofstream outFile(fileOff,ios::out);
	outFile << "Tabela com os caracteres codificados:\n" << endl;
	for(i=0;i<=alturArvore;i++)
    {
        outFile << "Codigo da Letra " << codeTabel[i].letra << ": " <<  codeTabel[i].codigo << endl;
    }
}
	
void ListaCaracteres::createDecodedFile()
{
    char alfa;
    int i;
    ifstream readFile("teste.txt",ios::in);
    ofstream postFile("arquivo.txt",ios::out);
    //postFile << codeTabel[0].letra;
    //postFile << codeTabel[1].letra;
    //postFile << codeTabel[2].letra;
   cout << bigDeal;
   while((alfa=readFile.get()) != EOF)
    {
        for(i=0;i<=bigDeal;i++)
        {
            cout << "loop " << i << endl;
            if(alfa == codeTabel[i].letra)
            {
                postFile << codeTabel[i].codigo;
                break;
            }
        }
    }
}
    
    
    
    
    
    
    

                     

void simetArv(huff * pt)
{
    if (pt->left != NULL) simetArv(pt->left);
    //if(pt->left == NULL && pt->right == NULL)
        cout << "pt->info.character: " << pt->info.character << " pt->info.quantidade: " << pt->info.quantidade << endl;
    if (pt->right != NULL) simetArv(pt->right);
}                  

void preOrdem(huff * pt)
{
    //if(pt->left == NULL && pt->right == NULL)
        cout << "pt->info.character: " << pt->info.character << " pt->info.quantidade: " << pt->info.quantidade << endl;
    if (pt->left != NULL) preOrdem(pt->left);    
    if (pt->right != NULL) preOrdem(pt->right);
}

void posOrdem(huff * pt)
{
    if (pt->left != NULL) posOrdem(pt->left);    
    if (pt->right != NULL) posOrdem(pt->right);
    //if(pt->left == NULL && pt->right == NULL)
        cout << "pt->info.character: " << pt->info.character << " pt->info.quantidade: " << pt->info.quantidade << endl;
}
//tabelPosOrdem deve comecar com:
    //(*binaryCode)=""
    //(*posicao)=0
void tabelPosOrdem(code * tabel,huff * pt, string * binaryCode,int * posicao)
{
    if (pt->left != NULL)
    {
        binaryCode->append("0");
        tabelPosOrdem(tabel,pt->left,binaryCode,posicao);
    }    
    if (pt->right != NULL) 
    {
        binaryCode->append("1");
        tabelPosOrdem(tabel,pt->right,binaryCode,posicao);
    }
    if(pt->left == NULL && pt->right == NULL)
    {
        tabel[(*posicao)].codigo = (*binaryCode);
        tabel[(*posicao)].letra = pt->info.character;
        (*posicao)=(*posicao)+1;
        binaryCode->resize(binaryCode->length()-1);
    }
}

void delPosOrdem(huff * pt)
{
    if(pt->left != NULL)
        delPosOrdem(pt->left);
    if(pt->right != NULL)
        delPosOrdem(pt->right);
    delete pt;
}
    
    
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  	
	
		
