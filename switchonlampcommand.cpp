#include "switchonlampcommand.h"

void SwitchOnLampCommand::execute(Lamp * lamp)
{
    lamp->switchOn();
}
