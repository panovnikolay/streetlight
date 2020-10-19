#include <QtEndian>
#include "tlvlampcommandparser.h"
#include "lampcommand.h"
#include "switchonlampcommand.h"
#include "switchofflampcommand.h"
#include "changecolorlampcommand.h"


enum {
    SwitchOn = 0x12,
    SwitchOff = 0x13,
    ChangeColor = 0x20
};

LampCommand * TlvLampCommandParser::parse(const QByteArray & rawCommand)
{
    QVector<quint8> commandBytes(rawCommand.size(), 0);
    qFromBigEndian<quint8>(rawCommand.data(), rawCommand.size(), commandBytes.data());

    switch (commandBytes[0]) {
    case SwitchOn:
        return new SwitchOnLampCommand();
    case SwitchOff:
        return new SwitchOffLampCommand();
    case ChangeColor:
        return new ChangeColorLampCommand(QColor(commandBytes[3], commandBytes[4], commandBytes[5]));
    default:
        return nullptr;
    }
}

