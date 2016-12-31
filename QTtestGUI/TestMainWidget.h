#pragma once
#include <QtWidgets/QMainWindow>

class TestCentralWidget;
class TestMainWidget : public QMainWindow 
{
	Q_OBJECT
public:
	TestMainWidget(QWidget* parent = nullptr);
	~TestMainWidget();

protected:
	void initGUI();
private:
	TestCentralWidget* m_pCentralWidget = nullptr;
};


