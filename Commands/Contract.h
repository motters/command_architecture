#pragma once

#include <string>
#include <vector>
#include <any>

#include "CommandList.h"

namespace Commands
{
    struct Contract
    {
        public:
            // Input string can converted into a function and params
            bool status = false;

            // Input string's length was verified
            bool validLength = false;

            // Command from which interface?
            enum class AvailableInterfaces
            {
                Serial,
                LoRa,
                Internal
            };
            AvailableInterfaces interface = AvailableInterfaces::Internal;

            // Some marker for command to run
            List command;

            // Holds the params for the command
            std::vector < std::any > params;

            // Holds the return responces
            bool commandStatus = false;
            std::vector < std::any > returns;

            // Holds the communication generated out
            std::string communicationsOutput = "";

            // Check is contract was execute correctly
            bool validExecution()
            {
                if(status && validLength && commandStatus)
                    return true;
                return false;
            }
    };
}