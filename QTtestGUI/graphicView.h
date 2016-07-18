#ifndef GRAPHIC_VIEW_H
#define GRAPHIC_VIEW_H

#include <QtGui/QWidget>

class GraphicView : public QWidget
{
	Q_OBJECT
public:
	GraphicView(QWidget* parent = nullptr);
	~GraphicView();

	QSize sizeHint() const;
protected:
	void initGui();
private:
	QGroupBox* m_pGroupBox;
};


#endif