#ifndef TLVCOMMANDPARSER_H
#define TLVCOMMANDPARSER_H

#include "lampcommandparser.h"


class TlvLampCommandParser : public LampCommandParser
{
public:
    LampCommand * parse(const QByteArray & rawCommand);
};

#endif // TLVCOMMANDPARSER_H
