#pragma once

#include <vector>

#include "Interface.h"

namespace Interfaces
{
    class LoRa : Interface<std::vector<uint8_t>>
    {
        public:

            LoRa()
            {

            }

            /**
             * Handles incomming LoRa data
             *
             * @param input
             * @return
             */
            virtual bool handle(std::vector<uint8_t > input)
            {
                return true;
            };
    };
}