#ifndef STREETLIGHT_H
#define STREETLIGHT_H

#include <QWidget>
#include <QPaintEvent>
#include <QResizeEvent>
#include "shine.h"


class Lamp : public QWidget
{
    Q_OBJECT

public:
    explicit Lamp(QWidget * parent = nullptr);
    ~Lamp();
    void paintEvent(QPaintEvent *event);
    void changeColor(const QColor & color);
    void switchOn();
    void switchOff();
    Shine & getShine();

private:
    void draw(const QColor & color);
    bool isEnabled = false;
    QPixmap * lampPixmap;
    QPainter * lampPainter;
    const QColor offColor = QColor(150, 150, 150);
    const QColor onColor = QColor(255, 255, 0);
    const QRect rectangle = QRect(165, 147, 50, 65);
    const int startAngle = 0;
    const int spanAngle = -180 * 16;
    Shine shine;
};

#endif // STREETLIGHT_H
