#pragma once

#include <vector>
#include <string>

#include "Communication.h"

#include "../Commands/Contract.h"
#include "../Commands/CommandList.h"
#include "../Commands/Directory.h"

namespace Communications
{
    class LoRa : Communication<std::string>
    {
        public:

            LoRa()
            {

            }

            enum class Functions: uint8_t
            {
                SetFrequency = 'a',
                SetRelay = 'b'
            };



            /**
             * Handles incomming LoRa data
             *
             * @param input
             * @return
             */
            virtual Commands::Contract handle(std::string input)
            {
                // Command contract
                Commands::Contract contract;

                // Has to have atleast a command byte
                if(input.size() < 1)
                    return contract;

                // Mark interface
                contract.interface = Commands::Contract::AvailableInterfaces::LoRa;

                // Directory for commands
                Commands::Directory directory;

                // Find the correct command
                switch(static_cast<Functions>(input.at(0)))
                {
                    case Functions::SetFrequency:
                        updateContract(contract, Commands::List::SetFrequency, parseIn(input, "%c%4", contract.params));
                        // Execute command in contract
                        directory.call(contract);
                        parseOut(contract, "u%4");
                        break;
                    case Functions::SetRelay:
                        updateContract(contract, Commands::List::SetRelay, parseIn(input, "%c%1", contract.params));
                        //parseOut(contract, "%c%4");
                        break;
                }

                return contract;
            };


        private:
    };
}