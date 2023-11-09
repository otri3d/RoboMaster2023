#include "control.hpp"
#include "tap/communication/serial/remote.hpp"
#include "tap/algorithms/math_user_utils.hpp"

using tap::communication::serial::Remote;
using tap::algorithms::limitVal;
namespace control{
    float control::getXAxis(){
        float currentXAxis = driver -> remote.getChannel(Remote::Channel::LEFT_HORIZONTAL);
        return limitVal(currentXAxis, -1.0f, 1.0f);
    }
    float control::getYAxis(){
        float currentYAxis = driver -> remote.getChannel(Remote::Channel::LEFT_VERTICAL);
        return limitVal(currentYAxis, -1.0f, 1.0f);
    }
}