//! Polar Bear
#ifndef POLAR_BEAR_DARK_LIGHT_STYLE_H
#define POLAR_BEAR_DARK_LIGHT_STYLE_H

#include <QtWidgets/QProxyStyle>

class DarkLightStyle : public QProxyStyle
{

public:
	DarkLightStyle();
	~DarkLightStyle();


	virtual void polish(QApplication *app);
	virtual void polish(QWidget *widget);
	virtual void unpolish(QWidget *widget);
	virtual void unpolish(QApplication *app);
	virtual void drawComplexControl(ComplexControl control, const QStyleOptionComplex *option, QPainter *painter, const QWidget *widget = Q_NULLPTR) const;
	virtual void drawControl(ControlElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget = Q_NULLPTR) const;
	virtual void drawItemPixmap(QPainter *painter, const QRect &rect, int alignment, const QPixmap &pixmap) const;
	virtual void drawItemText(QPainter *painter, const QRect &rect, int flags, const QPalette &pal, bool enabled, const QString &text, QPalette::ColorRole textRole = QPalette::NoRole) const;
	virtual void drawPrimitive(PrimitiveElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget = Q_NULLPTR) const;
	virtual int  pixelMetric(PixelMetric metric, const QStyleOption *option = Q_NULLPTR, const QWidget *widget = Q_NULLPTR) const;
	virtual int  styleHint(StyleHint hint, const QStyleOption *option = Q_NULLPTR, const QWidget *widget = Q_NULLPTR, QStyleHintReturn *returnData = Q_NULLPTR) const;

private:
	QPalette _appPalette;
};

#endif


