#include "changecolorlampcommand.h"
#include <QThread>


ChangeColorLampCommand::ChangeColorLampCommand(QColor color) : color(color)
{

}

void ChangeColorLampCommand::execute(Lamp * lamp)
{
    lamp->changeColor(color);
}
