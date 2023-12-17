#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <drivers.hpp>
#include <control/chassis/chassissubsystem.hpp>


Drivers driver;

namespace control::chassis{
    class MockChassisSubsystem: public chassissubsystem
    {
        MockChassisSubsystem(Drivers &drivers): chassissubsystem(drivers, {}){}

        MOCK_METHOD(void, setspeed, (float, float));
    };
}

