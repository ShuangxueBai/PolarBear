//!<
#ifndef POLAR_BEAR_TEST_INFOS_VIEW_H
#define POLAR_BEAR_TEST_INFOS_VIEW_H

#include <QtGui/QWidget>

class InfosView : public QWidget
{
	Q_OBJECT
public:
	InfosView(QWidget* parent = nullptr);
	~InfosView();

	QSize sizeHint() const;
protected:
	void initGui();
};

#endif