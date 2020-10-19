#include "switchofflampcommand.h"

void SwitchOffLampCommand::execute(Lamp * lamp)
{
    lamp->switchOff();
}

