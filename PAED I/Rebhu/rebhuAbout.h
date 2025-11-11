/**
* @file rebhuAbout.h
* @author Giuliano Vilela
* Contêm a dialog about do Rebhu
*/

#ifndef __REBHUABOUT_H__
#define __REBHUABOUT_H__

#include <Qt>
#include <QDialog>

#include "ui_about.h"

/**
* Esta classe representa a janela
* de informações em geral do Rebhu.
*/
class RebhuAbout : public QDialog {
	public:
		RebhuAbout(QWidget* parent = 0);
	private:
		Ui::rebhuAbout about;
};
	

#endif // __REBHUABOUT_H__
