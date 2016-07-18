#include "stdafx.h"
#include <QtGui/QHBoxLayout>
#include "InfosView.h"


InfosView::InfosView(QWidget* parent /* = nullptr */)
	:QWidget(nullptr)
{
	initGui();
}

InfosView::~InfosView()
{

}

void InfosView::initGui()
{
	QGroupBox* pGroupBox = new QGroupBox(QString("Infos View : "), this);
	QHBoxLayout* pH = new QHBoxLayout(this);
	pH->setMargin(4);
	pH->setSpacing(4);
	pH->addWidget(pGroupBox);
	setLayout(pH);
}

QSize InfosView::sizeHint() const
{
	return QSize(500, 500);
}