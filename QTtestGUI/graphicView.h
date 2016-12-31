#ifndef GRAPHIC_VIEW_H
#define GRAPHIC_VIEW_H

#include <QtWidgets/QWidget>
#include <QtWidgets/QGroupBox>

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