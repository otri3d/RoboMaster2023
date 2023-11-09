#include "tap/control/command.hpp"
#include "otsrc/controls/chassis/chassissubsystem.hpp"
#include "otsrc/controls/control.hpp"

namespace control::chassis {
    class ChassisTankDriveCommand : public tap::control::Command {
    public:
        ChassisTankDriveCommand(chassissubsystem& chassis, control& ctrl);
        void initialize();
        void execute();
        void end();
        bool isFinished();

    private:
        chassissubsystem& chassissubsystem;
        control& control;
    };
}