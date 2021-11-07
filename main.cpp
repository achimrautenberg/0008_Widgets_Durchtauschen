#include "MainWindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	MainWindow w;
	w.show();
	int iReturnValue = a.exec();
	return iReturnValue;
}
