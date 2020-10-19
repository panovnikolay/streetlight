#ifndef COMMANDPARSER_H
#define COMMANDPARSER_H

#include "lampcommand.h"


class LampCommandParser
{
public:
    virtual ~LampCommandParser() {};
    virtual LampCommand * parse(const QByteArray & rawCommand) = 0;
};

#endif // COMMANDPARSER_H
