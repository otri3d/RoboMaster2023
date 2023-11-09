#include "tap/control/command.hpp"
#include "otsrc/controls/chassis/chassissubsystem.hpp"
#include "otsrc/controls/control.hpp"
#include "otsrc/controls/chassis/chassis_tank_drive_command.hpp"

namespace control::chassis{
    void ChassisTankDriveCommand::execute(){
        chassissubsystem.setSpeed(control.getXAxis());
    }
}

