#pragma once

#include <vector>

#include "Interface.h"

namespace Interfaces
{
    class Serial : Interface<std::vector<char>>
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
            virtual bool handle(std::vector<char> input)
            {
                return true;
            };
    };
}