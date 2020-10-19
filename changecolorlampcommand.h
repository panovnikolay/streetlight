#ifndef CHANGECOLORCOMMAND_H
#define CHANGECOLORCOMMAND_H

#include "lampcommand.h"


class ChangeColorLampCommand : public LampCommand
{
public:
    ChangeColorLampCommand(QColor color);
    void execute(Lamp * lamp);

private:
    QColor color;
};

#endif // CHANGECOLORCOMMAND_H
