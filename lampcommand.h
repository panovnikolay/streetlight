#ifndef STREETLIGHTCOMMAND_H
#define STREETLIGHTCOMMAND_H

#include "lamp.h"

class LampCommand
{
public:
    virtual ~LampCommand() {};
    virtual void execute(Lamp * streetLight) = 0;
};

#endif // STREETLIGHTCOMMAND_H
