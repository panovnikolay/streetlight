#ifndef SWITCHOFFCOMMAND_H
#define SWITCHOFFCOMMAND_H

#include "lampcommand.h"


class SwitchOffLampCommand : public LampCommand
{
public:
    void execute(Lamp * handler);
};

#endif // SWITCHOFFCOMMAND_H
