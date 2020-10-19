#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPaintEvent>
#include "lamp.h"
#include "lampsmanager.h"
#include "lampcommandparser.h"
#include "tlvlampcommandparser.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_connectButton_clicked();

private:
    Ui::MainWindow *ui;
    Lamp * lamp;
    TlvLampCommandParser * lampCommandParser;
    LampsManager * lampManager;

};
#endif // MAINWINDOW_H
