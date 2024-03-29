#pragma once

#include <vector>

#include "Communication.h"

#include "../Commands/Contract.h"
#include "../Commands/CommandList.h"

#include "../Validators/Contains.h"

namespace Communications
{
    class Serial : Communication<std::string>
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
                // Method contract
                Commands::Contract contract;

                // Has to have atleast a command byte
                if(input.size() < 1)
                    return contract;

                // Mark interface
                contract.interface = Commands::Contract::AvailableInterfaces::Serial;

                // Directory for commands
                Commands::Directory directory;

                // Find the correct command
                if(Validators::Contains::startsWith(input, "FREQ="))
                {
                    processCommand(contract, Commands::List::SetFrequency, input, "%s=%o,%m", "FREQ=%q%m,%o");
                }


                return contract;
            };
    };
}