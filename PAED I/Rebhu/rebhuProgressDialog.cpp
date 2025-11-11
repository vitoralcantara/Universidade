#include "rebhuProgressDialog.h"

RebhuProgressDialog::RebhuProgressDialog(QWidget* parent) : QDialog(parent) {
	dialog.setupUi(this);
	_step = 1;
	show();
}

RebhuProgressDialog::~RebhuProgressDialog() {
	hide();
}

void RebhuProgressDialog::step(void) {
	dialog.progressBar->setValue(dialog.progressBar->value()+_step);
	update();
}

void RebhuProgressDialog::update(void) {
	repaint();
	QApplication::processEvents();
}

void RebhuProgressDialog::reset(void) {
	dialog.progressBar->setValue(0);
}

void RebhuProgressDialog::setFile(string name) {
	dialog.fileLabel->setText(QString("Arquivo atual: ") + name.c_str());
}

void RebhuProgressDialog::setOperation(string op) {
	dialog.opLabel->setText(QString::fromUtf8("Operação atual: ") + op.c_str());
}

void RebhuProgressDialog::setMinMax(uint min, uint max) {
	dialog.progressBar->setMinimum(min);
	dialog.progressBar->setMaximum(max);
}

void RebhuProgressDialog::setStep(uint _s) {
	_step = _s;
}
