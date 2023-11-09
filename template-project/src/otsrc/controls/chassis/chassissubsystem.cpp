#include "template-project\src\otsrc\controls\control.hpp"
#include "tap/motor/dji_motor.hpp"
#include "chassissubsystem.hpp"
#include "drivers.hpp"

namespace control::chassis{
    chassissubsystem::chassissubsystem(Drivers &drivers, const ChassisConfig &config)
    : tap::control::Subsystem(&drivers),
        motors{
            Motor(&drivers, config.leftFrontMotorId, config.canBus, false, "LF"),
            Motor(&drivers, config.leftBackMotorId, config.canBus, false, "LB"),
            Motor(&drivers, config.rightFrontMotorId, config.canBus, true, "RF"),
            Motor(&drivers, config.rightBackMotorId, config.canBus, true, "RB"),
        }
    {}

    void chassissubsystem::initialize(){
        for(auto &motor : motors){
            motor.initialize();
        }
    }
    void chassissubsystem::setSpeed(float speed){
        for(auto &motor : motors){
            motor.setDesiredOutput(speed);
        }
    }
    
};

    