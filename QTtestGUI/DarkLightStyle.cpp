#include "stdafx.h"
#include "DarkLightStyle.h"


#define DL_WINDOW_COLOR QColor(35,35,35)
#define DL_WINDOW_TEXT_COLOR QColor(35,35,35)
#define DL_BACKGROUND_COLOR QColor(35,35,35)
#define DL_FOREGROUND_COLOR QColor(35,35,35)
#define DL_BASE_COLOR QColor(35,35,35)
#define DL_ALTERNATE_BASE_COLOR QColor(35,35,35)
#define DL_TOOLTIP_BASE_COLOR QColor(35,35,35)
#define DL_TOOLTIP_TEXT_COLOR QColor(35,35,35)
#define DL_TEXT_COLOR QColor(35,35,35)
#define DL_BUTTON_COLOR QColor(35,35,35)
#define DL_BUTTON_TEXT_COLOR QColor(35,35,35)
#define DL_BRIGHT_TEXT_COLOR QColor(35,35,35)

// For 3D bevel and shadow effects.
#define DL_LIGHT_COLOR QColor(35,35,35)
#define DL_MIDLIGHT_COLOR QColor(35,35,35)
#define DL_DARK_COLOR QColor(35,35,35)
#define DL_MID_COLOR QColor(35,35,35)
#define DL_SHADOW_COLOR QColor(35,35,35)

// For selected
#define DL_HIGHT_LIGHT_COLOR QColor(35,35,35)
#define DL_HIGHT_LIGHTED_TEXT_COLOR QColor(35,35,35)

// For hyperlines
#define DL_LINK_COLOR QColor(35,35,35)
#define DL_LINK_VISITED_COLOR QColor(35,35,35)

// For no role
#define DL_NO_ROLE_COLOR QColor(35,35,35)


DarkLightStyle::DarkLightStyle()
	:QProxyStyle()
{

}

DarkLightStyle::~DarkLightStyle()
{


}

void DarkLightStyle::polish(QApplication *app)
{
	Q_ASSERT(Q_NULLPTR != app);

	_appPalette = app->palette();

	QPalette newAppPalette;

	newAppPalette.setColor(QPalette::Window, DL_WINDOW_COLOR);
	newAppPalette.setColor(QPalette::WindowText, DL_WINDOW_TEXT_COLOR);
	newAppPalette.setColor(QPalette::Text, DL_TEXT_COLOR);
	newAppPalette.setColor(QPalette::Background, DL_BACKGROUND_COLOR);
	newAppPalette.setColor(QPalette::Foreground, DL_FOREGROUND_COLOR);
	newAppPalette.setColor(QPalette::Base, DL_BASE_COLOR);
	newAppPalette.setColor(QPalette::AlternateBase, DL_ALTERNATE_BASE_COLOR);
	newAppPalette.setColor(QPalette::ToolTipBase, DL_TOOLTIP_BASE_COLOR);
	newAppPalette.setColor(QPalette::ToolTipText, DL_TOOLTIP_TEXT_COLOR);
	newAppPalette.setColor(QPalette::Button, DL_BUTTON_COLOR);
	newAppPalette.setColor(QPalette::ButtonText, DL_BUTTON_TEXT_COLOR);
	newAppPalette.setColor(QPalette::BrightText, DL_BRIGHT_TEXT_COLOR);

	//For 3D and shadow effects
	newAppPalette.setColor(QPalette::Light, DL_LIGHT_COLOR);
	newAppPalette.setColor(QPalette::Midlight, DL_MIDLIGHT_COLOR);
	newAppPalette.setColor(QPalette::Dark, DL_DARK_COLOR);
	newAppPalette.setColor(QPalette::Mid, DL_MID_COLOR);
	newAppPalette.setColor(QPalette::Shadow, DL_SHADOW_COLOR);

	//For Selected
	newAppPalette.setColor(QPalette::Highlight, DL_HIGHT_LIGHT_COLOR);
	newAppPalette.setColor(QPalette::HighlightedText, DL_HIGHT_LIGHTED_TEXT_COLOR);
	
	//For Link
	newAppPalette.setColor(QPalette::Link, DL_LINK_COLOR);
	newAppPalette.setColor(QPalette::LinkVisited, DL_LINK_VISITED_COLOR);

	//For no role
	newAppPalette.setColor(QPalette::NoRole, DL_NO_ROLE_COLOR);

	return;
}

void DarkLightStyle::polish(QWidget *widget)
{

}

void DarkLightStyle::unpolish(QApplication *app)
{

}

void DarkLightStyle::unpolish(QWidget *widget)
{

}

void DarkLightStyle::drawComplexControl(ComplexControl control, const QStyleOptionComplex *option, QPainter *painter, const QWidget *widget /* = Q_NULLPTR */) const
{

}

void DarkLightStyle::drawControl(ControlElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget /* = Q_NULLPTR */) const
{

}

void DarkLightStyle::drawItemPixmap(QPainter *painter, const QRect &rect, int alignment, const QPixmap &pixmap) const
{

}

void DarkLightStyle::drawItemText(QPainter *painter, const QRect &rect, int flags, const QPalette &pal, bool enabled, const QString &text, QPalette::ColorRole textRole /* = QPalette::NoRole */) const
{

}

void DarkLightStyle::drawPrimitive(PrimitiveElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget /* = Q_NULLPTR */) const
{

}

int DarkLightStyle::pixelMetric(PixelMetric metric, const QStyleOption *option /* = Q_NULLPTR */, const QWidget *widget /* = Q_NULLPTR */) const
{

	return 0;
}

int DarkLightStyle::styleHint(StyleHint hint, const QStyleOption *option /* = Q_NULLPTR */, const QWidget *widget /* = Q_NULLPTR */, QStyleHintReturn *returnData /* = Q_NULLPTR */) const
{
	return 0;
}