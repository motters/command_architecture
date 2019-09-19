#pragma once

#include <string>
#include <vector>
#include <any>

namespace Commands
{
    class Contract
    {
        public:
            // Input string can converted into a function and params
            bool status = false;

            // Command from which interface?
            enum class AvailableInterfaces
            {
                Serial,
                LoRa
            };
             AvailableInterfaces interface = AvailableInterfaces::LoRa;

            // Input string's length was verified
            bool validLength = false;

            // Some marker for command to run
            // @todo

            // Holds the params for the command
            std::vector < std::any > params;


    };
}