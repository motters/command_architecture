#pragma once

#include <iostream>

#include "Command.h"

namespace Commands
{
    class Calibration : Command
    {
        public:
            Calibration()
            {

            }

            bool start()
            {
                std::cout << "Start calibration" << std::endl;
                return true;
            }

            bool lLineCurrentOffset(float error)
            {
                std::cout << "L line current offset: " << error << std::endl;
                return true;
            }

    };
}