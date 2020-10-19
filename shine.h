#ifndef SHINE_H
#define SHINE_H

#include <QWidget>


class Shine : public QWidget
{
    Q_OBJECT

public:
    explicit Shine(QWidget * parent = nullptr);
    void paintEvent(QPaintEvent * event);
};

#endif // SHINE_H
