/**
* @file rebhuProgressDialog.h
* @author Giuliano Vilela
* Contêm a janela de progresso de operações
*/

#ifndef __REBHUPROGRESSDIALOG_H__
#define __REBHUPROGRESSDIALOG_H__

#include <Qt>
#include <QWidget>
#include <QDialog>
#include <QString>
#include <QApplication>

#include <string>
using std::string;

#include "ui_rebhuProgressDialog.h"

/**
* Esta classe representa a janela de progresso
* de compactação, utilizada pelo Rebhu.
* Contêm slots para atualizar à si mesmo e a aplicação em geral.
* enquanto a computação pesada é efetuada.
*/
class RebhuProgressDialog : public QDialog {
	public:
		RebhuProgressDialog(QWidget* parent = 0);
		~RebhuProgressDialog();	
		
	public slots:
		//! Aumenta o valor da progressbar, atualizando as animações
		void step(void);
		//! Reseta o valor da progressbar para 0
		void reset(void);
		//! Atualiza esta dialog e também as outras pela QApplication
		void update(void);
		//! Seta o nome do arquivo sendo compactado
		void setFile(string name);
		//! Seta a operação de compactação que está sendo realizada no arquivo
		void setOperation(string op);
		//! Seta os valores máximos e mínimos da progressbar
		void setMinMax(uint min, uint max);
		//! Seta o valor de incremento da progressbar à cada step
		void setStep(uint _s);
		
	private:
		uint _step;
		Ui::rebhuProgressDialog dialog;
};
	
#endif // __REBHUPROGRESSDIALOG_H__
