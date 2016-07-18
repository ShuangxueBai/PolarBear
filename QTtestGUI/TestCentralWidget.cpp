#include "stdafx.h"
#include <QtGui/QSplitter>
#include "TestCentralWidget.h"
#include "graphicView.h"
#include "operatorView.h"
#include "InfosView.h"

TestCentralWidget::TestCentralWidget(QWidget* parent /* = nullptr */)
	:QWidget(parent)
{
	initGui();
}

TestCentralWidget::~TestCentralWidget()
{

}

void TestCentralWidget::initGui()
{
	m_pGraphicView = new GraphicView(this);
	m_pOperatorView = new OperatorView(this);
	m_pInfosView = new InfosView(this);

	m_pHorSplitter = new QSplitter(Qt::Horizontal, this);
	m_pVerSplitter = new QSplitter(Qt::Vertical, this);

	m_pHorSplitter->setHandleWidth(6);
	m_pVerSplitter->setHandleWidth(6);

	m_pHorSplitter->addWidget(m_pVerSplitter);
	m_pHorSplitter->addWidget(m_pGraphicView);
	m_pVerSplitter->addWidget(m_pOperatorView);
	m_pVerSplitter->addWidget(m_pInfosView);
}

void TestCentralWidget::resizeEvent(QResizeEvent *e)
{
	m_pHorSplitter->setGeometry(this->geometry());
	return QWidget::resizeEvent(e);
}
