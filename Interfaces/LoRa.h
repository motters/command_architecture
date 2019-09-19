#pragma once

#include <vector>
#include <map>
#include <string>
#include <any>

#include "Interface.h"

#include "../Commands/Calibration.h"
#include "../Commands/Contract.h"

namespace Interfaces
{
    class LoRa : Interface<std::string>
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

                std::vector < std::any > result;

                // Find the correct command
                switch(static_cast<Functions>(input.at(0)))
                {
                    case Functions::SetFrequency:
                        updateContract(contract, parse(input, "%c%4", contract.params));
                        break;
                    case Functions::SetRelay:
                        updateContract(contract, parse(input, "%c%1", contract.params));
                        break;
                }

                return contract;

            };


        private:
    };
}