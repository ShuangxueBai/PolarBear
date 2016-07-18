#ifndef OPERATOR_VIEW_H
#define OPERATOR_VIEW_H
#include <QtGui/QWidget>
#include <QtGui/QTabWidget>

class QGroupBox;
//////////////////////////////////////////////////////////////////////////
class OperatorTabView : public QTabWidget
{
	Q_OBJECT
public:
	OperatorTabView(QWidget* parent = nullptr);
	~OperatorTabView();

protected:
	void initGui();
};


class QStackedWidget;
//////////////////////////////////////////////////////////////////////////
class OperatorView : public QWidget
{

	Q_OBJECT
public:
	OperatorView(QWidget* parent = nullptr);
	~OperatorView();

	QSize sizeHint() const;
protected:
	void initGui();

protected:
	QStackedWidget* m_pStackedWidget;
};

#endif