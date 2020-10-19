#ifndef SWITCHONCOMMAND_H
#define SWITCHONCOMMAND_H

#include "lampcommand.h"


class SwitchOnLampCommand : public LampCommand
{
public:
    void execute(Lamp * handler);
};

#endif // SWITCHONCOMMAND_H
