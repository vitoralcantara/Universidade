#include "rebhuMainWindow.h"

//! Cria a janela com o pai parent, montando a gui e conectando as actions
RebhuWindow::RebhuWindow(QWidget* parent) : QMainWindow(parent) {
	mainWin.setupUi(this);
	connectActions();
}

RebhuWindow::~RebhuWindow() {
}

/**
* Conecta todas as actions da Gui (da toolbar e dos menus)
* com os respectivos slots desta classe.
*/
void RebhuWindow::connectActions(void) {
	connect(mainWin.actionNovo,SIGNAL(triggered(bool)),this,SLOT(newFile()));
	connect(mainWin.actionAbrir,SIGNAL(triggered(bool)),this,SLOT(openFile()));
	connect(mainWin.actionFechar,SIGNAL(triggered(bool)),this,SLOT(closeFile()));
	connect(mainWin.actionSair,SIGNAL(triggered(bool)),this,SLOT(exit()));
	connect(mainWin.actionAdicionar,SIGNAL(triggered(bool)),this,SLOT(addFile()));
	connect(mainWin.actionRemover,SIGNAL(triggered(bool)),this,SLOT(removeFile()));
	connect(mainWin.actionExtrair,SIGNAL(triggered(bool)),this,SLOT(extractFile()));
	connect(mainWin.actionUpdate,SIGNAL(triggered(bool)),this,SLOT(updateFile()));
	connect(mainWin.actionSobre,SIGNAL(triggered(bool)),this,SLOT(showAbout()));
}

/**
* Performa todas as operações requisitadas no RebFile.
* Mantêm as informações de progresso na RebhuProgressDialog.
* Se update_display for verdadeiro, atualiza a tabela de arquivos da GUI.
*/
void RebhuWindow::update_file(bool update_display) {
	RebhuProgressDialog pd(this);
	pd.update();
	
	file.comit(&pd);
	if (update_display)
		updateDisplay();
		
	setWindowModified(false);
}

//! Cria um novo RebFile
void RebhuWindow::newFile(void) {
	open_file(Rebhu::RebFile::New);
}

//! Abre para leitura um RebFile existente
void RebhuWindow::openFile(void) {
	open_file(Rebhu::RebFile::Open);
}

//! Fecha um arquivo, perguntando se deseja efetuar operações não salvas
void RebhuWindow::closeFile(void) {
	if (file.isOpen())
		confirmAndClose();
	updateDisplay();
}

//! Atualiza o RebFile e a tabela de arquivos
void RebhuWindow::updateFile(void) {
	update_file(true);
}

/**
* Função principal de extração de arquivos.
* Extrai cada arquivo selecionado na tabela.
* Abre uma QDialog perguntando o diretório para extração.
*/
void RebhuWindow::extractFile(void) {
	// Pega todas as CÉLULAS selecionadas
	list<QTableWidgetItem*> lst = mainWin.fileTable->selectedItems().toStdList();
	list<QTableWidgetItem*>::const_iterator it = lst.begin();
	
	if (lst.empty()) {
		QMessageBox::critical(this,
			QString("Extrair arquivos"), QString("Nenhum arquivo foi selecionado"));
		return;
	}
	
	string dir;
	dir = QFileDialog::getExistingDirectory(this,
			QString::fromUtf8("Selecione o diretório para extração")).toStdString();

	if (dir.empty()) return;

	uint c = 0;

	// Separa os nomes dos arquivos e descompacta-os
	for (;it != lst.end();) {
		// Primeira célula da linha é o nome do arquivo
		string nome = (*it)->text().toStdString();
		try {
			file.decompressFile(nome,dir);
		}
		catch (...) {
			(void)QMessageBox::critical(this,QString("Extrair arquivos"),
				QString("Ocorreu um erro na descompactação do arquivo ")+nome.c_str());
			return;
		}
		++c;

		for (uint i = 0; i < 7 && it != lst.end(); ++i) ++it; // Pula os números
	}	
	
	(void)QMessageBox::information(this,QString::fromUtf8("Extrair arquivos"),
		QString::number(c)+(c!=1?" arquivos foram descompactados":" arquivo foi descompactado")+" com sucesso!");
}

/**
* Adiciona um novo arquivo ao RebFile.
* Abre dialogs perguntando qual arquivo será adicionado
* e também o tamanho dos blocos de cada algoritmo
*/
void RebhuWindow::addFile(void) {
	QString fileName;
	Rebhu::FileSpec f;
	
	f.nome = QFileDialog::getOpenFileName(this,
			QString("Adicionar arquivo"),QString(),QString("Todos os arquivos (*.*)")).toStdString();
			
	if (f.nome.empty()) return;
	
	f.huffSize = QInputDialog::getInteger(this,
			QString("Huffman Blocks"),QString("Escolha o tamanho dos blocos para o Huffman (em kb)"),
			150u,1u,1024u*1000u,5u)*1024u;
	
	f.rleSize = QInputDialog::getInteger(this,
			QString("RLE Blocks"),QString("Escolha o tamanho dos blocos para o RLE (em kb)"),
			100u*1024u,100u,1024u*1000u,150u)*1024u;
	
	f.bwtSize = QInputDialog::getInteger(this,
			QString("BWT Blocks"),QString("Escolha o tamanho dos blocos para o BWT (em kb)"),
			400u,10u,1024u*20u,10u)*1024u;
	
	file.addFile(f);
	setWindowModified(true);
	updateDisplay();
		
}

// #################
void RebhuWindow::removeFile(void) {
	
}

//! Fecha o programa, atualizando o arquivo se necessário
void RebhuWindow::exit(void) {
	if (file.isOpen())
		confirmAndClose();
	close();
}

