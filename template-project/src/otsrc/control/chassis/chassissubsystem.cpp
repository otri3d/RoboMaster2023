#include "template-project\src\otsrc\control\control.hpp"
#include "tap/motor/dji_motor.hpp"
#include "chassissubsystem.hpp"
#include "drivers.hpp"


namespace control::chassis{
    chassissubsystem::chassissubsystem(Drivers &drivers, const ChassisConfig &config): 
        tap::control::Subsystem(&drivers),
        motors{
            Motor(&drivers, config.leftFrontMotorId, config.canBus, false, "LF"),
            Motor(&drivers, config.rightFrontMotorId, config.canBus, false, "RF"),
            Motor(&drivers, config.leftBackMotorId, config.canBus, false, "LB"),
            Motor(&drivers, config.rightBackMotorId, config.canBus, false, "RB")
        }
    {}

    void chassissubsystem::initialize(){
        for (auto &motor : motors){
            motor.initialize();
        }
    }

    void chassissubsystem::setspeed(float left, float right){
        motors[0].setDesiredOutput(left);
        motors[1].setDesiredOutput(right);
        motors[2].setDesiredOutput(left);
        motors[3].setDesiredOutput(right);
    }
}

    