//!<

#ifndef POLAR_BEAR_TEST_CENTRAL_WIDGET_H
#define POLAR_BEAR_TEST_CENTRAL_WIDGET_H

#include <QtWidgets/QWidget>
#include <QtWidgets/QSplitter>


class OperatorView;
class GraphicView;
class InfosView;
class TestCentralWidget : public QWidget
{
	Q_OBJECT
public:
	TestCentralWidget(QWidget* parent = nullptr);
	~TestCentralWidget();

protected:
	void initGui();
	virtual void resizeEvent(QResizeEvent *e);
private:
	OperatorView* m_pOperatorView;
	GraphicView* m_pGraphicView;
	InfosView* m_pInfosView;

	QSplitter* m_pHorSplitter;
	QSplitter* m_pVerSplitter;

};





#endif