//! Confirma se deseja efetuar as últimas modificações e fecha o arquivo
void RebhuWindow::confirmAndClose(void) {
	if (file.hasModifications()) {
		if (QMessageBox::question(this,QString::fromUtf8("Confirmação"),
			QString::fromUtf8("Algumas modificações feitas ainda não foram incluídas no arquivo. Deseja atualizar o arquivo?"),
			QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes)
				update_file(false);
	}
	file.close(false);
	clearTable();
	disableGui();
}

/**
* Abre um novo arquivo RebFile.
* Pergunta aonde ele está e também checa se é um
* arquivo .reb válido (na medida do possível, pois há
* maneiras de se burlar essa checagem).
*/
void RebhuWindow::open_file(bool RebFlag) {
	QString fileName;
	if (file.isOpen())
		confirmAndClose();

	if (RebFlag == Rebhu::RebFile::New)
		fileName = QFileDialog::getSaveFileName(this,
			QString("Novo arquivo"),QString(),QString("Rebhu Files (*.reb)"));
	else
		fileName = QFileDialog::getOpenFileName(this,
			QString("Abrir arquivo"),QString(),QString("Rebhu Files (*.reb)"));

	if (fileName.isEmpty()) return;

	try {
		file.open(fileName.toStdString().c_str(),RebFlag);
		updateDisplay();
	}
	catch (...) {
		file.close(false);
		return (void)QMessageBox::critical(this,
			QString("Abrir arquivo"), QString::fromUtf8("O arquivo escolhido não é um arquivo .reb válido ou está corrompido."));
	}
	enableGui();
}

/**
* Atualiza a tabela de arquivos.
* Manda o RebFile atualizar a lista interna de arquivos e depois,
* para cada um deles, monta as células que irão ser colocadas na tabela.
*/
void RebhuWindow::updateDisplay(void) {
	clearTable();
	if (!file.isOpen()) return;

	file.analize();
	list<Rebhu::File>::const_iterator it_in;
	list<Rebhu::FileSpec>::const_iterator it_add;

	for (it_in = file.inside.begin(); it_in != file.inside.end(); ++it_in)
		addTableItem(*it_in);

	for (it_add = file.to_add.begin(); it_add != file.to_add.end(); ++it_add)
		addTableItem(*it_add);
}

/**
* Transforma o número num em uma string, formatada
* para exibição de tamanho de arquivos (em bytes, kbytes e megabytes).
*/
QString formatFileSize (uint num) {
	QString result;
	if (num < 1024u)
		result = QString::number(num) + 'b';
	else if (num < 1024u*1024u)
		result = QString::number(num/(double)1024,'f',2u) + "kb";
	else 
		result = QString::number((num/(double)1024)/1024u,'f',2u) + "mb";
	return result;
}

/**
* Cria as células necessárias para descrever o File f,
* e as adiciona na fileTable.
*/
void RebhuWindow::addTableItem(const Rebhu::File& f) {
	QTableWidget* t = mainWin.fileTable;
	uint row = t->rowCount();
	t->setRowCount(row+1);
	
	t->setItem(row,0,(new QTableWidgetItem(QString(f.nome.c_str()))));
	t->setItem(row,1,(new QTableWidgetItem(formatFileSize(f.origSize))));
	t->setItem(row,2,(new QTableWidgetItem(formatFileSize(f.compSize))));
	t->setItem(row,3,(new QTableWidgetItem(
			QString::number(double(f.compressionRatio()),'f',2u)+'%')));
	t->setItem(row,4,(new QTableWidgetItem(QString::number(f.huff_x))));
	t->setItem(row,5,(new QTableWidgetItem(QString::number(f.rle_x))));
	t->setItem(row,6,(new QTableWidgetItem(QString::number(f.bwt_x))));
}

/**
* Cria as células necessárias para descrever o FileSpec f,
* e as adiciona na fileTable.
*/
void RebhuWindow::addTableItem(const Rebhu::FileSpec& f) {
	QTableWidget* t = mainWin.fileTable;
	uint row = t->rowCount();
	t->setRowCount(row+1);
	
	t->setItem(row,0,(new QTableWidgetItem(QString(f.nome.c_str()))));
	t->setItem(row,1,(new QTableWidgetItem(QString("--"))));
	t->setItem(row,2,(new QTableWidgetItem(QString("--"))));
	t->setItem(row,3,(new QTableWidgetItem(QString("--"))));
	t->setItem(row,4,(new QTableWidgetItem(formatFileSize(f.huffSize))));
	t->setItem(row,5,(new QTableWidgetItem(formatFileSize(f.rleSize))));
	t->setItem(row,6,(new QTableWidgetItem(formatFileSize(f.bwtSize))));
}

//! Limpa a tabela de arquivos
void RebhuWindow::clearTable(void) {
	mainWin.fileTable->clearContents();
	mainWin.fileTable->setRowCount(0u);
}

//! Habilita os elementos da GUI que interagem com o RebFile
void RebhuWindow::enableGui(void) {
	mainWin.fileBar->setEnabled(true);
	mainWin.fileTable->setEnabled(true);
	setWindowTitle(QString(Rebhu::removePath(file.getName()).c_str()) + QString("[*] - Rebhu 0.5"));
	setWindowModified(false);
}

//! Desabilita os elementos da GUI que interagem com o RebFile
void RebhuWindow::disableGui(void) {
	mainWin.fileBar->setEnabled(false);
	mainWin.fileTable->setEnabled(false);
	setWindowModified(false);
	setWindowTitle(QString("Rebhu 0.5[*]"));
}

//! Mostra a dialog de about do Rebhu
void RebhuWindow::showAbout(void) {
	about.show();
}
