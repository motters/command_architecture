#pragma once

#include <iostream>

#include "Command.h"

namespace Commands
{
    class CreditControl : Command
    {
        public:
            CreditControl()
            {

            }


            bool enable()
            {
                std::cout << "Credit control enabled";
                return true;
            }

            bool addCredit(uint32_t amount)
            {
                std::cout << "Adding credit: " << amount << std::endl;
                return true;
            }

    };
}