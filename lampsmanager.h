#ifndef STREETLIGHTMANAGER_H
#define STREETLIGHTMANAGER_H

#include <QObject>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QLabel>
#include <QDebug>
#include <QPushButton>
#include "lamp.h"
#include "lampcommand.h"
#include "lampcommandparser.h"


class LampsManager : public QObject
{
    Q_OBJECT

public:
    explicit LampsManager(LampCommandParser * parser, QLabel * status,
                                QPushButton * connectButton, QObject * parent = nullptr);
    void addLamp(Lamp * streetLight);
    void executeCommand(LampCommand * command);
    void doConnect(const QString & host, const quint16 port);
    bool getIsConnected();
    void disconnectFromHost();

private:
    void setStatus(const QString & text, const QString & color);
    LampCommand * parseCommand(const QByteArray & rawCommand);
    QVector<Lamp *> lamps;
    LampCommandParser * parser;
    QAbstractSocket * socket;
    QLabel * status;
    QPushButton* connectButton;
    bool isConnected = false;
    QTimer * timer;

private slots:
    void connected();
    void disconnected();
    void readyRead();
    void error(QAbstractSocket::SocketError error);
    void timeout();
};

#endif // STREETLIGHTMANAGER_H
