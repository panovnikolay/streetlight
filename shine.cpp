#include "shine.h"
#include <QPainter>


Shine::Shine(QWidget *parent) : QWidget(parent)
{

}

void Shine::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setPen(Qt::NoPen);
    QRadialGradient gradient(227, 230, 130);
    gradient.setColorAt(0, Qt::white);
    gradient.setColorAt(1, Qt::transparent);
    QBrush brush(gradient);
    painter.setBrush(brush);
    QPolygon polygon;
    polygon << QPoint(163, 209) << QPoint(293, 209) << QPoint(450, 800) << QPoint(4, 800);
    painter.drawPolygon(polygon);
}
