#include "stdafx.h"
#include <QtGui/QHBoxLayout>
#include "graphicView.h"

GraphicView::GraphicView(QWidget* parent /* = nullptr */)
	:QWidget(parent)
{
	initGui();
}

GraphicView::~GraphicView()
{

}

void GraphicView::initGui()
{
	m_pGroupBox = new QGroupBox(QString("Graphics View : "), this);
	QHBoxLayout* pH = new QHBoxLayout(this);
	pH->setMargin(4);
	pH->setSpacing(4);
	pH->addWidget(m_pGroupBox);
	setLayout(pH);
}

QSize GraphicView::sizeHint() const
{
	return QSize(1200, 1000);
}