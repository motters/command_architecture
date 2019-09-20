#pragma once

#include <iostream>

#include "Command.h"
#include "Contract.h"

namespace Commands
{
    class Calibration : Command
    {
        public:
            Calibration()
            {

            }



            bool start(Contract contract)
            {
                std::cout << "Start calibration" << std::endl;
                return true;
            }

            bool lLineCurrentOffset(Contract contract)
            {
                std::cout << "L line current offset: " << std::any_cast<float>(contract.params[1]) << std::endl;
                return true;
            }

    };
}