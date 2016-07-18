//!<

#ifndef POLAR_BEAR_TEST_CENTRAL_WIDGET_H
#define POLAR_BEAR_TEST_CENTRAL_WIDGET_H

#include <QtGui/QWidget>
class QSplitter;
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
	QWidget* m_pOperatorView;
	QWidget* m_pGraphicView;
	QWidget* m_pInfosView;

	QSplitter* m_pHorSplitter;
	QSplitter* m_pVerSplitter;

};





#endif