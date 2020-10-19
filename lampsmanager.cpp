#include "lampsmanager.h"
#include "switchofflampcommand.h"
#include <QTimer>

LampsManager::LampsManager(LampCommandParser * parser, QLabel* status,
                           QPushButton * connectButton, QObject *parent)
    : QObject(parent), parser(parser), status(status), connectButton(connectButton)
{

}

void LampsManager::addLamp(Lamp * lamp)
{
    if (lamp != nullptr) {
        lamps.push_back(lamp);
        lamp->show();
    }
}

void LampsManager::executeCommand(LampCommand * command)
{
    if (command != nullptr) {
        for (Lamp * lamp : lamps)
            command->execute(lamp);
    }
}

LampCommand * LampsManager::parseCommand(const QByteArray & rawCommand)
{
    return parser->parse(rawCommand);
}

void LampsManager::doConnect(const QString & host, const quint16 port)
{
    connectButton->setEnabled(false);

    socket = new QTcpSocket(this);
    timer = new QTimer(this);

    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(error(QAbstractSocket::SocketError)));
    connect(timer, SIGNAL(timeout()), this, SLOT(timeout()));

    setStatus("Connecting...", "yellow");
    socket->connectToHost(host, port);
    timer->start(3000);
}

void LampsManager::connected()
{
    timer->stop();
    connectButton->setEnabled(true);
    isConnected = true;
    setStatus("Connected", "green");
    connectButton->setText("Disconnect");
}

void LampsManager::disconnected()
{
    connectButton->setEnabled(true);
    isConnected = false;
    setStatus("Not connected", "red");
    SwitchOffLampCommand command;
    executeCommand(&command);
    connectButton->setText("Connect");
    timer->stop();
}

void LampsManager::readyRead()
{
    LampCommand * command = parseCommand(socket->readAll());
    executeCommand(command);
    delete command;
}

void LampsManager::error(QAbstractSocket::SocketError)
{
    timer->stop();
    setStatus(socket->errorString(), "red");
    connectButton->setEnabled(true);
}

void LampsManager::timeout()
{
    timer->stop();
    setStatus("Timeout", "red");
    connectButton->setEnabled(true);
}

bool LampsManager::getIsConnected()
{
    return isConnected;
}

void LampsManager::disconnectFromHost()
{
    socket->disconnectFromHost();
}

void LampsManager::setStatus(const QString & text, const QString & color)
{
    status->setText(text);
    status->setStyleSheet("QLabel { color : " + color + "; }");
}
