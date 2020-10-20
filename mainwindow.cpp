#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QtSvg/QSvgWidget>
#include <QPainter>
#include <QLayout>


MainWindow::MainWindow(QWidget * parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , lamp(new Lamp)
    , lampCommandParser(new TlvLampCommandParser)
{
    ui->setupUi(this);
    lampManager = new LampsManager(lampCommandParser, ui->statusLabel,
                                             ui->connectButton, this);
    lampManager->addLamp(lamp);

    setWindowTitle("Street light");
    QPixmap image{":/res/img/park.svg"};
    ui->image->setPixmap(image.scaled(ui->image->width(), ui->image->height(), Qt::KeepAspectRatio));

    QGridLayout * layout = new QGridLayout(ui->image);
    layout->addWidget(&lamp->getShine(), 0, 0);
    layout->addWidget(lamp, 0, 0);
}

MainWindow::~MainWindow()
{
    delete lampCommandParser;
    delete lamp;
    delete ui;
}

void MainWindow::on_connectButton_clicked()
{
    if (lampManager->getIsConnected()) {
        lampManager->disconnectFromHost();
    } else {
        QString host = ui->hostLineEdit->text();
        quint16 port = ui->portLineEdit->text().toInt();
        lampManager->doConnect(host, port);
    }
}
