#pragma once

#include <iostream>

#include "Command.h"

namespace Commands
{
    class Relay : Command
    {
        public:
            Relay()
            {

            }

            bool on()
            {
                std::cout << "Turning relay on" << std::endl;;
            }

            bool off()
            {
                std::cout << "Turning relay off" << std::endl;;
            }

    };
}