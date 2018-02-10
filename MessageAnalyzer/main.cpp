#include "stdafx.h"
#include "MessageAnalyzer.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MessageAnalyzer w;
	w.show();
	return a.exec();
}
