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
    QRadialGradient gradient(188, 201, 130);
    gradient.setColorAt(0, Qt::white);
    gradient.setColorAt(1, Qt::transparent);
    QBrush brush(gradient);
    painter.setBrush(brush);
    QPolygon polygon;
    polygon << QPoint(124, 180) << QPoint(254, 180) << QPoint(411, 771) << QPoint(-25, 771);
    painter.drawPolygon(polygon);
}
