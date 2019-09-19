#pragma once

#include <vector>

#include "Interface.h"

namespace Interfaces
{
    class Serial : Interface<std::string>
    {
        public:

            Serial()
            {

            }

            /**
             * Handles incomming serial data
             *
             * @param input
             * @return
             */
            virtual Commands::Contract handle(std::string input)
            {
                Commands::Contract status;
                return status;
            };
    };
}