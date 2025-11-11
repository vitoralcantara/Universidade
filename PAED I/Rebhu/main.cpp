/**
* @file main.cpp
* @author Giuliano Vilela
* Arquivo principal do Rebhu.
* Cria uma QApplication e uma RebhuWindow e passa o controle
* de eventos e threads para o Qt.
*/

#include <QApplication>

#include "rebhuMainWindow.h"

int main ( int argc, char** argv ) {
	// Utiliza alguns argumentos de linha de comando e inicializa o Qt
	QApplication app(argc,argv);
	
	// Janela principal do Rebhu
	RebhuWindow mainWin;
	mainWin.show();
	
	// Passa o controle da aplicação para o Qt.
	return app.exec();
}
