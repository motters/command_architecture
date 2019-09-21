#pragma once

#include <iostream>

#include "Command.h"
#include "Contract.h"

#include "../Validators/Range.h"

namespace Commands
{
    class Radio : Command
    {
        public:

            Radio()
            {

            }

            bool setFrequency(Contract& contract)
            {
                // Validates and returns value
                auto frequency = get<uint32_t>(contract.params, 1);

                // If validation passed
                if( frequency.state &&

                    // Run guards
                    //@todo

                    // Run validators
                    Validators::Range::between<uint32_t>(frequency.value, 800000000,900000000))
                {
                    // This would set a value in storage or at most would run an Event::X::function
                    std::cout << "Setting frequency to: " << frequency.value << std::endl;

                    // Data to send back to interface
                    contract.commandStatus = true;
                    contract.returns.push_back(std::any_cast<uint32_t>(frequency.value));
                }

                // Return result
                return contract.commandStatus;
            }

    };
}