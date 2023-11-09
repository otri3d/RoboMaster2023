#include "tap/drivers.hpp"

namespace control{
    class control{
        public:
            float getXAxis();
            float getYAxis();
        private:
            tap::Drivers *driver;
    };
}