#include "stdafx.h"
#include "operatorView.h"


OperatorTabView::OperatorTabView(QWidget* parent /* = nullptr*/)
	:QTabWidget(parent)
{
	initGui();
}

OperatorTabView::~OperatorTabView()
{


}

void OperatorTabView::initGui()
{

}


//////////////////////////////////////////////////////////////////////////
OperatorView::OperatorView(QWidget* parent /* = nullptr */)
	:QWidget(parent)
{
	initGui();
}

OperatorView::~OperatorView()
{

}

void OperatorView::initGui()
{
	QGroupBox* pGroupBox = new QGroupBox(QString("Operator View : "), this);
	m_pStackedWidget = new QStackedWidget(pGroupBox);
	QHBoxLayout* pH = new QHBoxLayout(this);
	pH->setMargin(4);
	pH->setSpacing(4);
	pH->addWidget(pGroupBox);
	setLayout(pH);
}

QSize OperatorView::sizeHint() const
{
	return QSize(500, 500);
}
