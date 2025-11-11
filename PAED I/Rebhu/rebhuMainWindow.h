/**
* @file rebhuMainWindow.h
* @author Giuliano Vilela
* Este arquivo contêm a classe principal da GUI.
* Reune toda a lógica da janela principal do Rebhu.
*/

#ifndef __REBHUMAINWINDOW_H__
#define __REBHUMAINWINDOW_H__

#include <Qt>
#include <QWidget>
#include <QMainWindow>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QString>
#include <QMessageBox>
#include <QInputDialog>
#include <QFileDialog>

#include <iostream>
#include <list>
using std::list;
using std::cout;
using std::endl;

#include "ui_rebhuMainWindow.h"
#include "RebhuMain.h"
#include "rebhuAbout.h"
#include "rebhuProgressDialog.h"

/**
* QMainWindow que representa a janela principal do Rebhu.
* Reúne toda a lógica da GUI em torno da interação desta classe
* com um RebFile.
*/
class RebhuWindow : public QMainWindow {
	Q_OBJECT
	
	public:
		RebhuWindow(QWidget* parent = 0);
		~RebhuWindow();
	
	protected slots:
		void addFile(void);
		void removeFile(void);
		void extractFile(void);
		void updateFile(void);

		void newFile(void);
		void openFile(void);
		void closeFile(void);
		void exit(void);
		
		void showAbout(void);
	
	protected:
		void connectActions(void);
		void open_file(bool RebFlag);
		void toggleToolbar(void);

		void updateDisplay(void);
		void update_file(bool update_display = false);
		void confirmAndClose(void);
		
		void addTableItem(const Rebhu::File& f);
		void addTableItem(const Rebhu::FileSpec& f);
		void clearTable(void);

		void enableGui(void);
		void disableGui(void);

	private:
		Ui::rebhuWindow mainWin;
		RebhuAbout about;
		Rebhu::RebFile file;
		
};


#endif 
