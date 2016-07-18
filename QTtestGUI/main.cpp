#include "stdafx.h"
#include "TestMainWidget.h"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	TestMainWidget w;
	w.show();
	return a.exec();
}
