#include "lamp.h"
#include <QPainter>


Lamp::Lamp(QWidget *parent) : QWidget(parent)
{
    lampPixmap = new QPixmap(width(), height());
    lampPixmap->fill(QColor(255, 255, 255, 0));
    lampPainter = new QPainter(lampPixmap);
    draw(offColor);
    shine.hide();
}

Lamp::~Lamp()
{
    delete lampPainter;
    delete lampPixmap;
}

void Lamp::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.drawPixmap(0, 0, *lampPixmap);
}

void Lamp::draw(const QColor & color)
{
    lampPainter->setPen(Qt::NoPen);
    lampPainter->setBrush(color);
    lampPainter->drawPie(rectangle, startAngle, spanAngle);
    update();
}

void Lamp::changeColor(const QColor & color)
{
    if (isEnabled)
        draw(color);
}

void Lamp::switchOn()
{
    isEnabled = true;
    draw(onColor);
    shine.show();
}

void Lamp::switchOff()
{
    isEnabled = false;
    draw(offColor);
    shine.hide();
}

Shine & Lamp::getShine(){
    return shine;
}
