#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MessageAnalyzer.h"


class MessageAnalyzer : public QMainWindow
{
	Q_OBJECT

public:
	MessageAnalyzer(QWidget *parent = Q_NULLPTR);

private:
	Ui::MessageAnalyzerClass ui;

	private slots:

	void buttonClicked();


};
