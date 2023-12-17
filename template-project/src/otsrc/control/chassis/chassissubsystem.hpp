#include "template-project\src\otsrc\control\control.hpp"
#include "tap/motor/dji_motor.hpp"
#include "tap/control/subsystem.hpp"
#include <array>

class Drivers;

using Motor = tap::motor::DjiMotor;
namespace control::chassis{

    struct ChassisConfig{
        tap::motor::MotorId leftFrontMotorId;
        tap::motor::MotorId rightFrontMotorId;
        tap::motor::MotorId leftBackMotorId;
        tap::motor::MotorId rightBackMotorId;
        tap::can::CanBus canBus;
    };

    class chassissubsystem : public tap::control::Subsystem{
        const static int numMotors = 4;
        public:
            chassissubsystem(Drivers &drivers, const ChassisConfig &config);
        private:
            tap::Drivers *driver;
            std::array<Motor, numMotors> motors;

            void initialize();
            void setspeed(float left, float right);
    };
}