#pragma once

#include <vector>
#include <string>

#include "Communication.h"

#include "../Commands/Contract.h"
#include "../Commands/CommandList.h"

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

                // Find the correct command
                switch(static_cast<Functions>(input.at(0)))
                {
                    case Functions::SetFrequency:
                        updateContract(contract, Commands::List::SetFrequency, parse(input, "%c%4", contract.params));
                        processResponse(contract, "%c%4");
                        break;
                    case Functions::SetRelay:
                        updateContract(contract, Commands::List::SetRelay, parse(input, "%c%1", contract.params));
                        processResponse(contract, "%c%4");
                        break;
                }

                return contract;
            };


        private:
    };
}