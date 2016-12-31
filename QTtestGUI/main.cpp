#include "stdafx.h"
#include "TestMainWidget.h"

#include <iostream>
using namespace std;

POLAR_BEAR_USE_NAMESPACE;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	TestMainWidget w;
	w.show();
	return a.exec();
	return 0;
}
