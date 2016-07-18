#include "stdafx.h"
#include "TestMainWidget.h"
#include "TestCentralWidget.h"

TestMainWidget::TestMainWidget(QWidget* parent)
	:QMainWindow(parent)
{
	setWindowState(Qt::WindowState::WindowMaximized);
	setWindowTitle(QString("Test 3D Engine that is Polar Bear!"));
	initGUI();
}

TestMainWidget::~TestMainWidget()
{

}

void TestMainWidget::initGUI()
{
	m_pCentralWidget = new TestCentralWidget(this);
	setCentralWidget(m_pCentralWidget);
	return;
}
